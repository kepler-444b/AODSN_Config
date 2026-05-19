#include "model_panel_3key.h"
#include "ui_model_panel_3key.h"

ModelPanel3Key::ModelPanel3Key(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelPanel3Key)
{
    ui->setupUi(this);
    m_buttons.clear();
    m_buttons.append(ui->key_1);
    m_buttons.append(ui->key_2);
    m_buttons.append(ui->key_3);
    for (auto btn : m_buttons)
    {
        btn->setCheckable(true);
        btn->installEventFilter(this);
    }
}

ModelPanel3Key::~ModelPanel3Key()
{
    delete ui;
}

void ModelPanel3Key::SetKeyNames(const QStringList &names)
{
    int count = qMin(names.size(), m_buttons.size());
    for (int i = 0; i < count; ++i)
    {
        if (!names[i].isEmpty())
            m_buttons[i]->setText(names[i]);
    }
}

void ModelPanel3Key::SetPanelAddr(const uint8_t addr)
{
    ui->addr->setText(QString("地址:%1").arg(addr));
    m_addr = addr;
}

bool ModelPanel3Key::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() != QEvent::MouseButtonPress)
        return QWidget::eventFilter(obj, event);

    auto btn = qobject_cast<QPushButton*>(obj);
    if (!btn || !m_buttons.contains(btn))
        return QWidget::eventFilter(obj, event);

    auto e = static_cast<QMouseEvent*>(event);
    if (e->button() != Qt::RightButton)
        return QWidget::eventFilter(obj, event);

    int keyIndex = 0;
    QString objName = btn->objectName();
    if (objName.startsWith("key_"))
    {
        bool ok;
        int num = objName.mid(4).toInt(&ok);
        if (ok && num >= 1 && num <= 6)
            keyIndex = num - 1;
    }
    // 3键到6键映射关系

    QList<int> hwIndices;
    switch (keyIndex) {
    case 0: hwIndices << 0 << 1; break; // 键1 -> 0, 1
    case 1: hwIndices << 4 << 5; break; // 键2 -> 4, 5
    case 2: hwIndices << 2 << 3; break; // 键3 -> 2, 3
    default: hwIndices << keyIndex;      // 其他 -> 保持原样
    }
    QMenu menu(this);
    QAction *deleteAction = menu.addAction("删除");
    QAction *renameAction = menu.addAction("修改别名");

    auto addSceneActions = [this](QMenu* parentMenu) {
        for (const auto &scene : m_sceneList)
        {
            QString text = QString("%1: %2").arg(scene.scene_id).arg(scene.scene_name);
            QAction *action = parentMenu->addAction(text);
            action->setData(QVariant::fromValue(scene.scene_id));
        }
    };

    QMenu *bindOpenMenu = menu.addMenu("绑定开场景");
    addSceneActions(bindOpenMenu);

    QMenu *bindCloseMenu = menu.addMenu("绑定关场景");
    addSceneActions(bindCloseMenu);

    // 弹出菜单并处理选择
    QAction *selected = menu.exec(e->globalPos());
    if (selected == renameAction)
    {
        bool ok;
        QString text = QInputDialog::getText(this, "修改按键名称", "请输入新的名称：", QLineEdit::Normal, btn->text(), &ok);
        if (ok && !text.isEmpty())
        {
            btn->setText(text);
            emit keyNameChanged(m_addr, keyIndex, text);
        }
    }
    else if (selected == deleteAction)
    {
        emit requestDelete(m_addr);
    }
    // 绑定开场景
    else if (selected && selected->parentWidget() == bindOpenMenu)
    {
        uint8_t scene_id   = selected->data().toUInt();

        for (int idx : hwIndices) {
            emit requestBindScene(m_addr, idx, scene_id, true);
        }
    }

    // 绑定关场景
    else if (selected && selected->parentWidget() == bindCloseMenu)
    {
        uint8_t sceneId = selected->data().toUInt();
        for (int idx : hwIndices) {
            emit requestBindScene(m_addr, idx, sceneId, false);
        }
    }

    return true; // 拦截事件
}

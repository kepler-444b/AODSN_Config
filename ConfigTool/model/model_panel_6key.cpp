#include "model_panel_6key.h"
#include "ui_model_panel_6key.h"

ModelPanel6Key::ModelPanel6Key(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelPanel6Key)
{
    ui->setupUi(this);
    m_buttons.clear();
    m_buttons.append(ui->key_1);
    m_buttons.append(ui->key_2);
    m_buttons.append(ui->key_3);
    m_buttons.append(ui->key_4);
    m_buttons.append(ui->key_5);
    m_buttons.append(ui->key_6);
    for (auto btn : m_buttons)
    {
        btn->setCheckable(true);
        btn->installEventFilter(this);
    }

}

ModelPanel6Key::~ModelPanel6Key()
{
    delete ui;
}

void ModelPanel6Key::SetKeyNames(const QStringList &names)
{
    int count = qMin(names.size(), m_buttons.size());
    for (int i = 0; i < count; ++i)
    {
        if (!names[i].isEmpty())
            m_buttons[i]->setText(names[i]);
    }
}

void ModelPanel6Key::SetPanelAddr(const uint8_t addr)
{
    ui->addr->setText(QString("地址:%1").arg(addr));
    m_addr = addr;
}

bool ModelPanel6Key::eventFilter(QObject *obj, QEvent *event)
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

        emit requestBindScene(m_addr, keyIndex, scene_id, true);
    }

    // 绑定关场景
    else if (selected && selected->parentWidget() == bindCloseMenu)
    {
        uint8_t sceneId = selected->data().toUInt();
        emit requestBindScene(m_addr, keyIndex, sceneId, false);
    }

    return true; // 拦截事件
}

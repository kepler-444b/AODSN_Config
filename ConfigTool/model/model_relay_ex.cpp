#include "model_relay_ex.h"
#include "ui_model_relay_ex.h"

ModelRelayEx::ModelRelayEx(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelRelayEx)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

ModelRelayEx::~ModelRelayEx()
{
    delete ui;
}

void ModelRelayEx::SetExtendAddr(const uint8_t addr, const ExtendType type)
{
    ui->addr->setText(QString("地址:%1").arg(addr));
    m_addr = addr;
    m_type = type;
}

bool ModelRelayEx::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QWidget* w = qobject_cast<QWidget*>(obj);
        if (w == this)  // 如果点击的是这个 widget 本身
        {
            QMouseEvent *e = static_cast<QMouseEvent*>(event);
            if (e->button() == Qt::RightButton)
            {
                QMenu menu(this);   // 创建右键菜单
                QAction *deleteAction = menu.addAction("删除");

                QAction *selected = menu.exec(e->globalPos()); // 弹出菜单
                if (selected == deleteAction)
                {
//                    emit requestDelete(m_addr, m_type);  // 发出删除信号
                }
                return true;  // 拦截事件
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}




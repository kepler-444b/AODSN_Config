#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化各个模块
    m_protocol      = new AppProtocolSetAddr(this);
    SerialWidget    = new AppSerial(ui->centralwidget); // 创建串口实例

    SetAddrWidget   = new AppSetAddr(ui->stackedWidget->widget(0));                 // 创建设置地址页面
    SetConfigWidget = new AppSetConfig(ui->stackedWidget->widget(1), SerialWidget); // 创建设备配置页面
    SetNetWidget    = new AppSetNet(ui->stackedWidget->widget(2), SerialWidget);    // 创建设置页面

    ui->stackedWidget->widget(1)->setLayout(new QGridLayout);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0, 0, 0, 0);
    ui->stackedWidget->widget(1)->layout()->addWidget(SetConfigWidget);


    on_listWidget_currentItemChanged(ui->listWidget->currentItem(), nullptr); // 默认显示 widget(0)
    ui->stackedWidget->setCurrentIndex(0);                                    // 切换到 widget(0)
    ui->listWidget->setCurrentRow(0);                                         // 右侧的 listWidget 切换到 0行
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 关闭主窗口
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (DisplayWidget) {
        DisplayWidget->close();
        DisplayWidget = nullptr;
    }
    QMainWindow::closeEvent(event); // 调用基类处理
}

// 弹出调试窗口
void MainWindow::on_debug_triggered()
{
    if (!DisplayWidget)
    {
        DisplayWidget = new AppDisplay(nullptr);
        DisplayWidget->setWindowFlags(Qt::Window);

        connect(DisplayWidget, &AppDisplay::sigDisplaySendData, SerialWidget, &AppSerial::SerialSendData);  // 显示窗口点击发送 → 串口发送数据
        connect(SerialWidget, &AppSerial::sigRecvData, DisplayWidget, &AppDisplay::DisplayRecv);            // 串口收到数据 → 显示窗口显示 RX
        connect(SerialWidget, &AppSerial::sigSendData, DisplayWidget, &AppDisplay::DisplaySend);            // 串口发送数据 → 显示窗口显示 TX
    }

    DisplayWidget->show();
    DisplayWidget->raise();
    DisplayWidget->activateWindow();
}

// 功能切换
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        return;
    qDebug() << "当前页面" << current->text();

    // 离开页面
    if (previous && previous->text() == "设置地址") {
        disconnect(SetAddrWidget, &AppSetAddr::sigAddrChanged, m_protocol, &AppProtocolSetAddr::AddrUpdate);
        disconnect(SetAddrWidget, &AppSetAddr::sigAddrSendAll, m_protocol, &AppProtocolSetAddr::AddrSendAll);
        disconnect(m_protocol, &AppProtocolSetAddr::sigSendData, SerialWidget, &AppSerial::SerialSendData);
        disconnect(SerialWidget, &AppSerial::sigRecvData, m_protocol, &AppProtocolSetAddr::RecvDataParse);
    }
    if (previous && previous->text() == "设置配置")
    {

    }

    // 进入新页面时建立连接
    if (current->text() == "设置地址") {
        connect(SetAddrWidget, &AppSetAddr::sigAddrChanged, m_protocol, &AppProtocolSetAddr::AddrUpdate, Qt::UniqueConnection);
        connect(SetAddrWidget, &AppSetAddr::sigAddrSendAll, m_protocol, &AppProtocolSetAddr::AddrSendAll, Qt::UniqueConnection);
        connect(m_protocol, &AppProtocolSetAddr::sigSendData, SerialWidget, &AppSerial::SerialSendData, Qt::UniqueConnection);
        connect(SerialWidget, &AppSerial::sigRecvData, m_protocol, &AppProtocolSetAddr::RecvDataParse, Qt::UniqueConnection);
    }
    if (current->text() == "设置配置") {
//        connect(SetConfigWidget, &AppSetConfig::sigSendDataToSerial, SerialWidget, &AppSerial::SerialSendData);
    }



    // 切换到新页面
    int row = ui->listWidget->row(current);
    ui->stackedWidget->setCurrentIndex(row);
}

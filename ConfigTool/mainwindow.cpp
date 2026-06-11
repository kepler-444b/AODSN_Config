#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化各个模块
//    m_protocol      = new AppProtocolSetAddr(this);
    SerialWidget    = new AppSerial(ui->centralwidget); // 创建串口实例

    SetAddrWidget   = new AppSetAddr(ui->stackedWidget->widget(0), SerialWidget);   // 创建设置地址页面
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
    if (SetConfigWidget && SetConfigWidget->ConfigIsChanged())
    {
        QMessageBox msgBox(QMessageBox::Warning, "未保存配置", "检测到配置已修改,是否仍然退出?", QMessageBox::Ok | QMessageBox::Cancel, this);

        msgBox.button(QMessageBox::Ok)->setText("确定");
        msgBox.button(QMessageBox::Cancel)->setText("取消");

        msgBox.setDefaultButton(QMessageBox::Cancel); // 设置默认聚焦在“取消”上,防止用户习惯性敲回车误关闭

        int ret = msgBox.exec();

        // 只有明确点击了 Ok 才会放行,其他任何操作(点 Cancel 点叉号)都拦截
        if (ret != QMessageBox::Ok)
        {
            event->ignore();   // 拦截关闭
            return;
        }
    }

    if (DisplayWidget) // 关闭调试窗口
    {
        DisplayWidget->close();
        DisplayWidget = nullptr;
    }

    if (SetConfigWidget) // 关闭场景列表
    {
        SetConfigWidget->CloseListWidget();
    }
    event->accept();
}

// 弹出调试窗口
void MainWindow::on_debug_triggered()
{
    if (!DisplayWidget)
    {
        DisplayWidget = new AppDisplay(nullptr);
        DisplayWidget->setWindowFlags(Qt::Window);

        connect(DisplayWidget, &AppDisplay::sigDisplaySendData, SerialWidget, &AppSerial::SerialSendData);  // 显示窗口点击发送 → 串口发送数据
        connect(SerialWidget, &AppSerial::sigRecvRawData, DisplayWidget, &AppDisplay::DisplayRecv);            // 串口收到数据 → 显示窗口显示 RX
        connect(SerialWidget, &AppSerial::sigSendData, DisplayWidget, &AppDisplay::DisplaySend);            // 串口发送数据 → 显示窗口显示 TX
    }

    DisplayWidget->show();
    DisplayWidget->raise();
    DisplayWidget->activateWindow();
}

// 软件版本
void MainWindow::on_ver_triggered()
{
    QString currentVersion = "v0.2";
    QString downloadUrl = "https://gitee.com/jokershudongsheng/ADSON_Release/releases";

    QString infoText = QString(
                "<h3>奥迪信设置工具</h3>"
                "<p><b>当前版本：</b>%1</p>"
                "<p><b>最新版本下载地址：</b><br>"
                "<a href=\"%2\">点击前往下载最新版本</a></p>"
                "<p style='font-size: 11px; color: gray;'>Copyright © 2026 shudongsheng. All rights reserved.</p>"
                ).arg(currentVersion).arg(downloadUrl);

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("版本信息");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(infoText);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.button(QMessageBox::Ok)->setText("确定");

    QDialogButtonBox *buttonBox = msgBox.findChild<QDialogButtonBox *>();
    if (buttonBox) {
        buttonBox->setCenterButtons(true);
    }
    msgBox.exec();
}

// 自述文件
void MainWindow::on_readme_triggered()
{
    QString filePath = qApp->applicationDirPath() + "/readme.docx";

    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "错误", "readme.docx 文件不存在！");
        return;
    }

    // 打开 Word 文件，使用系统默认程序
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

// 功能切换
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        return;
    qDebug() << "当前页面" << current->text();

    // 离开页面
    if (previous && previous->text() == "主机逻辑") {
    }
    if (previous && previous->text() == "主机逻辑")
    {

    }

    // 进入新页面时建立连接
    if (current->text() == "面板信息") {
    }
    if (current->text() == "面板信息") {
    }

    // 切换到新页面
    int row = ui->listWidget->row(current);
    ui->stackedWidget->setCurrentIndex(row);
}



#include "app_serial.h"
#include "ui_app_serial.h"

AppSerial::AppSerial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppSerial)
{
    ui->setupUi(this);

    ui->baudrate->addItem("9600");
    ui->baudrate->addItem("115200");
    ui->baudrate->setCurrentText("115200");

    ui->recv_timeout->addItem("10");
    ui->recv_timeout->addItem("20");
    ui->recv_timeout->addItem("50");
    ui->recv_timeout->addItem("100");

    m_frameTimer = new QTimer(this);
    m_frameTimer->setSingleShot(true);

    connect(m_frameTimer, &QTimer::timeout, this, &AppSerial::RecvTimeout, Qt::UniqueConnection);
    RefreshPorts();
    LoadSettings();
}

AppSerial::~AppSerial()
{
    SaveSettings();
    if (m_serial.isOpen())
        m_serial.close();
    delete ui;
}

// 发送数据
bool AppSerial::SerialSendData(const QByteArray &data)
{
    if (!m_serial.isOpen())
    {
        QMessageBox::warning(this, "错误", "串口未打开");
        return false;
    }

    qint64 len = m_serial.write(data);

    if (len == -1)
    {
        return false;
    }

    qDebug() << "发送HEX:" << data.toHex(' ').toUpper();
    emit sigSendData(data);
    return true;
}

// 接收数据
void AppSerial::SerialRecv()
{
    QByteArray data = m_serial.readAll();
    if (data.isEmpty())
        return;

    m_recvBuffer.append(data);
    if (m_autoFrame == true) // 如果开启了自动断帧
    {
        m_frameTimer->setInterval(m_timeout);
        m_frameTimer->start();
    }
    else
    {
        emit sigRecvData(data);
    }
}


// 刷新串口
void AppSerial::RefreshPorts()
{
    ui->com->clear();

    const auto ports = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &info : ports)
    {
        ui->com->addItem(info.portName());
    }
    if (ui->com->count() > 0)
    {
        ui->com->setCurrentIndex(0);
        m_portName = ui->com->currentText();
        qDebug() << "默认选择串口：" << m_portName;
    }
    else
    {
        m_portName.clear();
        qDebug() << "没有检测到串口";
    }
}


void AppSerial::on_baudrate_currentIndexChanged(const QString &arg1)
{
    bool ok = false;
    int baud = arg1.toInt(&ok);
    if (!ok) return;
    m_baudRate = baud;
}

// 串口选择
void AppSerial::on_com_currentIndexChanged(const QString &arg1)
{
    m_portName = arg1;
    qDebug() << "当前选择串口：" << m_portName;
}

void AppSerial::on_refresh_com_clicked()
{
    RefreshPorts();
}

// 打开串口
void AppSerial::on_switch_com_clicked()
{
    if (!m_isOpen)
    {
        m_baudRate = ui->baudrate->currentText().toInt(); // 从ui界面取到波特率
        m_serial.setPortName(m_portName);
        m_serial.setBaudRate(m_baudRate);
        m_serial.setDataBits(QSerialPort::Data8);
        m_serial.setParity(QSerialPort::NoParity);
        m_serial.setStopBits(QSerialPort::OneStop);
        m_serial.setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << "串口已打开：" << "端口=" << m_portName << "波特率=" << m_baudRate;

        if (!m_serial.open(QIODevice::ReadWrite))
        {
            QString err = m_serial.errorString();
            QMessageBox::warning(this, "错误\n",  err);
            return;
        }

        m_isOpen = true;
        ui->switch_com->setText("关闭");
        SetControlsEnabled(false); // 锁定控件
        connect(&m_serial, &QSerialPort::readyRead, this, &AppSerial::SerialRecv, Qt::UniqueConnection);
    }
    else
    {
        m_serial.close();
        m_isOpen = false;
        disconnect(&m_serial, &QSerialPort::readyRead, this, &AppSerial::SerialRecv);
        ui->switch_com->setText("打开");

        SetControlsEnabled(true); // 解锁控件
    }
}

// 接收超时
void AppSerial::RecvTimeout()
{
    if (m_recvBuffer.isEmpty())
        return;

    QByteArray frame = m_recvBuffer;
    m_recvBuffer.clear();

    qDebug() << "超时断帧HEX:" << frame.toHex(' ').toUpper();

    emit sigRecvData(frame);
}

// 是否自动断帧
void AppSerial::on_auto_check_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        m_autoFrame = true;
        qDebug() << "自动功能：开启";
    }
    else if (arg1 == Qt::Unchecked)
    {
        m_autoFrame = false;
        qDebug() << "自动功能：关闭";
    }
    m_recvBuffer.clear();
}

// 下拉框选择"断帧超时时间"时触发这个函数
void AppSerial::on_recv_timeout_activated(const QString &text)
{
    m_timeout= text.toInt(); // 字符串转为数字
    m_frameTimer->setInterval(m_timeout);
    qDebug() << "超时时间:" << m_timeout;
}

void AppSerial::SaveSettings()
{
    QSettings settings("MyCompany", "MySerialApp");

    settings.setValue("portName", m_portName);
    settings.setValue("baudRate", m_baudRate);
    settings.setValue("autoFrame", m_autoFrame);
    settings.setValue("timeout", m_timeout);
}

void AppSerial::LoadSettings()
{
    QSettings settings("MyCompany", "MySerialApp");
    m_portName = settings.value("portName", m_portName).toString();
    m_timeout = settings.value("timeout", m_timeout).toInt();
    m_baudRate = settings.value("baudRate", m_baudRate).toInt();
    m_autoFrame = settings.value("autoFrame", m_autoFrame).toBool();

    if (ui->com->findText(m_portName) >= 0) // 恢复串口
        ui->com->setCurrentText(m_portName);
    else if (ui->com->count() > 0)
        ui->com->setCurrentIndex(0);

    if (ui->baudrate->findText(QString::number(m_baudRate)) >= 0) // 恢复波特率
        ui->baudrate->setCurrentText(QString::number(m_baudRate));

    ui->auto_check->setChecked(m_autoFrame); // 恢复自动断帧

    if (ui->recv_timeout->findText(QString::number(m_timeout)) >= 0)  // 恢复超时时间
        ui->recv_timeout->setCurrentText(QString::number(m_timeout));

    m_frameTimer->setInterval(m_timeout); // timer
}

void AppSerial::SetControlsEnabled(bool enabled)
{
    ui->com->setEnabled(enabled);
    ui->baudrate->setEnabled(enabled);
    ui->refresh_com->setEnabled(enabled);
}


#include "app_set_addr.h"
#include "ui_app_set_addr.h"

AppSetAddr::AppSetAddr(QWidget *parent, AppSerial* serialWidget) :
    QWidget(parent),
    ui(new Ui::AppSetAddr)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    m_serialWidget = serialWidget;

    m_protocol_set_addr = new AppProtocolSetAddr(this, m_serialWidget);
    connect(m_protocol_set_addr, &AppProtocolSetAddr::sigDevVer, this, &AppSetAddr::updateVer, Qt::UniqueConnection);
    connect(m_serialWidget, &AppSerial::sigRecvData, m_protocol_set_addr, &AppProtocolSetAddr::RecvDataParse, Qt::UniqueConnection);
}

AppSetAddr::~AppSetAddr()
{
    delete ui;
}

void AppSetAddr::on_spinBox_valueChanged(int addr)
{
    if (addr > 32)
    {
        addr = 32;
        ui->spinBox->setValue(32); // 强制拉回最大值
        QMessageBox::warning(this, "提示", "地址不能大于32,已自动修改为32");
    }
    m_protocol_set_addr->AddrUpdate(addr);
}

// 地址群发
void AppSetAddr::on_pushButton_clicked()
{
   m_protocol_set_addr->AddrSendAll();
}

// 设备信息
void AppSetAddr::on_dev_info_clicked()
{
    m_protocol_set_addr->GetInfo();
}

// 回显设备信息
void AppSetAddr::updateVer(const uint8_t ver)
{
    uint8_t raw_version = ver;

    if (raw_version > 99)
    {
        raw_version = 99;
    }

    double version_num = raw_version / 10.0;

    QString version_str = QString("V %1").arg(version_num, 0, 'f', 1);

    ui->lineEdit->setText(version_str);
}

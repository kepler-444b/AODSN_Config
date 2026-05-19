#include "app_set_addr.h"
#include "ui_app_set_addr.h"

AppSetAddr::AppSetAddr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppSetAddr)
{
    ui->setupUi(this);
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
    emit sigAddrChanged(addr);
}

// 地址群发
void AppSetAddr::on_pushButton_clicked()
{
    emit sigAddrSendAll();
}

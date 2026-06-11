#ifndef APP_SET_ADDR_H
#define APP_SET_ADDR_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include "app/app_serial.h"
#include "app/app_protocol_set_addr.h"

namespace Ui {
class AppSetAddr;
}

class AppSetAddr : public QWidget
{
    Q_OBJECT

public:
    explicit AppSetAddr(QWidget *parent, AppSerial* serialWidget);
    ~AppSetAddr();

    void updateVer(const uint8_t ver);

signals:
    void sigAddrChanged(int addr);
    void sigAddrSendAll();
    void sigGetInfo();

private slots:
    void on_spinBox_valueChanged(int addr);

    void on_pushButton_clicked();

    void on_dev_info_clicked();

private:
    Ui::AppSetAddr *ui;
    AppSerial* m_serialWidget = nullptr; // 保存串口实例
    AppProtocolSetAddr * m_protocol_set_addr = nullptr;
};

#endif // APP_SET_ADDR_H

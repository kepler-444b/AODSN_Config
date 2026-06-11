#ifndef APP_PROTOCOL_H
#define APP_PROTOCOL_H

#include <QObject>
#include <QByteArray>
#include <QDebug>

#include "app/app_serial.h"

#define SET_ADDR_SINGLE          0x02 // 单发地址
#define SET_ADDR_BATCH           0x03 // 群发地址
#define SET_DEV_INFO             0x05 // 获取设备信息

class AppProtocolSetAddr : public QObject
{
    Q_OBJECT

public:
    explicit AppProtocolSetAddr(QObject *parent, AppSerial* serialWidget);

    // 接收原始数据
    void RecvDataParse(const QByteArray &data);
    void AddrUpdate(int addr);
    void AddrSendAll();
    void GetInfo();
    QByteArray BuildFrame(int addr, int type);

signals:
    void sigDevVer(const uint8_t ver);

private:
    int m_addr = 0;
    AppSerial* m_serialWidget = nullptr; // 保存串口实例
};

#endif // APP_PROTOCOL_H

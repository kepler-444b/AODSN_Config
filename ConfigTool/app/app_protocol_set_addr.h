#ifndef APP_PROTOCOL_H
#define APP_PROTOCOL_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QTimer>

class AppProtocolSetAddr : public QObject
{
    Q_OBJECT

public:
    explicit AppProtocolSetAddr(QObject *parent = nullptr);

    // 接收原始数据
    void RecvDataParse(const QByteArray &data);
    void AddrUpdate(int addr);
    void AddrSendAll();
    QByteArray BuildFrame(int addr);
    QByteArray BuildAllFrame(int addr);

signals:
    void sigSendData(const QByteArray &data);

private:
    QByteArray m_buffer;
    int m_addr = 0;
    bool ParseSetAddrRequest(QByteArray &buffer);
};

#endif // APP_PROTOCOL_H

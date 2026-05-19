#include "app_protocol_set_addr.h"

AppProtocolSetAddr::AppProtocolSetAddr(QObject *parent)
    : QObject(parent)
{

}

// 接收原始数据
void AppProtocolSetAddr::RecvDataParse(const QByteArray &data)
{
    qDebug() << "RecvDataParse" << data;
    m_buffer.append(data);
    while (m_buffer.size() > 0)
    {
        if(ParseSetAddrRequest(m_buffer))
            continue;
        m_buffer.remove(0, 1);
    }
}

// 面板请求地址
bool AppProtocolSetAddr::ParseSetAddrRequest(QByteArray &buffer)
{
    if (buffer.size() < 3)
        return false;

    if ((quint8)buffer[0] == 0xB1 && (quint8)buffer[1] == 0xB2 && (quint8)buffer[2] == 0xB3)
    {
        QByteArray frame = buffer.left(3);
        buffer.remove(0, 3);
        qDebug() << "面板请求地址";

        QTimer::singleShot(50, this, [=]() {
            QByteArray frame = BuildFrame(m_addr);
            emit sigSendData(frame);
        });
        return true;
    }
    return false;
}

// 地址更新
void AppProtocolSetAddr::AddrUpdate(int addr)
{
    m_addr = addr;
    qDebug() << "设置地址:" << addr;

}

// 群发地址
void AppProtocolSetAddr::AddrSendAll()
{
    qDebug() << "群发地址:";
    QByteArray frame = BuildAllFrame(m_addr);
    emit sigSendData(frame);
}

// 单发地址组帧
QByteArray AppProtocolSetAddr::BuildFrame(int addr)
{
    QByteArray frame;
    frame.append(char(0x1B));
    frame.append(char(0x2C));
    frame.append(char(addr));
    frame.append(char(0x3D));
    return frame;
}

// 群发地址组帧
QByteArray AppProtocolSetAddr::BuildAllFrame(int addr)
{
    QByteArray frame;
    frame.resize(34);   // 一共34字节，先分配好

    // byte0：地址字段（0xC0 表示 addr=0）
    frame[0] = char(0xC0 + addr);

    // byte1 ~ byte4
    frame[1] = char(0x0E);
    frame[2] = char(0x0E);
    frame[3] = char(0x0E);
    frame[4] = char(0x0E);

    // byte5 ~ byte12
    for (int i = 5; i <= 12; ++i)
        frame[i] = char(0x00);

    // byte13 ~ byte16 = 0x21
    for (int i = 13; i <= 16; ++i)
        frame[i] = char(0x21);

    // byte17 ~ byte22
    frame[17] = char(0x21);
    frame[18] = char(0x00);
    frame[19] = char(0x00);
    frame[20] = char(0x00);
    frame[21] = char(0x00);
    frame[22] = char(0x0E);

    // byte23 ~ byte28
    frame[23] = char(0x00);
    frame[24] = char(0x76);
    frame[25] = char(0x00);
    frame[26] = char(0x21);
    frame[27] = char(0x00);
    frame[28] = char(0x0E);

    // byte29 ~ byte32
    frame[29] = char(0x00);
    frame[30] = char(0x00);
    frame[31] = char(0x21);
    frame[32] = char(0x00);

    // byte33
    frame[33] = char(0xB0);
    return frame;
}

#include "app_protocol_set_addr.h"

AppProtocolSetAddr::AppProtocolSetAddr(QObject *parent, AppSerial* serialWidget)
    : QObject(parent)
{
    m_serialWidget = serialWidget;
}

// 接收原始数据
void AppProtocolSetAddr::RecvDataParse(const QByteArray &data)
{
    if (data.size() < 3)
        return;

    if ((quint8)data[0] != 0xFE || (quint8)data[1] != 0xBB)
        return;

    uint8_t cmd_type = (quint8)data[3];
    if (cmd_type == 0x02) // 请求地址
    {
        QByteArray frame = BuildFrame(m_addr, SET_ADDR_SINGLE);
        m_serialWidget->SerialSendData(frame);
    }
    if (cmd_type == 0x05) // 设备信息
    {
        emit sigDevVer(data[5]);
    }
    return;
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
    QByteArray frame = BuildFrame(m_addr, SET_ADDR_BATCH);
    m_serialWidget->SerialSendData(frame);
}

// 获取设备信息
void AppProtocolSetAddr::GetInfo()
{
    qDebug() << "获取设备信息:";
    QByteArray frame = BuildFrame(m_addr, SET_DEV_INFO);
    m_serialWidget->SerialSendData(frame);
}

// 单发地址组帧
QByteArray AppProtocolSetAddr::BuildFrame(int addr ,int type)
{
    QByteArray frame;
    frame.resize(9);

    // 开始组帧
    frame[0] = static_cast<char>(FRAME_TX_FH_1);
    frame[1] = static_cast<char>(FRAME_TX_FH_2);
    frame[2] = static_cast<char>(0x03); // 有效数据固定4个字节
    frame[3] = static_cast<char>(type);

    frame[7] = static_cast<char>(FRAME_TAIL_1);
    frame[8] = static_cast<char>(FRAME_TAIL_2);

    if (type == SET_DEV_INFO)
    {
        frame[4] = static_cast<char>(0x00);
        frame[5] = static_cast<char>(0x00); // reserve
        frame[6] = static_cast<char>(addr);

    }
    else if (type == SET_ADDR_BATCH || type == SET_ADDR_SINGLE)
    {
        frame[4] = static_cast<char>(0x1B);
        frame[5] = static_cast<char>(0x2C);
        frame[6] = static_cast<char>(addr);
    }
    return frame;
}

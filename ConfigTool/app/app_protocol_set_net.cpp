#include "app_protocol_set_net.h"


namespace {
// 协议头尾常量
constexpr uint8_t PACKET_HEAD_1 = 0xFA;
constexpr uint8_t PACKET_HEAD_2 = 0xFB;
constexpr uint8_t PACKET_TAIL_1 = 0x0D;
constexpr uint8_t PACKET_TAIL_2 = 0x0A;
}

AppProtocolSetNet::AppProtocolSetNet(QObject *parent, AppSerial* serialWidget)
    : QObject(parent)
{
    m_serialWidget = serialWidget;
}

void AppProtocolSetNet::RecvDataParse(const QByteArray &data)
{
    if (data.size() < static_cast<int>(sizeof(dev_packet_t))) {
        qDebug() << "Data too short!";
        return;
    }

    memcpy(&m_dev_packet, data.constData(), sizeof(dev_packet_t));
    emit sigUpdate(m_dev_packet);

}

// 获取设备信息
bool AppProtocolSetNet::GetInfoData(void)
{
    QByteArray payload;
    payload.append(static_cast<char>(0x01));
    payload.append(static_cast<char>(0x02));
    payload.append(static_cast<char>(0x03));

    QByteArray packet = PackData(0x01, payload);

    if (m_serialWidget) {
      return m_serialWidget->SerialSendData(packet);
    }
    return false;
}

// 下发设备信息
bool AppProtocolSetNet::SetInfoData(const dev_packet_t &info)
{
    QByteArray payload(reinterpret_cast<const char*>(&info), sizeof(info));
    QByteArray packet = PackData(0x01, payload);

    if (m_serialWidget) {
        return m_serialWidget->SerialSendData(packet);
    }
    return false;
}

// 打包函数
QByteArray AppProtocolSetNet::PackData(uint8_t cmdType, const QByteArray &payload)
{
    QByteArray packet;
    packet.reserve(2 + 1 + payload.size() + 2); // 头+cmd+payload+尾

    packet.append(static_cast<char>(PACKET_HEAD_1));
    packet.append(static_cast<char>(PACKET_HEAD_2));
    packet.append(static_cast<char>(cmdType));
    packet.append(payload);
    packet.append(static_cast<char>(PACKET_TAIL_1));
    packet.append(static_cast<char>(PACKET_TAIL_2));

    return packet;
}

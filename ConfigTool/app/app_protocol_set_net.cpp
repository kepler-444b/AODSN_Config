#include "app_protocol_set_net.h"

AppProtocolSetNet::AppProtocolSetNet(QObject *parent, AppSerial* serialWidget)
    : QObject(parent)
{
    m_serialWidget = serialWidget;
}

void AppProtocolSetNet::RecvDataParse(const QByteArray &data)
{
    qDebug() << "size" << sizeof(dev_packet_t);
    if (data.size() < static_cast<int>(sizeof(dev_packet_t))) {
        qDebug() << "Data too short!";
        return;
    }

    memcpy(&m_dev_packet, data.constData(), sizeof(dev_packet_t));
    emit sigUpdate(m_dev_packet);

}

// 获取设备信息
void AppProtocolSetNet::GetInfoData(void)
{
    QByteArray sendData;

    sendData.append(static_cast<char>(0xFA));
    sendData.append(static_cast<char>(0xFB));
    sendData.append(static_cast<char>(0x01));
    sendData.append(static_cast<char>(0x02));
    sendData.append(static_cast<char>(0x03));
    sendData.append(static_cast<char>(0x0D));
    sendData.append(static_cast<char>(0x0A));

    m_serialWidget->SerialSendData(sendData);
}

void AppProtocolSetNet::SetInfoData(const dev_packet_t &info)
{
    QByteArray sendData;

    sendData.append(static_cast<char>(0xFA));
    sendData.append(static_cast<char>(0xFB));

    sendData.append(reinterpret_cast<const char*>(&info), sizeof(info));

    sendData.append(static_cast<char>(0x0D));
    sendData.append(static_cast<char>(0x0A));

    // 发送
    if (m_serialWidget) {
        m_serialWidget->SerialSendData(sendData);
    }

}

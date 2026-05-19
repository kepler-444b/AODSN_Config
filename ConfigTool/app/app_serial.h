#ifndef APP_SERIAL_H
#define APP_SERIAL_H

#include <QWidget>
#include <QTime>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "app_protocol_set_addr.h"

namespace Ui {
class AppSerial;
}

class AppSerial : public QWidget
{
    Q_OBJECT

public:
    explicit AppSerial(QWidget *parent = nullptr);
    ~AppSerial();

    bool SerialSendData(const QByteArray &data);

private slots:
    void on_baudrate_currentIndexChanged(const QString &arg1); // 选择波特率
    void on_com_currentIndexChanged(const QString &arg1);      // 选择端口

    void on_refresh_com_clicked();
    void on_switch_com_clicked();
    void SerialRecv();
    void on_auto_check_stateChanged(int arg1);
    void on_recv_timeout_activated(const QString &text);

signals:
    void sigRecvData(const QByteArray &data);
    void sigSendData(const QByteArray &data);

private:
    void RefreshPorts(); // 扫描端口
    void RecvTimeout();
    void LoadSettings();
    void SaveSettings();
    void SetControlsEnabled(bool enabled);

    int m_baudRate = 115200;
    int m_timeout = 20;
    bool m_autoFrame = true;
    bool m_isOpen = false;

    Ui::AppSerial *ui;
    QSerialPort m_serial;
    QString m_portName;
    QByteArray m_recvBuffer;
    QTimer *m_frameTimer;

};

#endif // APP_SERIAL_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDebug>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include "app/app_serial.h"
#include "app/app_display.h"
#include "app/app_set_addr.h"
#include "app/app_set_config.h"
#include "app/app_set_net.h"
#include "app/app_protocol_set_addr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override; // 重写关闭事件

private slots:
    void on_debug_triggered();
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::MainWindow *ui             = nullptr;
    AppSerial *SerialWidget        = nullptr;
    AppDisplay *DisplayWidget      = nullptr;
    AppSetAddr *SetAddrWidget      = nullptr;
    AppProtocolSetAddr *m_protocol = nullptr;
    AppSetConfig *SetConfigWidget  = nullptr;
    AppSetNet* SetNetWidget        = nullptr;


};
#endif // MAINWINDOW_H

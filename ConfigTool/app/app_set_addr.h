#ifndef APP_SET_ADDR_H
#define APP_SET_ADDR_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AppSetAddr;
}

class AppSetAddr : public QWidget
{
    Q_OBJECT

public:
    explicit AppSetAddr(QWidget *parent = nullptr);
    ~AppSetAddr();
signals:
    void sigAddrChanged(int addr);
    void sigAddrSendAll();

private slots:
    void on_spinBox_valueChanged(int addr);

    void on_pushButton_clicked();

private:
    Ui::AppSetAddr *ui;
};

#endif // APP_SET_ADDR_H

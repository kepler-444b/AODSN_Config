#ifndef MODEL_RELAY_EX_H
#define MODEL_RELAY_EX_H


#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QMouseEvent>
#include <QAction>
#include "app/app_sel_extend.h"

namespace Ui {
class ModelRelayEx;
}

class ModelRelayEx : public QWidget
{
    Q_OBJECT

public:
    explicit ModelRelayEx(QWidget *parent = nullptr);
    ~ModelRelayEx();
    void SetExtendAddr(const uint8_t addr, const ExtendType type);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

private:
    Ui::ModelRelayEx *ui;

    uint8_t m_addr = 0;
    ExtendType m_type = LED_EX;
};

#endif // MODEL_RELAY_EX_H

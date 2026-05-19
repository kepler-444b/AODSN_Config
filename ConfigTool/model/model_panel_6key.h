#ifndef MODEL_PANEL_6KEY_H
#define MODEL_PANEL_6KEY_H

#include <QWidget>
#include <QMouseEvent>
#include <QInputDialog>
#include <QPushButton>
#include <QtDebug>
#include <QMenu>
#include <QAction>
#include "app/app_protocol_set_config.h"

namespace Ui {
class ModelPanel6Key;
}

class ModelPanel6Key : public QWidget
{
    Q_OBJECT

public:
    explicit ModelPanel6Key(QWidget *parent = nullptr);
    ~ModelPanel6Key();
    void SetPanelAddr(const uint8_t addr);
    void SetKeyNames(const QStringList &names);
    void updateSceneList(const QVector<scene_save_t>& scenes) { m_sceneList = scenes; };

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void requestDelete(int id); // 删除产品
    void keyNameChanged(uint8_t panelId, int keyIndex, const QString& newName); // 按键改名
    void requestBindScene(uint8_t panel_addr, int key_num, uint8_t scene_id, bool state);

private:
    Ui::ModelPanel6Key *ui;
    QList<QPushButton*> m_buttons;  // 存储6个按钮
    QVector<scene_save_t> m_sceneList;   // 获取场景列表
    uint8_t m_addr = 0;

};

#endif // MODEL_PANEL_6KEY_H

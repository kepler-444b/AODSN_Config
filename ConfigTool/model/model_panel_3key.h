#ifndef MODEL_PANEL_3KEY_H
#define MODEL_PANEL_3KEY_H

#include <QWidget>
#include <QMouseEvent>
#include <QInputDialog>
#include <QPushButton>
#include <QtDebug>
#include <QMenu>
#include <QAction>
#include "app/app_protocol_set_config.h"

namespace Ui {
class ModelPanel3Key;
}

class ModelPanel3Key : public QWidget
{
    Q_OBJECT

public:
    explicit ModelPanel3Key(QWidget *parent = nullptr);
    ~ModelPanel3Key();
    void SetPanelAddr(const uint8_t addr);
    void SetKeyNames(const QStringList &names);

    void updateSceneList(const QVector<scene_save_t>& scenes) { m_sceneList = scenes; };
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void requestDelete(int id);
    void keyNameChanged(uint8_t panelId, int keyIndex, const QString& newName);
    void requestBindScene(uint8_t panel_addr, int key_num, uint8_t scene_id, bool state);
private:
    Ui::ModelPanel3Key *ui;
    QList<QPushButton*> m_buttons;
    uint8_t m_addr = 0;
    QVector<scene_save_t> m_sceneList;
};

#endif // MODEL_PANEL_3KEY_H

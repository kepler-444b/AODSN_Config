#ifndef APPPROTOCOLSETCONFIG_H
#define APPPROTOCOLSETCONFIG_H

#include <QObject>
#include <QVector>
#include <QtDebug>
#include <QEventLoop>
#include "app_sel_set_scene.h"
#include "app/app_serial.h"


// 场景数据
typedef struct
{
    QString scene_name;
    QByteArray scene_data;
    uint8_t scene_id;
} scene_save_t;

// 面板状态
typedef struct
{
    uint8_t scene_id;           // 场景id
    QString scene_name;         // 场景别名

    uint8_t panel_addr;         // 面板地址
    uint8_t panel_type;         // 面板类型
    uint8_t panel_key_num;      // 按键数量
    QString panel_name[6];      // 按键别名
    QVector<bool> key_enable;   // 按键勾选状态
    QVector<bool> key_state;    // 对应状态勾选状态
} panel_save_t;

// led扩展状态
typedef struct
{
    uint8_t scene_id;              // 场景id
    QString scene_name;            // 场景别名

    uint8_t led_addr;              // 扩展地址
    QVector<bool> led_enable;      // 通道是否勾选
    QVector<int>  led_value;       // 输入的亮度值 (0-100)
} led_save_t;

// 继电器扩展状态
typedef struct
{
   uint8_t scene_id;
   QString scene_name;
   uint8_t relay_addr;

   QVector<bool> relay_enable;
   QVector<bool> relay_state;
} relay_save_t;

typedef struct
{
    QVector<scene_save_t> scene;
    QVector<panel_save_t> panel;
    QVector<led_save_t>   led_ex;
    QVector<relay_save_t> relay_ex;
} config_data_t;

typedef struct
{
    QString scene_name;
    QByteArray bind_data;
} bind_save_t;

typedef struct
{
  QVector<bind_save_t> bind_data;
} bind_data_t;

class AppProtocolSetConfig : public QObject
{
    Q_OBJECT

public:
    explicit AppProtocolSetConfig(QObject *parent, AppSerial* serialWidget);


public slots:
    void recv_scene_data(const QVector<panel_data_t>& panels, const QVector<led_data_t>& leds, const QVector<relay_data_t>& relays, uint8_t scene_id, QString name, bool &success);
    void recv_bind_data(uint8_t panelAddr, int keyIndex, uint8_t sceneId, bool isOpen);

    void bulidSceneData(const QVector<panel_data_t>& panels, const QVector<led_data_t>& leds, const QVector<relay_data_t>& relays, uint8_t scene_id, QString name);
    void buildBindData(uint8_t addr, uint8_t key_num, uint8_t state, uint8_t scene_id, QString scene_name);
    void printConfigData() const;
    void deleteScene(uint8_t scene_id);
    void deleteBind(const bind_save_t &bind);

    config_data_t getAllConfigData() const;
    bind_data_t getAllBindData() const;
    config_data_t getSceneConfigDataById(uint8_t scene_id) const;

    void setAllConfigData(const config_data_t& data);
    void setAllBindData(const bind_data_t& binds);

    void sendSceneData(void); // 下发场景数据
    void sendBindData(void);  // 下发绑定信息

    void sendClearSceneData(void);
    void sendClearBindData(void);

    QByteArray packFrame(const QByteArray &payload, const QByteArray &cmdType); // 打包函数


signals:
    void sceneListChanged(const QVector<scene_save_t>& data); // 场景列表发生变化
    void bindListChanged(const QVector<bind_save_t>& data);  // 绑定列表发生变化

private:

    AppSerial* m_serialWidget = nullptr; // 保存串口实例

    QVector<scene_save_t> m_scene_save;  // 保存场景数据
    QVector<panel_save_t> m_panel_save;  // 保存面板结构
    QVector<led_save_t> m_led_save;      // 保存led扩展结构
    QVector<relay_save_t> m_relay_save;  // 保存relay扩展结构

    QVector<bind_save_t> m_bind_save;    // 保存绑定结构
};


#endif // APPPROTOCOLSETCONFIG_H

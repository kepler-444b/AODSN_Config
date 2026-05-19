#ifndef APP_SET_CONFIG_H
#define APP_SET_CONFIG_H

#include <QWidget>
#include <QtDebug>
#include <QMessageBox>
#include <QGridLayout>
#include <QSettings>
#include <QHash>
#include <QTimer>
#include <QShortcut>
#include <QKeySequence>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>

#include "app/app_serial.h"
#include "app_sel_panel.h"
#include "app_sel_extend.h"
#include "app_sel_set_scene.h"
#include "app_all_list.h"
#include "app_protocol_set_config.h"

#include "model/model_panel_1key.h"
#include "model/model_panel_2key.h"
#include "model/model_panel_3key.h"
#include "model/model_panel_4key.h"
#include "model/model_panel_6key.h"
#include "model/model_led_ex.h"
#include "model/model_relay_ex.h"
#include "flow/flowlayout.h"

#define MAX_PANEL  32
#define MAX_LED     4
#define MAX_RELAY   4


namespace Ui {
class AppSetConfig;
}

class AppSetConfig : public QWidget
{
    Q_OBJECT

public:
    explicit AppSetConfig(QWidget *parent, AppSerial* serialWidget);
    ~AppSetConfig();

    void RemovePanel(uint8_t id);
    void UpdatePanelKeyName(uint8_t panelId, int keyIndex, const QString& newAlias);

    void RemoveExtend(uint8_t id, ExtendType type); // 删除扩展

private slots:
    void on_add_panel_clicked();
    void on_add_extend_clicked();
    void on_set_scene_clicked();
    void create_scene(int id);
    void on_pushButton_clicked();

    void on_load_data_clicked();

    void saveWidgets(const QString& filePath = "data.json");
    bool loadWidgets(const QString& filePath = "data.json");
    void autoLoadAllData(); // 自动加载

    void saveSceneDatas(const QString &filePath); // 保存场景信息及扩展状态
    bool loadSceneDatas(const QString &filePath); // 加载创建信息及扩展状态

    void saveBindDatas(const QString &filePath);  // 保存绑定信息
    bool loadBindDatas(const QString &filePath);  // 加载绑定信息

    void on_save_data_clicked();

private:
    Ui::AppSetConfig *ui;

     AppSerial* m_serialWidget = nullptr; // 保存串口实例

    template<typename PanelType> // 模版函数,使用泛型编程
    QWidget* CreateSetupPanel(const PanelInfo_t& info);

    // 添加面板
    PanelInfo_t m_panelArray[MAX_PANEL];
    PanelInfo_t m_lastPanelInfo = {0, PANEL, 1, {}};
    int m_panelCount = 0;

    DialogPanel *m_panelSelDialog   = nullptr;

    // 添加扩展
    ExtendInfo_t m_ledArray[MAX_LED];       // led 扩展
    ExtendInfo_t m_relayArray[MAX_RELAY];   // 继电器扩展

    int m_ledCount   = 0;
    int m_relayCount = 0;
    ExtendInfo_t m_lastExtendInfo = {0, LED_EX};
    DialogExtend *m_extendSelDialog = nullptr;


    FlowLayout *m_flowLayout = nullptr;

    QHash<uint8_t, QWidget*> m_panelMap;
    QHash<uint8_t, QWidget*> m_ledMap;
    QHash<uint8_t, QWidget*> m_relayMap;

    bool IsPanelIdExist(uint8_t id) const;
    bool IsExtendLedExist(ExtendInfo_t *info) const;


    QWidget* CreatePanelWidget(const PanelInfo_t& info);
    QWidget* CreateExtendWidget(const ExtendInfo_t& info);
    void AddPanelToLayout(QWidget* panelWidget);

    void CreateListWindow();   // 创建场景列表窗口

    DialogSetScene *m_set_sceneDialog = nullptr;
    AppAllList* m_sceneListWidget  = nullptr;
    AppProtocolSetConfig *m_protocol_set_config = nullptr;
};


#endif // APP_SET_CONFIG_H

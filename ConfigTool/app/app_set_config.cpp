#include "app_set_config.h"
#include "ui_app_set_config.h"

AppSetConfig::AppSetConfig(QWidget *parent, AppSerial* serialWidget) :
    QWidget(parent),
    ui(new Ui::AppSetConfig)
{
    ui->setupUi(this);                                                       // 将 .ui 文件中设计的控件部署到当前类上
    m_serialWidget = serialWidget;

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);     // 设置伸缩策略
    ui->scrollArea->setWidgetResizable(true);                                // 设置滚动区域
    m_flowLayout = new FlowLayout(ui->scrollAreaWidgetContents, 10, 10, 10); // 初始化流式布局管理器

    m_protocol_set_config = new AppProtocolSetConfig(this, m_serialWidget);   // 创建协议数据实例

    CreateListWindow(); // 创建场景列表

    connect(m_sceneListWidget, &AppAllList::requestDeleteScene, m_protocol_set_config, &AppProtocolSetConfig::deleteScene);
    connect(m_sceneListWidget, &AppAllList::requsetDeleteBind, m_protocol_set_config, &AppProtocolSetConfig::deleteBind);

    QTimer::singleShot(100, this, &AppSetConfig::autoLoadAllData);         // 加载上次保存的配置
    QShortcut* shortcutSave = new QShortcut(QKeySequence("Ctrl+S"), this); // ctrl + s 触发保存快捷键
    connect(shortcutSave, &QShortcut::activated, this, &AppSetConfig::on_load_data_clicked);
}

AppSetConfig::~AppSetConfig()
{
    delete ui;
}

// 添加面板
void AppSetConfig::on_add_panel_clicked()
{
    if (!m_panelSelDialog)
    {
        m_panelSelDialog = new DialogPanel(this);
    }

    m_panelSelDialog->SetPanelInfo(m_lastPanelInfo);

    if (m_panelSelDialog->exec() != QDialog::Accepted)
        return;

    PanelInfo_t info = m_panelSelDialog->GetPanelInfo();

    if (IsPanelIdExist(info.addr))
    {
        QMessageBox::warning(this, "警告", "地址已存在,请重新设置");
        return;
    }

    if (m_panelCount >= MAX_PANEL)
    {
        qDebug() << "数组已满";
        return;
    }

    QWidget* panelWidget = CreatePanelWidget(info);
    if (!panelWidget)
        return;

    AddPanelToLayout(panelWidget);
    m_panelMap.insert(info.addr, panelWidget); // 注册 UI 映射

    // 保存数据
    m_panelArray[m_panelCount] = info;
    m_panelCount++;
    m_lastPanelInfo = info;

    qDebug() << "添加成功:" << m_panelCount;
}

// 添加扩展
void AppSetConfig::on_add_extend_clicked()
{
    if (!m_extendSelDialog)
    {
        m_extendSelDialog = new DialogExtend(this);
    }
    m_extendSelDialog->SetExtendInfo(m_lastExtendInfo);
    if (m_extendSelDialog->exec() != QDialog::Accepted)
        return;

    ExtendInfo_t info = m_extendSelDialog->GetExtendInfo();
    if (IsExtendLedExist(&info))
    {
        QMessageBox::warning(this, "警告", "地址已存在,请重新设置");
        return;
    }

    if (info.type == LED_EX) {
        if (m_ledCount >= MAX_LED) return;
        m_ledArray[m_ledCount++] = info;
    }
    else if (info.type == RELAY_EX) {
        if (m_relayCount >= MAX_RELAY) return;
        m_relayArray[m_relayCount++] = info;
    }

    QWidget* extendWidget = CreateExtendWidget(info);
    if (!extendWidget) return;

    AddPanelToLayout(extendWidget);

    if (info.type == LED_EX) {
        m_ledMap.insert(info.id, extendWidget);
    }
    else if (info.type == RELAY_EX) {
        m_relayMap.insert(info.id, extendWidget);
    }

    m_lastExtendInfo = info;
}

void AppSetConfig::on_set_scene_clicked()
{
    create_scene(-1);
}

// 创建场景
void AppSetConfig::create_scene(int id)
{
    bool is_edit = (id != -1);
    uint8_t scene_id   = 0;
    QString scene_name = "NULL";

    QVector<PanelInfo_t> panelList;
    QVector<ExtendInfo_t> extendlist;

    for (int i = 0; i < m_panelCount; ++i)
        panelList.append(m_panelArray[i]);

    for (int i = 0; i < m_ledCount; i++)
    {
        if (m_ledArray[i].type == LED_EX)
            extendlist.append(m_ledArray[i]);
    }
    for (int i = 0; i <m_relayCount; i++)
    {
        if (m_relayArray[i].type == RELAY_EX)
            extendlist.append(m_relayArray[i]);
    }


    if (is_edit) // 是编辑场景
    {
        config_data_t temp = m_protocol_set_config->getSceneConfigDataById(id);

        scene_id   = temp.scene[0].scene_id;
        scene_name = temp.scene[0].scene_name;

        for (auto& panel : panelList)
        {
            auto it = std::find_if(temp.panel.begin(), temp.panel.end(), [&panel](const panel_save_t& savedPanel) {
                return panel.addr == savedPanel.panel_addr;
            });

            if (it != temp.panel.end())
            {
                panel.key_enable = it->key_enable;
                panel.key_state  = it->key_state;
            }
        }
        for (auto& extend : extendlist)
        {
            if (extend.type == ExtendType::LED_EX)
            {
                auto it = std::find_if(temp.led_ex.begin(), temp.led_ex.end(), [&extend](const led_save_t& savedLed) {
                    return extend.id == savedLed.led_addr;
                });

                if (it != temp.led_ex.end())
                {
                    extend.led_enable = it->led_enable;
                    extend.led_value  = it->led_value;
                }
            }
            else if (extend.type == ExtendType::RELAY_EX)
            {
                auto it = std::find_if(temp.relay_ex.begin(), temp.relay_ex.end(), [&extend](const relay_save_t& savedRelay) {
                    return extend.id == savedRelay.relay_addr;
                });

                if (it != temp.relay_ex.end())
                {
                    extend.relay_enable = it->relay_enable;
                    extend.relay_state  = it->relay_state;
                }
            }
        }
    }

    if (m_set_sceneDialog)
    {
        delete m_set_sceneDialog;
        m_set_sceneDialog = nullptr;
    }

    m_set_sceneDialog = new DialogSetScene(panelList, extendlist, scene_id, scene_name, this);
    connect(m_set_sceneDialog, &DialogSetScene::send_config, m_protocol_set_config, &AppProtocolSetConfig::recv_scene_data); // 连接信号,到prorocol_set_config中处理

    if (m_set_sceneDialog->exec() != QDialog::Accepted)
        return;
}

template<typename PanelBase>
QWidget* AppSetConfig::CreateSetupPanel(const PanelInfo_t& info)
{
    auto panel = new PanelBase(this); // 根据传入的类型创建对象
    panel->SetPanelAddr(info.addr);

    // 连接信号
    connect(panel, &PanelBase::requestDelete, this, &AppSetConfig::RemovePanel);
    connect(panel, &PanelBase::keyNameChanged, this, &AppSetConfig::UpdatePanelKeyName);
    connect(panel, &PanelBase::requestBindScene,  m_protocol_set_config, &AppProtocolSetConfig::recv_bind_data);      // 连接信号,处理绑定信息
    connect(m_protocol_set_config, &AppProtocolSetConfig::sceneListChanged, panel, &PanelBase::updateSceneList);      // 连接信号,当场景更新时,发送给PanelBase
    panel->updateSceneList(m_protocol_set_config->getAllConfigData().scene);                                          // PanelBase在创建时,主动获取场景列表

    // 设置按键名称
    QStringList names;
    for (int i = 0; i < 6; ++i) {
        names.append(info.key_name[i]);
    }
    panel->SetKeyNames(names);
    return panel;
}


// 创建 panel
QWidget* AppSetConfig::CreatePanelWidget(const PanelInfo_t& info)
{
    switch (info.key_num)
    {
    case 1: return CreateSetupPanel<ModelPanel1Key>(info);
    case 2: return CreateSetupPanel<ModelPanel2Key>(info);
    case 3: return CreateSetupPanel<ModelPanel3Key>(info);
    case 4: return CreateSetupPanel<ModelPanel4Key>(info);
    case 6: return CreateSetupPanel<ModelPanel6Key>(info);
    default:
        qDebug() << "不支持的按键数量:" << info.key_num;
        return nullptr;
    }
}


// 创建扩展
QWidget* AppSetConfig::CreateExtendWidget(const ExtendInfo_t& info)
{
    if (info.type == LED_EX)
    {
        auto extend = new ModelLedEx(this);
        extend->SetExtendAddr(info.id, info.type);
        connect(extend, &ModelLedEx::requestDelete, this, &AppSetConfig::RemoveExtend);
        return extend;
    }
    else if (info.type == RELAY_EX)
    {
        auto extend = new ModelRelayEx(this);
        extend->SetExtendAddr(info.id, info.type);
        //        connect(extend, &ModelLedEx::requestDelete, this, &AppSetConfig::RemoveExtend);
        return extend;
    }
    return nullptr;
}


// 添加到布局
void AppSetConfig::AddPanelToLayout(QWidget* panelWidget)
{
    if (!panelWidget)
        return;
    m_flowLayout->addWidget(panelWidget);
}

// 删除 panel
void AppSetConfig::RemovePanel(uint8_t id)
{
    QWidget* w = m_panelMap.take(id);
    if (!w) return;

    m_flowLayout->removeWidget(w);
    w->deleteLater();

    for (int i = 0; i < m_panelCount; i++)
    {
        if (m_panelArray[i].addr == id)
        {
            for (int j = i; j < m_panelCount - 1; j++)
                m_panelArray[j] = m_panelArray[j + 1];
            m_panelCount--;
            break;
        }
    }
    qDebug() << "删除panel id:" << id;
}

// 删除扩展
void AppSetConfig::RemoveExtend(uint8_t id, ExtendType type)
{
    QWidget* w = nullptr;

    if (type == LED_EX)
    {
        w = m_ledMap.take(id);
        if (!w) return;

        m_flowLayout->removeWidget(w);
        w->deleteLater();

        for (int i = 0; i < m_ledCount; i++)
        {
            if (m_ledArray[i].id == id)
            {
                for (int j = i; j < m_ledCount - 1; j++)
                    m_ledArray[j] = m_ledArray[j + 1];
                m_ledCount--;
                break;
            }
        }
        qDebug() << "删除 LED 扩展 id:" << id;
    }
    else if (type == RELAY_EX)
    {
        // 继电器扩展暂不实现
        qDebug() << "删除继电器扩展 id:" << id << " 暂未实现";
        return;
    }
}

void AppSetConfig::UpdatePanelKeyName(uint8_t panelId, int keyIndex, const QString& newAlias)
{
    if (keyIndex < 0 || keyIndex >= 6)
        return;

    // 更新 m_panelArray 中的数据
    for (int i = 0; i < m_panelCount; ++i)
    {
        if (m_panelArray[i].addr == panelId)
        {
            m_panelArray[i].key_name[keyIndex] = newAlias;
            qDebug() << QString("更新面板 %1 的按键 %2 别名: %3")
                        .arg(panelId).arg(keyIndex+1).arg(newAlias);
            return;
        }
    }

    qDebug() << "未找到面板ID:" << panelId;
}

// id是否存在
bool AppSetConfig::IsPanelIdExist(uint8_t id) const
{
    return m_panelMap.contains(id);
}

bool AppSetConfig::IsExtendLedExist(ExtendInfo_t *info) const
{
    if (info->type == LED_EX)
    {
        return m_ledMap.contains(info->id);
    }
    else if(info->type == RELAY_EX)
    {
        return  m_relayMap.contains(info->id);
    }
    return true;
}


// 创建场景列表
void AppSetConfig::CreateListWindow()
{
    if (!m_sceneListWidget)
    {
        m_sceneListWidget = new AppAllList(nullptr);

        QWidget* mainWindow = this->window();
        QRect parentRect = mainWindow->frameGeometry(); // 让窗口在主窗口右侧,垂直居中

        int newX = parentRect.right();
        int newY = parentRect.top() + (parentRect.height() - m_sceneListWidget->height()) / 2;
        m_sceneListWidget->move(newX, newY);

        connect(m_sceneListWidget, &QWidget::destroyed, this, [this]() {m_sceneListWidget = nullptr;}); // 当窗口关闭时,将指针置空
        connect(m_sceneListWidget, &AppAllList::requestSendSceneData,  m_protocol_set_config, &AppProtocolSetConfig::sendSceneData);    // 下发设备场景
        connect(m_sceneListWidget, &AppAllList::requestSendBindData, m_protocol_set_config, &AppProtocolSetConfig::sendBindData);       // 下发设备绑定

        connect(m_sceneListWidget, &AppAllList::requestClearSceneData,  m_protocol_set_config, &AppProtocolSetConfig::sendClearSceneData); // 删除设备场景
        connect(m_sceneListWidget, &AppAllList::requestClearBindData, m_protocol_set_config, &AppProtocolSetConfig::sendClearBindData);    // 删除设备绑定

        connect(m_sceneListWidget, &AppAllList::requestEditScene, this, &AppSetConfig::create_scene);

        connect(m_protocol_set_config, &AppProtocolSetConfig::sceneListChanged, m_sceneListWidget, &AppAllList::setSceneData); // 连接场景数据
        connect(m_protocol_set_config, &AppProtocolSetConfig::bindListChanged,m_sceneListWidget, &AppAllList::setBindData);    // 连接绑定数据

    }
}

// 打开场景列表
void AppSetConfig::on_pushButton_clicked()
{
    CreateListWindow();
    m_sceneListWidget->show();
    m_sceneListWidget->raise();
    m_sceneListWidget->activateWindow();
}

// 保存配置信息
void AppSetConfig::on_load_data_clicked()
{
    QSettings settings("AODSN", "ConfigTool");
    QString defaultPath = settings.value("lastSavePath", "data.json").toString();

    QString filePath = QFileDialog::getSaveFileName(this, "保存配置信息", defaultPath, "JSON Files (*.json);;All Files (*.*)");
    if (filePath.isEmpty()) return;

    saveWidgets(filePath);       // 保存UI配置
    saveSceneDatas(filePath);    // 保存协议数据
    saveBindDatas(filePath);     // 保存绑定信息

    settings.setValue("lastSavePath", filePath); // 保存到 QSettings,确保下次可用
    QMessageBox::information(this, "保存成功", QString("配置已成功保存！\n文件路径：%1\n共保存 %2 个面板").arg(filePath).arg(m_panelCount));
}

// 加载配置信息
void AppSetConfig::on_save_data_clicked()
{
    QSettings settings("AODSN", "ConfigTool");
    QString defaultPath = settings.value("lastSavePath", "data.json").toString();
    QString filePath = QFileDialog::getOpenFileName(this, "加载配置信息", defaultPath, "JSON Files (*.json);;All Files (*.*)");

    if (filePath.isEmpty())
        return;

    if (loadWidgets(filePath)) {
        settings.setValue("lastSavePath", filePath); // 成功加载后，保存当前路径，方便下次打开默认选中
        QMessageBox::information(this, "加载成功", QString("配置已成功加载!\n%1个面板,%2个LED扩展,%3个继电器扩展").arg(m_panelCount).arg(m_ledCount).arg(m_relayCount));
    } else {
        QMessageBox::warning(this, "加载失败", "配置文件加载失败，请检查文件格式或路径。");
    }

    if (loadWidgets(filePath)) {
        loadSceneDatas(filePath);
        loadBindDatas(filePath);
        QMessageBox::information(this, "加载成功", "配置与场景数据已同步加载！");
    }
}

// 保存界面文件
void AppSetConfig::saveWidgets(const QString& filePath)
{
    QFile file(filePath);
    QJsonObject root;

    // 如果文件存在,先读取
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        if (doc.isObject()) root = doc.object();
    }

    // 保存原来的 saveData 内容到 config 对象
    QJsonObject configObj;

    // panel
    QJsonArray panelArray;
    for (int i = 0; i < m_panelCount; ++i) {
        const auto& p = m_panelArray[i];
        QJsonObject obj{
            {"id", p.addr},
            {"type", static_cast<int>(p.type)},
            {"key_num", p.key_num}
        };
        QJsonArray keyNames;
        for (const auto& name : p.key_name) keyNames.append(name);
        obj["key_name"] = keyNames;
        panelArray.append(obj);
    }
    configObj["panel"] = panelArray;

    // led_ex
    QJsonArray ledArray;
    for (int i = 0; i < m_ledCount; ++i) {
        const auto& led = m_ledArray[i];
        QJsonObject obj{
            {"id", led.id},
            {"type", static_cast<int>(led.type)}
        };
        ledArray.append(obj);
    }
    configObj["led_ex"] = ledArray;

    // relay_ex
    QJsonArray relayArray;
    for (int i = 0; i < m_relayCount; ++i) {
        const auto& relay = m_relayArray[i];
        QJsonObject obj{
            {"id", relay.id},
            {"type", static_cast<int>(relay.type)}
        };
        relayArray.append(obj);
    }
    configObj["relay_ex"] = relayArray;
    configObj["panel_count"] = m_panelCount;
    configObj["led_ex_count"] = m_ledCount;
    configObj["relay_ex_count"] = m_relayCount;

    root["config"] = configObj; // 放到顶层 config 对象下

    // 写回文件
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "saveData 保存成功到 config 对象";
    } else {
        qWarning() << "写入失败：" << file.errorString();
    }
}

// 自动加载布局
void AppSetConfig::autoLoadAllData(void)
{
    QSettings settings("AODSN", "ConfigTool");
    QString lastFilePath = settings.value("lastSavePath").toString();

    if (lastFilePath.isEmpty() || !QFile::exists(lastFilePath)) return;

    // 加载 UI 布局数据
    if (loadWidgets(lastFilePath))
    {
        loadSceneDatas(lastFilePath);
        loadBindDatas(lastFilePath);
    }
    else
    {
        qWarning() << "自动加载失败：" << lastFilePath;
        settings.remove("lastSavePath");
    }
}

// 加界面载文件
bool AppSetConfig::loadWidgets(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "配置文件不存在：" << filePath;
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) {
        qWarning() << "JSON格式错误：" << filePath;
        return false;
    }

    auto root = doc.object();

    // 取 config 对象
    if (!root.contains("config") || !root["config"].isObject()) {
        qWarning() << "JSON里没有 config 对象";
        return false;
    }

    auto config = root["config"].toObject();
    // 彻底销毁旧的面板控件
    for (QWidget* widget : m_panelMap.values()) {
        if (widget) {
            m_flowLayout->removeWidget(widget); // 从布局中移除
            widget->deleteLater();              // 延迟销毁对象（安全做法）
        }
    }

    // 彻底销毁旧的 LED 扩展控件
    for (QWidget* widget : m_ledMap.values()) {
        if (widget) {
            m_flowLayout->removeWidget(widget);
            widget->deleteLater();
        }
    }

    // 彻底销毁旧的继电器扩展控件
    for (QWidget* widget : m_relayMap.values()) {
        if (widget) {
            m_flowLayout->removeWidget(widget);
            widget->deleteLater();
        }
    }

    // 清空原有数据
    m_panelCount = 0;
    m_ledCount = 0;
    m_relayCount = 0;
    m_panelMap.clear();
    m_ledMap.clear();
    m_relayMap.clear();

    // panel
    for (const auto& val : config["panel"].toArray()) {
        if (m_panelCount >= MAX_PANEL) break;

        auto obj = val.toObject();
        PanelInfo_t p{};
        p.addr      = static_cast<uint8_t>(obj["id"].toInt());
        p.type    = static_cast<PanelType>(obj["type"].toInt());
        p.key_num = static_cast<uint8_t>(obj["key_num"].toInt());

        auto names = obj["key_name"].toArray();
        for (int k = 0; k < names.size() && k < 6; ++k)
            p.key_name[k] = names[k].toString();

        m_panelArray[m_panelCount] = p;
        if (auto widget = CreatePanelWidget(p)) {
            AddPanelToLayout(widget);
            m_panelMap.insert(p.addr, widget);
            m_panelCount++;
        }
    }

    // led_ex
    for (const auto& val : config["led_ex"].toArray()) {
        if (m_ledCount >= MAX_LED) break;
        auto obj = val.toObject();
        ExtendInfo_t led{};
        led.id = static_cast<uint8_t>(obj["id"].toInt());
        led.type = static_cast<ExtendType>(obj["type"].toInt());
        m_ledArray[m_ledCount++] = led;

        if (auto widget = CreateExtendWidget(led)) {
            AddPanelToLayout(widget);
            m_ledMap.insert(led.id, widget);
        }
    }

    // relay_ex
    for (const auto& val : config["relay_ex"].toArray()) {
        if (m_relayCount >= MAX_RELAY) break;
        auto obj = val.toObject();
        ExtendInfo_t relay{};
        relay.id = static_cast<uint8_t>(obj["id"].toInt());
        relay.type = static_cast<ExtendType>(obj["type"].toInt());
        m_relayArray[m_relayCount++] = relay;

        if (auto widget = CreateExtendWidget(relay)) {
            AddPanelToLayout(widget);
            m_relayMap.insert(relay.id, widget);
        }
    }

    return true;
}

// 保存场景数据
void AppSetConfig::saveSceneDatas(const QString &filePath)
{
    QFile file(filePath);
    QJsonObject root;

    // 读取原文件 JSON
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        if (doc.isObject()) root = doc.object();
    }

    // 获取 AppProtocolSetConfig 的数据
    config_data_t data = m_protocol_set_config->getAllConfigData();
    QJsonObject protocolObj;

    // panel
    QJsonArray panelArray;
    for (const auto &p : data.panel) {
        QJsonObject obj;
        obj["scene_id"]      = p.scene_id;
        obj["scene_name"]    = p.scene_name;
        obj["panel_addr"]    = p.panel_addr;
        obj["panel_type"]    = p.panel_type;
        obj["panel_key_num"] = p.panel_key_num;

        QJsonArray keyNames;
        for (const auto &name : p.panel_name) keyNames.append(name);
        obj["key_name"] = keyNames;

        QJsonArray keyEnable;
        for (bool b : p.key_enable) keyEnable.append(b);
        obj["key_enable"] = keyEnable;

        QJsonArray keyState;
        for (bool b : p.key_state) keyState.append(b);
        obj["key_state"] = keyState;
        panelArray.append(obj);
    }
    protocolObj["panel"] = panelArray;

    // led_ex
    QJsonArray ledArray;
    for (const auto &l : data.led_ex) {
        QJsonObject obj;
        obj["scene_id"]   = l.scene_id;
        obj["scene_name"] = l.scene_name;
        obj["led_addr"]   = l.led_addr;

        QJsonArray enabled;
        for (bool b : l.led_enable) enabled.append(b);
        obj["led_enable"] = enabled;

        QJsonArray values;
        for (int v : l.led_value) values.append(v);
        obj["led_value"] = values;

        ledArray.append(obj);
    }
    protocolObj["led_ex"] = ledArray;

    // relay_ex
    QJsonArray relayArray;
    for (const auto &l : data.relay_ex) {
        QJsonObject obj;
        obj["scene_id"]    = l.scene_id;
        obj["scene_name"]  = l.scene_name;
        obj["relay_addr"]  = l.relay_addr;

        QJsonArray enabled;
        for (bool b : l.relay_enable) enabled.append(b);
        obj["relay_enable"] = enabled;

        QJsonArray values;
        for (bool v : l.relay_state) values.append(v);
        obj["relay_state"] = values;

        relayArray.append(obj);
    }
    protocolObj["relay_ex"] = relayArray;


    // scene_data
    QJsonArray sceneArray;
    for (const auto &s : data.scene) {
        QJsonObject obj;
        obj["scene_name"] = s.scene_name;
        obj["scene_data"] = QString(s.scene_data.toHex());
        sceneArray.append(obj);
    }
    protocolObj["scene_data"] = sceneArray;
    root["protocol"] = protocolObj; // 放到顶层 protocol 对象下

    // 写回文件
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "saveProtocolData 保存成功到 protocol 对象";
    } else {
        qWarning() << "写入失败：" << file.errorString();
    }
}


bool AppSetConfig::loadSceneDatas(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开协议配置文件进行读取：" << filePath;
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) return false;
    QJsonObject root = doc.object();

    // 检查是否存在 protocol 节点
    if (!root.contains("protocol") || !root["protocol"].isObject()) {
        qWarning() << "JSON 中未发现 protocol 场景数据";
        return false;
    }

    QJsonObject protocolObj = root["protocol"].toObject();
    config_data_t data; // 准备装载数据的结构体

    // panel
    QJsonArray panelArray = protocolObj["panel"].toArray();
    for (const auto &val : panelArray) {
        QJsonObject obj = val.toObject();
        panel_save_t p;
        p.scene_id      = static_cast<uint8_t>(obj["scene_id"].toInt());
        p.scene_name    = obj["scene_name"].toString();
        p.panel_addr    = static_cast<uint8_t>(obj["panel_addr"].toInt());
        p.panel_type    = static_cast<uint8_t>(obj["panel_type"].toInt());
        p.panel_key_num = static_cast<uint8_t>(obj["panel_key_num"].toInt());

        // 还原按键别名数组 QString[6]
        QJsonArray names = obj["key_name"].toArray();
        for (int i = 0; i < names.size() && i < 6; ++i) {
            p.panel_name[i] = names[i].toString();
        }

        // 还原勾选状态 QVector<bool>
        QJsonArray keyEnable = obj["key_enable"].toArray();
        for (const auto &b : keyEnable) p.key_enable.append(b.toBool());

        QJsonArray keyState = obj["key_state"].toArray();
        for (const auto &b : keyState) p.key_state.append(b.toBool());

        data.panel.append(p);
    }

    // led_ex
    QJsonArray ledArray = protocolObj["led_ex"].toArray();
    for (const auto &val : ledArray) {
        QJsonObject obj = val.toObject();
        led_save_t l;
        l.scene_id   = static_cast<uint8_t>(obj["scene_id"].toInt());
        l.scene_name = obj["scene_name"].toString();
        l.led_addr   = static_cast<uint8_t>(obj["led_addr"].toInt());

        QJsonArray enabled = obj["led_enable"].toArray();
        for (const auto &b : enabled) l.led_enable.append(b.toBool());

        QJsonArray values = obj["led_value"].toArray();
        for (const auto &v : values) l.led_value.append(v.toInt());

        data.led_ex.append(l);
    }

    // relay_ex
    QJsonArray relayArray = protocolObj["relay_ex"].toArray();
    for (const auto &val : relayArray)
    {
        QJsonObject obj = val.toObject();
        relay_save_t r;
        r.scene_id   = static_cast<uint8_t>(obj["scene_id"].toInt());
        r.scene_name = obj["scene_name"].toString();
        r.relay_addr = static_cast<uint8_t>(obj["relay_addr"].toInt());

        QJsonArray enabled = obj["relay_enable"].toArray();
        for (const auto &b : enabled) r.relay_enable.append(b.toBool());

        QJsonArray state = obj["relay_state"].toArray();
        for (const auto &v : state) r.relay_state.append(v.toBool());

        data.relay_ex.append(r);
    }

    // scene_data
    QJsonArray sceneArray = protocolObj["scene_data"].toArray();
    for (const auto &val : sceneArray) {
        QJsonObject obj = val.toObject();
        scene_save_t s;

        // 关键点：将 Hex 字符串还原为 QByteArray
        s.scene_data = QByteArray::fromHex(obj["scene_data"].toString().toUtf8());
        s.scene_name = obj["scene_name"].toString();
        s.scene_id = s.scene_data[0];
        data.scene.append(s);
    }

    // 将数据塞回协议管理器
    if (m_protocol_set_config) {
        m_protocol_set_config->setAllConfigData(data);
        return true;
    }

    return false;
}

// 保存绑定信息
void AppSetConfig::saveBindDatas(const QString &filePath)
{
    QFile file(filePath);
    QJsonObject root;

    // 读取原文件内容,确保不覆盖 config 或其他 protocol 数据
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        root = QJsonDocument::fromJson(file.readAll()).object();
        file.close();
    }

    // 获取或创建 protocol 对象
    QJsonObject protocolObj = root["protocol"].toObject();

    // 准备绑定数据映射
    bind_data_t allBindData = m_protocol_set_config->getAllBindData();
    QJsonArray bindArray;
    for (const auto &b : allBindData.bind_data) {
        QJsonObject obj;
        obj["scene_name"] = b.scene_name;
        obj["bind_data"]  = QString(b.bind_data.toHex());
        bindArray.append(obj);
    }

    // 只更新 protocol 里的 scene_bind_data 字段
    protocolObj["scene_bind_data"] = bindArray;
    root["protocol"] = protocolObj;

    // 写回文件
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));
        file.close();
    }
}

// 加载绑定信息
bool AppSetConfig::loadBindDatas(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开配置文件进行读取：" << filePath;
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) return false;

    QJsonObject root = doc.object();

    // 先进入 protocol 层级
    if (!root.contains("protocol") || !root["protocol"].isObject()) {
        qWarning() << "JSON 中未找到 protocol 节点";
        return false;
    }
    QJsonObject protocolObj = root["protocol"].toObject();

    // 在 protocol 内部查找 scene_bind_data
    if (!protocolObj.contains("scene_bind_data") || !protocolObj["scene_bind_data"].isArray()) {
        qWarning() << "protocol 节点下未找到 scene_bind_data 数组";
        return false;
    }

    QJsonArray bindArray = protocolObj["scene_bind_data"].toArray();
    bind_data_t allBinds;

    // 解析数组内容
    for (const auto &val : bindArray) {
        QJsonObject obj = val.toObject();
        bind_save_t item;
        item.scene_name = obj["scene_name"].toString();
        // 将 Hex 字符串还原为 QByteArray
        item.bind_data  = QByteArray::fromHex(obj["bind_data"].toString().toUtf8());
        allBinds.bind_data.append(item);
    }

    // 同步到协议管理器
    if (m_protocol_set_config) {
        // 传递整个结构体
        m_protocol_set_config->setAllBindData(allBinds);
        qDebug() << "成功加载绑定信息，共" << allBinds.bind_data.size() << "条";
        return true;
    }

    return false;
}

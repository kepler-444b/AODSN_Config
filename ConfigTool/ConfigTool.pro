QT       += core gui serialport

RC_ICONS = resources/app.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    app/app_all_list.cpp \
    app/app_protocol_set_addr.cpp \
    app/app_protocol_set_config.cpp \
    app/app_protocol_set_net.cpp \
    app/app_sel_extend.cpp \
    app/app_sel_set_scene.cpp \
    app/app_set_net.cpp \
    flow/flowlayout.cpp \
    app/app_display.cpp \
    app/app_sel_panel.cpp \
    app/app_serial.cpp \
    app/app_set_addr.cpp \
    app/app_set_config.cpp \
    main.cpp \
    mainwindow.cpp \
    model/model_led_ex.cpp \
    model/model_panel_1key.cpp \
    model/model_panel_2key.cpp \
    model/model_panel_3key.cpp \
    model/model_panel_4key.cpp \
    model/model_panel_6key.cpp \
    model/model_relay_ex.cpp

HEADERS += \
    app/app_all_list.h \
    app/app_protocol_set_addr.h \
    app/app_protocol_set_config.h \
    app/app_protocol_set_net.h \
    app/app_sel_extend.h \
    app/app_sel_set_scene.h \
    app/app_set_net.h \
    flow/flowlayout.h \
    app/app_display.h \
    app/app_sel_panel.h \
    app/app_serial.h \
    app/app_set_addr.h \
    app/app_set_config.h \
    mainwindow.h \
    model/model_led_ex.h \
    model/model_panel_1key.h \
    model/model_panel_2key.h \
    model/model_panel_3key.h \
    model/model_panel_4key.h \
    model/model_panel_6key.h \
    model/model_relay_ex.h

FORMS += \
    app/app_all_list.ui \
    app/app_display.ui \
    app/app_sel_extend.ui \
    app/app_sel_panel.ui \
    app/app_sel_set_scene.ui \
    app/app_serial.ui \
    app/app_set_addr.ui \
    app/app_set_config.ui \
    app/app_set_net.ui \
    app/app_set_scene.ui \
    mainwindow.ui \
    model/model_led_ex.ui \
    model/model_panel_1key.ui \
    model/model_panel_2key.ui \
    model/model_panel_3key.ui \
    model/model_panel_4key.ui \
    model/model_panel_6key.ui \
    model/model_relay_ex.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/app_icons.qrc

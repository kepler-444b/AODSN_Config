/****************************************************************************
** Meta object code from reading C++ file 'app_protocol_set_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ConfigTool/app/app_protocol_set_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app_protocol_set_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppProtocolSetConfig_t {
    QByteArrayData data[50];
    char stringdata0[611];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppProtocolSetConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppProtocolSetConfig_t qt_meta_stringdata_AppProtocolSetConfig = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AppProtocolSetConfig"
QT_MOC_LITERAL(1, 21, 16), // "sceneListChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "QVector<scene_save_t>"
QT_MOC_LITERAL(4, 61, 4), // "data"
QT_MOC_LITERAL(5, 66, 15), // "bindListChanged"
QT_MOC_LITERAL(6, 82, 20), // "QVector<bind_save_t>"
QT_MOC_LITERAL(7, 103, 15), // "recv_scene_data"
QT_MOC_LITERAL(8, 119, 21), // "QVector<panel_data_t>"
QT_MOC_LITERAL(9, 141, 6), // "panels"
QT_MOC_LITERAL(10, 148, 19), // "QVector<led_data_t>"
QT_MOC_LITERAL(11, 168, 4), // "leds"
QT_MOC_LITERAL(12, 173, 21), // "QVector<relay_data_t>"
QT_MOC_LITERAL(13, 195, 6), // "relays"
QT_MOC_LITERAL(14, 202, 7), // "uint8_t"
QT_MOC_LITERAL(15, 210, 8), // "scene_id"
QT_MOC_LITERAL(16, 219, 4), // "name"
QT_MOC_LITERAL(17, 224, 5), // "bool&"
QT_MOC_LITERAL(18, 230, 7), // "success"
QT_MOC_LITERAL(19, 238, 14), // "recv_bind_data"
QT_MOC_LITERAL(20, 253, 9), // "panelAddr"
QT_MOC_LITERAL(21, 263, 8), // "keyIndex"
QT_MOC_LITERAL(22, 272, 7), // "sceneId"
QT_MOC_LITERAL(23, 280, 6), // "isOpen"
QT_MOC_LITERAL(24, 287, 14), // "bulidSceneData"
QT_MOC_LITERAL(25, 302, 13), // "buildBindData"
QT_MOC_LITERAL(26, 316, 4), // "addr"
QT_MOC_LITERAL(27, 321, 7), // "key_num"
QT_MOC_LITERAL(28, 329, 5), // "state"
QT_MOC_LITERAL(29, 335, 10), // "scene_name"
QT_MOC_LITERAL(30, 346, 15), // "printConfigData"
QT_MOC_LITERAL(31, 362, 11), // "deleteScene"
QT_MOC_LITERAL(32, 374, 10), // "deleteBind"
QT_MOC_LITERAL(33, 385, 11), // "bind_save_t"
QT_MOC_LITERAL(34, 397, 4), // "bind"
QT_MOC_LITERAL(35, 402, 16), // "getAllConfigData"
QT_MOC_LITERAL(36, 419, 13), // "config_data_t"
QT_MOC_LITERAL(37, 433, 14), // "getAllBindData"
QT_MOC_LITERAL(38, 448, 11), // "bind_data_t"
QT_MOC_LITERAL(39, 460, 22), // "getSceneConfigDataById"
QT_MOC_LITERAL(40, 483, 16), // "setAllConfigData"
QT_MOC_LITERAL(41, 500, 14), // "setAllBindData"
QT_MOC_LITERAL(42, 515, 5), // "binds"
QT_MOC_LITERAL(43, 521, 13), // "sendSceneData"
QT_MOC_LITERAL(44, 535, 12), // "sendBindData"
QT_MOC_LITERAL(45, 548, 18), // "sendClearSceneData"
QT_MOC_LITERAL(46, 567, 17), // "sendClearBindData"
QT_MOC_LITERAL(47, 585, 9), // "packFrame"
QT_MOC_LITERAL(48, 595, 7), // "payload"
QT_MOC_LITERAL(49, 603, 7) // "cmdType"

    },
    "AppProtocolSetConfig\0sceneListChanged\0"
    "\0QVector<scene_save_t>\0data\0bindListChanged\0"
    "QVector<bind_save_t>\0recv_scene_data\0"
    "QVector<panel_data_t>\0panels\0"
    "QVector<led_data_t>\0leds\0QVector<relay_data_t>\0"
    "relays\0uint8_t\0scene_id\0name\0bool&\0"
    "success\0recv_bind_data\0panelAddr\0"
    "keyIndex\0sceneId\0isOpen\0bulidSceneData\0"
    "buildBindData\0addr\0key_num\0state\0"
    "scene_name\0printConfigData\0deleteScene\0"
    "deleteBind\0bind_save_t\0bind\0"
    "getAllConfigData\0config_data_t\0"
    "getAllBindData\0bind_data_t\0"
    "getSceneConfigDataById\0setAllConfigData\0"
    "setAllBindData\0binds\0sendSceneData\0"
    "sendBindData\0sendClearSceneData\0"
    "sendClearBindData\0packFrame\0payload\0"
    "cmdType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppProtocolSetConfig[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       5,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    6,  115,    2, 0x0a /* Public */,
      19,    4,  128,    2, 0x0a /* Public */,
      24,    5,  137,    2, 0x0a /* Public */,
      25,    5,  148,    2, 0x0a /* Public */,
      30,    0,  159,    2, 0x0a /* Public */,
      31,    1,  160,    2, 0x0a /* Public */,
      32,    1,  163,    2, 0x0a /* Public */,
      35,    0,  166,    2, 0x0a /* Public */,
      37,    0,  167,    2, 0x0a /* Public */,
      39,    1,  168,    2, 0x0a /* Public */,
      40,    1,  171,    2, 0x0a /* Public */,
      41,    1,  174,    2, 0x0a /* Public */,
      43,    0,  177,    2, 0x0a /* Public */,
      44,    0,  178,    2, 0x0a /* Public */,
      45,    0,  179,    2, 0x0a /* Public */,
      46,    0,  180,    2, 0x0a /* Public */,
      47,    2,  181,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12, 0x80000000 | 14, QMetaType::QString, 0x80000000 | 17,    9,   11,   13,   15,   16,   18,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, 0x80000000 | 14, QMetaType::Bool,   20,   21,   22,   23,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12, 0x80000000 | 14, QMetaType::QString,    9,   11,   13,   15,   16,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, QMetaType::QString,   26,   27,   28,   15,   29,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 33,   34,
    0x80000000 | 36,
    0x80000000 | 38,
    0x80000000 | 36, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 36,    4,
    QMetaType::Void, 0x80000000 | 38,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray,   48,   49,

       0        // eod
};

void AppProtocolSetConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppProtocolSetConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sceneListChanged((*reinterpret_cast< const QVector<scene_save_t>(*)>(_a[1]))); break;
        case 1: _t->bindListChanged((*reinterpret_cast< const QVector<bind_save_t>(*)>(_a[1]))); break;
        case 2: _t->recv_scene_data((*reinterpret_cast< const QVector<panel_data_t>(*)>(_a[1])),(*reinterpret_cast< const QVector<led_data_t>(*)>(_a[2])),(*reinterpret_cast< const QVector<relay_data_t>(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 3: _t->recv_bind_data((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->bulidSceneData((*reinterpret_cast< const QVector<panel_data_t>(*)>(_a[1])),(*reinterpret_cast< const QVector<led_data_t>(*)>(_a[2])),(*reinterpret_cast< const QVector<relay_data_t>(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->buildBindData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 6: _t->printConfigData(); break;
        case 7: _t->deleteScene((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 8: _t->deleteBind((*reinterpret_cast< const bind_save_t(*)>(_a[1]))); break;
        case 9: { config_data_t _r = _t->getAllConfigData();
            if (_a[0]) *reinterpret_cast< config_data_t*>(_a[0]) = std::move(_r); }  break;
        case 10: { bind_data_t _r = _t->getAllBindData();
            if (_a[0]) *reinterpret_cast< bind_data_t*>(_a[0]) = std::move(_r); }  break;
        case 11: { config_data_t _r = _t->getSceneConfigDataById((*reinterpret_cast< uint8_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< config_data_t*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->setAllConfigData((*reinterpret_cast< const config_data_t(*)>(_a[1]))); break;
        case 13: _t->setAllBindData((*reinterpret_cast< const bind_data_t(*)>(_a[1]))); break;
        case 14: _t->sendSceneData(); break;
        case 15: _t->sendBindData(); break;
        case 16: _t->sendClearSceneData(); break;
        case 17: _t->sendClearBindData(); break;
        case 18: { QByteArray _r = _t->packFrame((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppProtocolSetConfig::*)(const QVector<scene_save_t> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppProtocolSetConfig::sceneListChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppProtocolSetConfig::*)(const QVector<bind_save_t> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppProtocolSetConfig::bindListChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppProtocolSetConfig::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppProtocolSetConfig.data,
    qt_meta_data_AppProtocolSetConfig,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppProtocolSetConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppProtocolSetConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppProtocolSetConfig.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppProtocolSetConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void AppProtocolSetConfig::sceneListChanged(const QVector<scene_save_t> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppProtocolSetConfig::bindListChanged(const QVector<bind_save_t> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

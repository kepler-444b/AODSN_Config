/****************************************************************************
** Meta object code from reading C++ file 'app_set_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ConfigTool/app/app_set_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app_set_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppSetConfig_t {
    QByteArrayData data[18];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppSetConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppSetConfig_t qt_meta_stringdata_AppSetConfig = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AppSetConfig"
QT_MOC_LITERAL(1, 13, 20), // "on_add_panel_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_add_extend_clicked"
QT_MOC_LITERAL(4, 57, 20), // "on_set_scene_clicked"
QT_MOC_LITERAL(5, 78, 12), // "create_scene"
QT_MOC_LITERAL(6, 91, 2), // "id"
QT_MOC_LITERAL(7, 94, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 116, 20), // "on_load_data_clicked"
QT_MOC_LITERAL(9, 137, 11), // "saveWidgets"
QT_MOC_LITERAL(10, 149, 8), // "filePath"
QT_MOC_LITERAL(11, 158, 11), // "loadWidgets"
QT_MOC_LITERAL(12, 170, 15), // "autoLoadAllData"
QT_MOC_LITERAL(13, 186, 14), // "saveSceneDatas"
QT_MOC_LITERAL(14, 201, 14), // "loadSceneDatas"
QT_MOC_LITERAL(15, 216, 13), // "saveBindDatas"
QT_MOC_LITERAL(16, 230, 13), // "loadBindDatas"
QT_MOC_LITERAL(17, 244, 20) // "on_save_data_clicked"

    },
    "AppSetConfig\0on_add_panel_clicked\0\0"
    "on_add_extend_clicked\0on_set_scene_clicked\0"
    "create_scene\0id\0on_pushButton_clicked\0"
    "on_load_data_clicked\0saveWidgets\0"
    "filePath\0loadWidgets\0autoLoadAllData\0"
    "saveSceneDatas\0loadSceneDatas\0"
    "saveBindDatas\0loadBindDatas\0"
    "on_save_data_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppSetConfig[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    1,   97,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    1,  102,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x28 /* Private | MethodCloned */,
      11,    1,  106,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x28 /* Private | MethodCloned */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    1,  114,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      16,    1,  120,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void AppSetConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppSetConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_add_panel_clicked(); break;
        case 1: _t->on_add_extend_clicked(); break;
        case 2: _t->on_set_scene_clicked(); break;
        case 3: _t->create_scene((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_load_data_clicked(); break;
        case 6: _t->saveWidgets((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->saveWidgets(); break;
        case 8: { bool _r = _t->loadWidgets((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->loadWidgets();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->autoLoadAllData(); break;
        case 11: _t->saveSceneDatas((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: { bool _r = _t->loadSceneDatas((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->saveBindDatas((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: { bool _r = _t->loadBindDatas((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->on_save_data_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppSetConfig::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AppSetConfig.data,
    qt_meta_data_AppSetConfig,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppSetConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppSetConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppSetConfig.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AppSetConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

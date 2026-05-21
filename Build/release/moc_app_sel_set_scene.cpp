/****************************************************************************
** Meta object code from reading C++ file 'app_sel_set_scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ConfigTool/app/app_sel_set_scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app_sel_set_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogSetScene_t {
    QByteArrayData data[17];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSetScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSetScene_t qt_meta_stringdata_DialogSetScene = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DialogSetScene"
QT_MOC_LITERAL(1, 15, 11), // "send_config"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "QVector<panel_data_t>"
QT_MOC_LITERAL(4, 50, 6), // "panels"
QT_MOC_LITERAL(5, 57, 19), // "QVector<led_data_t>"
QT_MOC_LITERAL(6, 77, 4), // "leds"
QT_MOC_LITERAL(7, 82, 21), // "QVector<relay_data_t>"
QT_MOC_LITERAL(8, 104, 6), // "relays"
QT_MOC_LITERAL(9, 111, 7), // "uint8_t"
QT_MOC_LITERAL(10, 119, 8), // "scene_id"
QT_MOC_LITERAL(11, 128, 4), // "name"
QT_MOC_LITERAL(12, 133, 5), // "bool&"
QT_MOC_LITERAL(13, 139, 7), // "success"
QT_MOC_LITERAL(14, 147, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(15, 171, 4), // "arg1"
QT_MOC_LITERAL(16, 176, 21) // "on_pushButton_clicked"

    },
    "DialogSetScene\0send_config\0\0"
    "QVector<panel_data_t>\0panels\0"
    "QVector<led_data_t>\0leds\0QVector<relay_data_t>\0"
    "relays\0uint8_t\0scene_id\0name\0bool&\0"
    "success\0on_spinBox_valueChanged\0arg1\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSetScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   42,    2, 0x08 /* Private */,
      16,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9, QMetaType::QString, 0x80000000 | 12,    4,    6,    8,   10,   11,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void DialogSetScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogSetScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_config((*reinterpret_cast< const QVector<panel_data_t>(*)>(_a[1])),(*reinterpret_cast< const QVector<led_data_t>(*)>(_a[2])),(*reinterpret_cast< const QVector<relay_data_t>(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogSetScene::*)(const QVector<panel_data_t> & , const QVector<led_data_t> & , const QVector<relay_data_t> & , uint8_t , QString , bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSetScene::send_config)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogSetScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogSetScene.data,
    qt_meta_data_DialogSetScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogSetScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSetScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSetScene.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogSetScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DialogSetScene::send_config(const QVector<panel_data_t> & _t1, const QVector<led_data_t> & _t2, const QVector<relay_data_t> & _t3, uint8_t _t4, QString _t5, bool & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

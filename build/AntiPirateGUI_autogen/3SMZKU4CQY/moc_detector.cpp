/****************************************************************************
** Meta object code from reading C++ file 'detector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Source/Detector/detector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Detector_t {
    QByteArrayData data[14];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Detector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Detector_t qt_meta_stringdata_Detector = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Detector"
QT_MOC_LITERAL(1, 9, 15), // "SendDetectFrame"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 34, 5), // "frame"
QT_MOC_LITERAL(5, 40, 13), // "SendDetectRes"
QT_MOC_LITERAL(6, 54, 16), // "QList<DetectRes>"
QT_MOC_LITERAL(7, 71, 7), // "resList"
QT_MOC_LITERAL(8, 79, 15), // "SendProcessTime"
QT_MOC_LITERAL(9, 95, 1), // "t"
QT_MOC_LITERAL(10, 97, 12), // "SendPerfInfo"
QT_MOC_LITERAL(11, 110, 14), // "inference_time"
QT_MOC_LITERAL(12, 125, 12), // "compute_time"
QT_MOC_LITERAL(13, 138, 14) // "SendStopDetect"

    },
    "Detector\0SendDetectFrame\0\0cv::Mat\0"
    "frame\0SendDetectRes\0QList<DetectRes>\0"
    "resList\0SendProcessTime\0t\0SendPerfInfo\0"
    "inference_time\0compute_time\0SendStopDetect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Detector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       8,    1,   45,    2, 0x06 /* Public */,
      10,    2,   48,    2, 0x06 /* Public */,
      13,    0,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   11,   12,
    QMetaType::Void,

       0        // eod
};

void Detector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Detector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendDetectFrame((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 1: _t->SendDetectRes((*reinterpret_cast< const QList<DetectRes>(*)>(_a[1]))); break;
        case 2: _t->SendProcessTime((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->SendPerfInfo((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 4: _t->SendStopDetect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Detector::*)(const cv::Mat & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Detector::SendDetectFrame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Detector::*)(const QList<DetectRes> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Detector::SendDetectRes)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Detector::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Detector::SendProcessTime)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Detector::*)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Detector::SendPerfInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Detector::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Detector::SendStopDetect)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Detector::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Detector.data,
    qt_meta_data_Detector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Detector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Detector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Detector.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Detector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Detector::SendDetectFrame(const cv::Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Detector::SendDetectRes(const QList<DetectRes> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Detector::SendProcessTime(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Detector::SendPerfInfo(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Detector::SendStopDetect()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

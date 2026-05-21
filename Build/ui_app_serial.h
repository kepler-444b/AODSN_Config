/********************************************************************************
** Form generated from reading UI file 'app_serial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SERIAL_H
#define UI_APP_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSerial
{
public:
    QGridLayout *gridLayout;
    QLabel *label_serial;
    QComboBox *com;
    QPushButton *switch_com;
    QLabel *label_baudrate;
    QComboBox *baudrate;
    QPushButton *refresh_com;
    QCheckBox *auto_check;
    QComboBox *recv_timeout;

    void setupUi(QWidget *AppSerial)
    {
        if (AppSerial->objectName().isEmpty())
            AppSerial->setObjectName(QString::fromUtf8("AppSerial"));
        AppSerial->resize(200, 100);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AppSerial->sizePolicy().hasHeightForWidth());
        AppSerial->setSizePolicy(sizePolicy);
        AppSerial->setMinimumSize(QSize(200, 100));
        AppSerial->setMaximumSize(QSize(200, 100));
        AppSerial->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(AppSerial);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_serial = new QLabel(AppSerial);
        label_serial->setObjectName(QString::fromUtf8("label_serial"));

        gridLayout->addWidget(label_serial, 0, 0, 1, 1);

        com = new QComboBox(AppSerial);
        com->setObjectName(QString::fromUtf8("com"));

        gridLayout->addWidget(com, 0, 1, 1, 1);

        switch_com = new QPushButton(AppSerial);
        switch_com->setObjectName(QString::fromUtf8("switch_com"));

        gridLayout->addWidget(switch_com, 0, 2, 1, 1);

        label_baudrate = new QLabel(AppSerial);
        label_baudrate->setObjectName(QString::fromUtf8("label_baudrate"));

        gridLayout->addWidget(label_baudrate, 1, 0, 1, 1);

        baudrate = new QComboBox(AppSerial);
        baudrate->setObjectName(QString::fromUtf8("baudrate"));

        gridLayout->addWidget(baudrate, 1, 1, 1, 1);

        refresh_com = new QPushButton(AppSerial);
        refresh_com->setObjectName(QString::fromUtf8("refresh_com"));

        gridLayout->addWidget(refresh_com, 1, 2, 1, 1);

        auto_check = new QCheckBox(AppSerial);
        auto_check->setObjectName(QString::fromUtf8("auto_check"));

        gridLayout->addWidget(auto_check, 2, 0, 1, 2);

        recv_timeout = new QComboBox(AppSerial);
        recv_timeout->setObjectName(QString::fromUtf8("recv_timeout"));

        gridLayout->addWidget(recv_timeout, 2, 2, 1, 1);


        retranslateUi(AppSerial);

        QMetaObject::connectSlotsByName(AppSerial);
    } // setupUi

    void retranslateUi(QWidget *AppSerial)
    {
        AppSerial->setWindowTitle(QCoreApplication::translate("AppSerial", "Form", nullptr));
        label_serial->setText(QCoreApplication::translate("AppSerial", "\347\253\257\345\217\243", nullptr));
        switch_com->setText(QCoreApplication::translate("AppSerial", "\346\211\223\345\274\200", nullptr));
        label_baudrate->setText(QCoreApplication::translate("AppSerial", "\346\263\242\347\211\271\347\216\207", nullptr));
        refresh_com->setText(QCoreApplication::translate("AppSerial", "\345\210\267\346\226\260", nullptr));
        auto_check->setText(QCoreApplication::translate("AppSerial", "\350\207\252\345\212\250\346\226\255\345\270\247 ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSerial: public Ui_AppSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SERIAL_H

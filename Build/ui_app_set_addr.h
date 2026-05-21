/********************************************************************************
** Form generated from reading UI file 'app_set_addr.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SET_ADDR_H
#define UI_APP_SET_ADDR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSetAddr
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *AppSetAddr)
    {
        if (AppSetAddr->objectName().isEmpty())
            AppSetAddr->setObjectName(QString::fromUtf8("AppSetAddr"));
        AppSetAddr->resize(221, 142);
        AppSetAddr->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    font-size: 16px;\n"
"    height: 35px;\n"
"}"));
        gridLayout = new QGridLayout(AppSetAddr);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(AppSetAddr);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(AppSetAddr);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(0, 0));
        spinBox->setMaximumSize(QSize(16777215, 36));
        spinBox->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        pushButton = new QPushButton(AppSetAddr);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(72, 36));
        pushButton->setMaximumSize(QSize(36, 72));
        pushButton->setIconSize(QSize(16, 32));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        label_2 = new QLabel(AppSetAddr);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);


        retranslateUi(AppSetAddr);

        QMetaObject::connectSlotsByName(AppSetAddr);
    } // setupUi

    void retranslateUi(QWidget *AppSetAddr)
    {
        AppSetAddr->setWindowTitle(QCoreApplication::translate("AppSetAddr", "Form", nullptr));
        label->setText(QCoreApplication::translate("AppSetAddr", "\351\235\242\346\235\277\345\234\260\345\235\200", nullptr));
        pushButton->setText(QCoreApplication::translate("AppSetAddr", "\345\234\260\345\235\200\347\276\244\345\217\221", nullptr));
        label_2->setText(QCoreApplication::translate("AppSetAddr", "\345\215\225\345\217\221\345\234\260\345\235\200,\350\257\267\351\225\277\346\214\211\351\235\242\346\235\2773\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSetAddr: public Ui_AppSetAddr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SET_ADDR_H

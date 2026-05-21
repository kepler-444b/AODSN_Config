/********************************************************************************
** Form generated from reading UI file 'app_sel_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SEL_PANEL_H
#define UI_APP_SEL_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogPanel
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *sel_dev;
    QRadioButton *panel;
    QRadioButton *knob;
    QGroupBox *sel_key_num;
    QRadioButton *key_1;
    QRadioButton *key_2;
    QRadioButton *key_3;
    QRadioButton *key_4;
    QRadioButton *key_6;
    QLabel *label;
    QSpinBox *set_addr;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DialogPanel)
    {
        if (DialogPanel->objectName().isEmpty())
            DialogPanel->setObjectName(QString::fromUtf8("DialogPanel"));
        DialogPanel->resize(200, 250);
        DialogPanel->setMinimumSize(QSize(200, 250));
        DialogPanel->setMaximumSize(QSize(200, 250));
        gridLayout_3 = new QGridLayout(DialogPanel);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sel_dev = new QGroupBox(DialogPanel);
        sel_dev->setObjectName(QString::fromUtf8("sel_dev"));
        sel_dev->setMinimumSize(QSize(180, 60));
        sel_dev->setMaximumSize(QSize(180, 60));
        sel_dev->setStyleSheet(QString::fromUtf8(""));
        panel = new QRadioButton(sel_dev);
        panel->setObjectName(QString::fromUtf8("panel"));
        panel->setGeometry(QRect(10, 28, 71, 16));
        knob = new QRadioButton(sel_dev);
        knob->setObjectName(QString::fromUtf8("knob"));
        knob->setGeometry(QRect(93, 28, 71, 16));

        gridLayout->addWidget(sel_dev, 0, 0, 1, 1);

        sel_key_num = new QGroupBox(DialogPanel);
        sel_key_num->setObjectName(QString::fromUtf8("sel_key_num"));
        sel_key_num->setMinimumSize(QSize(180, 80));
        sel_key_num->setMaximumSize(QSize(180, 80));
        key_1 = new QRadioButton(sel_key_num);
        key_1->setObjectName(QString::fromUtf8("key_1"));
        key_1->setGeometry(QRect(10, 22, 47, 16));
        key_2 = new QRadioButton(sel_key_num);
        key_2->setObjectName(QString::fromUtf8("key_2"));
        key_2->setGeometry(QRect(63, 22, 47, 16));
        key_3 = new QRadioButton(sel_key_num);
        key_3->setObjectName(QString::fromUtf8("key_3"));
        key_3->setGeometry(QRect(116, 22, 47, 16));
        key_4 = new QRadioButton(sel_key_num);
        key_4->setObjectName(QString::fromUtf8("key_4"));
        key_4->setGeometry(QRect(10, 44, 47, 16));
        key_6 = new QRadioButton(sel_key_num);
        key_6->setObjectName(QString::fromUtf8("key_6"));
        key_6->setGeometry(QRect(63, 44, 47, 16));

        gridLayout->addWidget(sel_key_num, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        label = new QLabel(DialogPanel);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        set_addr = new QSpinBox(DialogPanel);
        set_addr->setObjectName(QString::fromUtf8("set_addr"));
        set_addr->setMinimumSize(QSize(50, 0));
        set_addr->setMaximum(99);

        gridLayout_2->addWidget(set_addr, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton = new QPushButton(DialogPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 2, 1, 1);


        retranslateUi(DialogPanel);

        QMetaObject::connectSlotsByName(DialogPanel);
    } // setupUi

    void retranslateUi(QDialog *DialogPanel)
    {
        DialogPanel->setWindowTitle(QCoreApplication::translate("DialogPanel", "Dialog", nullptr));
        sel_dev->setTitle(QCoreApplication::translate("DialogPanel", "\351\200\211\346\213\251\351\235\242\346\235\277\347\261\273\345\236\213", nullptr));
        panel->setText(QCoreApplication::translate("DialogPanel", "\347\201\257\346\216\247\351\235\242\346\235\277", nullptr));
        knob->setText(QCoreApplication::translate("DialogPanel", "\346\227\213\351\222\256\351\235\242\346\235\277", nullptr));
        sel_key_num->setTitle(QCoreApplication::translate("DialogPanel", "\351\200\211\346\213\251\346\214\211\351\224\256\344\270\252\346\225\260", nullptr));
        key_1->setText(QCoreApplication::translate("DialogPanel", "1key", nullptr));
        key_2->setText(QCoreApplication::translate("DialogPanel", "2key", nullptr));
        key_3->setText(QCoreApplication::translate("DialogPanel", "3key", nullptr));
        key_4->setText(QCoreApplication::translate("DialogPanel", "4key", nullptr));
        key_6->setText(QCoreApplication::translate("DialogPanel", "6key", nullptr));
        label->setText(QCoreApplication::translate("DialogPanel", "\350\256\276\345\244\207\345\234\260\345\235\200", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogPanel", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPanel: public Ui_DialogPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SEL_PANEL_H

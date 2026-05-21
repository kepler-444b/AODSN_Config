/********************************************************************************
** Form generated from reading UI file 'app_sel_set_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SEL_SET_SCENE_H
#define UI_APP_SEL_SET_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetScene
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *scene_name;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *sel_panel;
    QLabel *label_3;
    QScrollArea *scrollArea_led;
    QWidget *sel_led;
    QLabel *label_4;
    QScrollArea *scrollArea_relay;
    QWidget *sel_relay;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogSetScene)
    {
        if (DialogSetScene->objectName().isEmpty())
            DialogSetScene->setObjectName(QString::fromUtf8("DialogSetScene"));
        DialogSetScene->resize(700, 850);
        DialogSetScene->setMinimumSize(QSize(700, 850));
        DialogSetScene->setMaximumSize(QSize(700, 850));
        gridLayout = new QGridLayout(DialogSetScene);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogSetScene);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(DialogSetScene);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(DialogSetScene);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        scene_name = new QLineEdit(DialogSetScene);
        scene_name->setObjectName(QString::fromUtf8("scene_name"));

        horizontalLayout_2->addWidget(scene_name);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(465, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_2 = new QLabel(DialogSetScene);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        scrollArea = new QScrollArea(DialogSetScene);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(680, 300));
        scrollArea->setMaximumSize(QSize(680, 300));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        sel_panel = new QWidget();
        sel_panel->setObjectName(QString::fromUtf8("sel_panel"));
        sel_panel->setGeometry(QRect(0, 0, 676, 296));
        scrollArea->setWidget(sel_panel);

        gridLayout->addWidget(scrollArea, 2, 0, 1, 4);

        label_3 = new QLabel(DialogSetScene);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 2);

        scrollArea_led = new QScrollArea(DialogSetScene);
        scrollArea_led->setObjectName(QString::fromUtf8("scrollArea_led"));
        scrollArea_led->setMinimumSize(QSize(680, 200));
        scrollArea_led->setMaximumSize(QSize(680, 200));
        scrollArea_led->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"}"));
        scrollArea_led->setWidgetResizable(true);
        sel_led = new QWidget();
        sel_led->setObjectName(QString::fromUtf8("sel_led"));
        sel_led->setGeometry(QRect(0, 0, 676, 196));
        scrollArea_led->setWidget(sel_led);

        gridLayout->addWidget(scrollArea_led, 4, 0, 1, 4);

        label_4 = new QLabel(DialogSetScene);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 2);

        scrollArea_relay = new QScrollArea(DialogSetScene);
        scrollArea_relay->setObjectName(QString::fromUtf8("scrollArea_relay"));
        scrollArea_relay->setMinimumSize(QSize(680, 200));
        scrollArea_relay->setMaximumSize(QSize(680, 200));
        scrollArea_relay->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"}"));
        scrollArea_relay->setWidgetResizable(true);
        sel_relay = new QWidget();
        sel_relay->setObjectName(QString::fromUtf8("sel_relay"));
        sel_relay->setGeometry(QRect(0, 0, 676, 196));
        scrollArea_relay->setWidget(sel_relay);

        gridLayout->addWidget(scrollArea_relay, 6, 0, 1, 4);

        pushButton = new QPushButton(DialogSetScene);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(100, 25));
        pushButton->setMaximumSize(QSize(100, 25));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pushButton, 7, 2, 1, 1);


        retranslateUi(DialogSetScene);

        QMetaObject::connectSlotsByName(DialogSetScene);
    } // setupUi

    void retranslateUi(QDialog *DialogSetScene)
    {
        DialogSetScene->setWindowTitle(QCoreApplication::translate("DialogSetScene", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogSetScene", "\345\234\272\346\231\257\347\274\226\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("DialogSetScene", "\345\234\272\346\231\257\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSetScene", "\350\256\276\347\275\256\351\235\242\347\212\266\346\200\201", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSetScene", "\350\256\276\347\275\256LED\346\211\251\345\261\225\347\212\266\346\200\201", nullptr));
        label_4->setText(QCoreApplication::translate("DialogSetScene", "\350\256\276\347\275\256\347\273\247\347\224\265\345\231\250\346\211\251\345\261\225\347\212\266\346\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogSetScene", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetScene: public Ui_DialogSetScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SEL_SET_SCENE_H

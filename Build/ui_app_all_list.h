/********************************************************************************
** Form generated from reading UI file 'app_all_list.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_ALL_LIST_H
#define UI_APP_ALL_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppAllList
{
public:
    QGridLayout *gridLayout;
    QLabel *scene_label;
    QScrollArea *scrollArea;
    QWidget *scene_list;
    QPushButton *send_bind;
    QLabel *bind_label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea_2;
    QWidget *bind_list;
    QPushButton *send_scene;
    QPushButton *clear_scene;
    QPushButton *clear_bind;

    void setupUi(QWidget *AppAllList)
    {
        if (AppAllList->objectName().isEmpty())
            AppAllList->setObjectName(QString::fromUtf8("AppAllList"));
        AppAllList->resize(420, 700);
        AppAllList->setMinimumSize(QSize(420, 700));
        gridLayout = new QGridLayout(AppAllList);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scene_label = new QLabel(AppAllList);
        scene_label->setObjectName(QString::fromUtf8("scene_label"));

        gridLayout->addWidget(scene_label, 0, 0, 1, 1);

        scrollArea = new QScrollArea(AppAllList);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(400, 300));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"} "));
        scrollArea->setWidgetResizable(true);
        scene_list = new QWidget();
        scene_list->setObjectName(QString::fromUtf8("scene_list"));
        scene_list->setGeometry(QRect(0, 0, 398, 320));
        scene_list->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidget(scene_list);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 6);

        send_bind = new QPushButton(AppAllList);
        send_bind->setObjectName(QString::fromUtf8("send_bind"));

        gridLayout->addWidget(send_bind, 2, 5, 1, 1);

        bind_label = new QLabel(AppAllList);
        bind_label->setObjectName(QString::fromUtf8("bind_label"));

        gridLayout->addWidget(bind_label, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 2);

        scrollArea_2 = new QScrollArea(AppAllList);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(400, 300));
        scrollArea_2->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_2->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"} "));
        scrollArea_2->setWidgetResizable(true);
        bind_list = new QWidget();
        bind_list->setObjectName(QString::fromUtf8("bind_list"));
        bind_list->setGeometry(QRect(0, 0, 398, 296));
        bind_list->setStyleSheet(QString::fromUtf8(""));
        scrollArea_2->setWidget(bind_list);

        gridLayout->addWidget(scrollArea_2, 3, 0, 2, 6);

        send_scene = new QPushButton(AppAllList);
        send_scene->setObjectName(QString::fromUtf8("send_scene"));

        gridLayout->addWidget(send_scene, 0, 4, 1, 2);

        clear_scene = new QPushButton(AppAllList);
        clear_scene->setObjectName(QString::fromUtf8("clear_scene"));

        gridLayout->addWidget(clear_scene, 0, 1, 1, 1);

        clear_bind = new QPushButton(AppAllList);
        clear_bind->setObjectName(QString::fromUtf8("clear_bind"));

        gridLayout->addWidget(clear_bind, 2, 1, 1, 2);


        retranslateUi(AppAllList);

        QMetaObject::connectSlotsByName(AppAllList);
    } // setupUi

    void retranslateUi(QWidget *AppAllList)
    {
        AppAllList->setWindowTitle(QCoreApplication::translate("AppAllList", "Form", nullptr));
        scene_label->setText(QCoreApplication::translate("AppAllList", "\345\234\272\346\231\257\345\210\227\350\241\250", nullptr));
        send_bind->setText(QCoreApplication::translate("AppAllList", "\344\270\213\345\217\221\347\273\221\345\256\232", nullptr));
        bind_label->setText(QCoreApplication::translate("AppAllList", "\347\273\221\345\256\232\345\210\227\350\241\250", nullptr));
        send_scene->setText(QCoreApplication::translate("AppAllList", "\344\270\213\345\217\221\345\234\272\346\231\257", nullptr));
        clear_scene->setText(QCoreApplication::translate("AppAllList", "\346\270\205\347\251\272\350\256\276\345\244\207\345\234\272\346\231\257", nullptr));
        clear_bind->setText(QCoreApplication::translate("AppAllList", "\346\270\205\347\251\272\350\256\276\345\244\207\347\273\221\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppAllList: public Ui_AppAllList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_ALL_LIST_H

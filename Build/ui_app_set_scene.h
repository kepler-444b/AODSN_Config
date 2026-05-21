/********************************************************************************
** Form generated from reading UI file 'app_set_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SET_SCENE_H
#define UI_APP_SET_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSetScene
{
public:
    QPushButton *pushButton;
    QSpinBox *set_scene_id;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *AppSetScene)
    {
        if (AppSetScene->objectName().isEmpty())
            AppSetScene->setObjectName(QString::fromUtf8("AppSetScene"));
        AppSetScene->resize(400, 300);
        pushButton = new QPushButton(AppSetScene);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 177, 176, 23));
        set_scene_id = new QSpinBox(AppSetScene);
        set_scene_id->setObjectName(QString::fromUtf8("set_scene_id"));
        set_scene_id->setGeometry(QRect(100, 10, 85, 20));
        label = new QLabel(AppSetScene);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 10, 85, 20));
        scrollArea = new QScrollArea(AppSetScene);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(70, 60, 120, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 78));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(AppSetScene);

        QMetaObject::connectSlotsByName(AppSetScene);
    } // setupUi

    void retranslateUi(QDialog *AppSetScene)
    {
        AppSetScene->setWindowTitle(QCoreApplication::translate("AppSetScene", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("AppSetScene", "\347\241\256\350\256\244", nullptr));
        label->setText(QCoreApplication::translate("AppSetScene", "\345\234\272\346\231\257ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSetScene: public Ui_AppSetScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SET_SCENE_H

/********************************************************************************
** Form generated from reading UI file 'app_set_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_SET_CONFIG_H
#define UI_APP_SET_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSetConfig
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *load_data;
    QPushButton *save_data;
    QVBoxLayout *verticalLayout;
    QPushButton *add_panel;
    QPushButton *add_extend;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *set_scene;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *AppSetConfig)
    {
        if (AppSetConfig->objectName().isEmpty())
            AppSetConfig->setObjectName(QString::fromUtf8("AppSetConfig"));
        AppSetConfig->resize(860, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AppSetConfig->sizePolicy().hasHeightForWidth());
        AppSetConfig->setSizePolicy(sizePolicy);
        AppSetConfig->setMinimumSize(QSize(860, 600));
        AppSetConfig->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(AppSetConfig);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        load_data = new QPushButton(AppSetConfig);
        load_data->setObjectName(QString::fromUtf8("load_data"));

        verticalLayout_2->addWidget(load_data);

        save_data = new QPushButton(AppSetConfig);
        save_data->setObjectName(QString::fromUtf8("save_data"));

        verticalLayout_2->addWidget(save_data);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        add_panel = new QPushButton(AppSetConfig);
        add_panel->setObjectName(QString::fromUtf8("add_panel"));

        verticalLayout->addWidget(add_panel);

        add_extend = new QPushButton(AppSetConfig);
        add_extend->setObjectName(QString::fromUtf8("add_extend"));

        verticalLayout->addWidget(add_extend);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(590, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        set_scene = new QPushButton(AppSetConfig);
        set_scene->setObjectName(QString::fromUtf8("set_scene"));

        verticalLayout_3->addWidget(set_scene);

        pushButton = new QPushButton(AppSetConfig);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout_3, 0, 3, 1, 1);

        scrollArea = new QScrollArea(AppSetConfig);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(840, 524));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 1px solid #bdbdbd;\n"
"    border-radius: 4px;\n"
"    padding: 1px;\n"
"} "));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 838, 520));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 4);


        retranslateUi(AppSetConfig);

        QMetaObject::connectSlotsByName(AppSetConfig);
    } // setupUi

    void retranslateUi(QWidget *AppSetConfig)
    {
        AppSetConfig->setWindowTitle(QCoreApplication::translate("AppSetConfig", "Form", nullptr));
        load_data->setText(QCoreApplication::translate("AppSetConfig", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        save_data->setText(QCoreApplication::translate("AppSetConfig", "\345\257\274\345\205\245\351\205\215\347\275\256", nullptr));
        add_panel->setText(QCoreApplication::translate("AppSetConfig", "\346\267\273\345\212\240\351\235\242\346\235\277", nullptr));
        add_extend->setText(QCoreApplication::translate("AppSetConfig", "\346\267\273\345\212\240\346\211\251\345\261\225", nullptr));
        set_scene->setText(QCoreApplication::translate("AppSetConfig", "\345\210\233\345\273\272\351\205\215\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("AppSetConfig", "\351\205\215\347\275\256\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSetConfig: public Ui_AppSetConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_SET_CONFIG_H

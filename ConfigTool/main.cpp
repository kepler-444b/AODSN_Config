#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QFont>

int main(int argc, char *argv[])
{
    // 启用高 DPI 缩放和图标缩放
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);

    // 获取主屏幕的逻辑 DPI(标准 DPI 为 96)
    qreal dpi = a.primaryScreen()->logicalDotsPerInch();

    // 调整全局字体大小,按 DPI 缩放
    QFont font = a.font();
    font.setPointSizeF(font.pointSizeF() * dpi / 96.0); // 自动放大字体
    a.setFont(font);

    // 创建主窗口并显示
    MainWindow w;
    w.show();

    return a.exec();
}

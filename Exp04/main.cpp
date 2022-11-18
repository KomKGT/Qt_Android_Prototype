#include "mainwindow.h"

#include <QApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QQuickView view;
    qmlRegisterType<MainWindow>("Speed", 1, 0, "Speed"); // 1,0 คือ version 1.0
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    return a.exec();
}

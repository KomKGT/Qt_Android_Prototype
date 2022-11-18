#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->speedSlider,SIGNAL(valueChanged(int)),this,SIGNAL(speedChanged(int)));
    QQuickView view;

    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QQmlEngine engine;
    QQmlComponent     component(&engine,QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = component.create();
    QVariant speeds=100;
    QVariant returnedValue;
    QMetaObject::invokeMethod(object,"speedNeedleValue",
                               Q_RETURN_ARG(QVariant, returnedValue),
                               Q_ARG(QVariant, speeds));
     qDebug() << "From QML"<< returnedValue.toString();
}

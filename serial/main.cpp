#include "mainwindow.h"
#include "login.h"
#include "homelayout.h"
#include "alertwidget.h"
#include <QApplication>
#include "QDialog"
#include "qdialog.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    /////////////////////////Window//////////////////////////
    //MainWindow w;
    //w.show();

    login log;
    log.show();
    //log.setWindowFlags(Qt::Window);
    //log.showFullScreen();

    //homeLayout home;
    //home.show();

    //AlertWidget alert;
    //alert.show();

    /////////////////////////Animation///////////////////////
    QPropertyAnimation animation(&log, "rot1");
    animation.setDuration(1000);
    animation.setStartValue(0.0);
    animation.setEndValue(90.0);
    animation.start();

    return a.exec();
}

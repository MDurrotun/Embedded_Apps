#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSerialPort"              //to run with serial port
#include "QDebug"                   //to run with console
#include "QNetworkAccessManager"    //to make request
#include "QNetworkReply"            //to handle replies
#include "QPixmap"                  //to work with image
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QTimer>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray mWholeData;//var member this is our buffer
    QNetworkAccessManager *man = new QNetworkAccessManager;
    QString myURL = "https://99designs-start-attachments.imgix.net/alchemy-pictures/2016%2F02%2F22%2F04%2F24%2F31%2Fb7bd820a-ecc0-4170-8f4e-3db2e73b0f4a%2F550250_artsigma.png?auto=format&ch=Width%2CDPR&w=250&h=250";
    QTimer *timer;

private slots:
    void serialReceived();
    void downloadFinished(QNetworkReply*);
    void replyFinished(QNetworkReply*);
    void dateTime();
    void animation();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_PushButtonHome_clicked();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionReboot_triggered();
};

#endif // MAINWINDOW_H

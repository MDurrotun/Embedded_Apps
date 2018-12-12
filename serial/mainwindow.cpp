#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "homelayout.h"
#include "QMessageBox"
#include "QProcess"
#include "QPropertyAnimation"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(300,50,800,600);
    timer = new QTimer(this);

    //////////////////////////Serial Port///////////////////
    serial = new QSerialPort(this);
    serial->setPortName("ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    //serial->setReadBufferSize(37);
    serial->write("OK");

    animation();

    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));
    connect(timer,SIGNAL(timeout()), this,SLOT(dateTime()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::animation(){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->PushButtonHome, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(QRect(0, 0, 0, 0));
    animation->setEndValue(ui->PushButtonHome->geometry());
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MainWindow::dateTime(){
    //qDebug() << "Update";
    //QTime time = QTime::currentTime();
    //QDate date = QDate::currentDate();
    //QString time_text = time.toString(" hh : mm : ss ");
    //QString date_text = date.toString("");


    //QDateTime dateTime = QDateTime::currentDateTime();
    //QString text_dateTime = dateTime.toString(" dddd, d MMMM yyyy hh:mm:ss ");

    QLocale locale(QLocale("Indonesia"));
    QDateTime date = QDateTime::currentDateTime();
    QString text_dateTime  = locale.toString(date);

    //ui->label_4->setText(QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd hh:mm:ss t")+"\n"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss t"));
    ui->label_4->setText(text_dateTime);
}

void MainWindow::serialReceived()
{
     mWholeData.append(serial->readAll());
     //ui->label->setText(mWholeData);
     ui->textEdit->setText(mWholeData);
     qDebug() << mWholeData;
}

/*void MainWindow::serialReceived(){
        receivedData.append(serial->readAll());
        if(receivedData.count() >= 37) {
            ui->label->setText(receivedData);
            ui->textEdit->setText(receivedData);
            //qDebug()<<"NumberOfBytesToRead..."+ QString::number(NumberOfBytesToRead)+" "+receivedData;
            serial->flush();
        }
}*/

void MainWindow::downloadFinished(QNetworkReply *reply){
    QPixmap pix;
    pix.loadFromData(reply->readAll());
    ui->label_2->setPixmap(pix);
}

/*void MainWindow::replyFinished(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    QString str(data);
    ui->label_2->setText("LOADED");
}*/

void MainWindow::replyFinished(QNetworkReply *reply){
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *file = new QFile("/home/durr/Documents/downloaded.txt");
        if(file->open(QFile::Append))
        {
            file->write(reply->readAll());
            ui->label_3->setText("https:// has been saved successfully on your Documents" );
            file->flush();
            file->close();
        }
        delete file;
    }
    reply->deleteLater();
}

void MainWindow::on_pushButton_clicked()
{
    ////////////////////////HTTP Request for downloading the Picture/////////////////////
    const QUrl url = QUrl(myURL);
    QNetworkRequest request(url);
    man->get(request);
    connect(man, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
    //connect(man, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
}

void MainWindow::on_pushButton_2_clicked()
{
    /////////////////////////HTTP Request for downloading the URL////////////////////////
    man->get(QNetworkRequest(QUrl("https://www.google.com/")));
    connect(man, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));   
}

void MainWindow::on_PushButtonHome_clicked()
{
    hide();
    homeLayout *homeUI = new homeLayout;
    homeUI->show();
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this,"Tittle","New");
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox::information(this,"Tittle","Open");
}

void MainWindow::on_actionReboot_triggered()
{
    QProcess::startDetached("reboot");
}

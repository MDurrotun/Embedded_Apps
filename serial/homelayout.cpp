#include "homelayout.h"
#include "ui_homelayout.h"
#include "mainwindow.h"
#include "maps.h"
#include "QMessageBox"
#include "QTimer"
#include "QGraphicsOpacityEffect"
#include "QGraphicsEffect"
#include "QPropertyAnimation"
#include "Result/Result.h"
#include "Operation/Operation.h"
#include <QToolTip>
#include "QSound"
#include "QtMultimedia"
#include "QVideoWidget"
#include <QGraphicsOpacityEffect>

homeLayout::homeLayout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homeLayout)
{
    ui->setupUi(this);
    /////////////Image//////////////
    //QPixmap pix("/home/durr/Pictures/t.png");
    //ui->label->setPixmap(pix.scaled(50,50,Qt::IgnoreAspectRatio, Qt::FastTransformation));
    //ui->label->setPixmap(pix);

    /*int h=ui->label->height();
    int w=ui->label->width();
    ui->label->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio, Qt::FastTransformation));*/

    /////////////Animation//////////////
    animation(ui->PushButtonHome);
    animation(ui->PushButtonAbout);
    animation(ui->PushButtonFeedback);
    animation(ui->PushButtonHistory);
    animation(ui->PushButtonLevel);
    animation(ui->PushButtonMaps);
}

homeLayout::~homeLayout()
{
    delete ui;
}

void homeLayout::animation(QAbstractButton *PushButton){
    QPropertyAnimation *animation = new QPropertyAnimation(PushButton, "geometry");
    animation->setDuration(5000);
    animation->setStartValue(QRect(0, 0, 100, 65));
    animation->setEndValue(PushButton->geometry());
    animation->setEasingCurve(QEasingCurve::OutElastic);
    animation->start();

    QGraphicsOpacityEffect opacity;
    //QPropertyAnimation *anim = new QPropertyAnimation(opacity, "opacity" );
    QPropertyAnimation anim(&opacity, "opacity" );
    PushButton->setGraphicsEffect(&opacity);
    anim.setDuration(3000);
    anim.setStartValue( 0.0 );
    anim.setEndValue( 1.0 );
    anim.start();
}

//////////////////////////////image/////////////////////////////////////
/*void homeLayout::on_PushButtonHome_clicked()
{
    //QPixmap pix("/home/durr/Pictures/truck.jpeg");
    const int w = ui->label->width();
    const int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
}*/

void homeLayout::on_PushButtonHistory_clicked()
{
    MainWindow *mainUI = new MainWindow;
    hide();
    //mainUI->setWindowState(Qt::WindowFullScreen);
    //mainUI->showFullScreen();
    mainUI->show();
}

//////////////////////////////pop up//////////////////////////////////
void homeLayout::on_PushButtonFeedback_clicked()
{
    //QMessageBox::information(this, "Feedback", "Your Feedback");
    //QMessageBox::warning(this, "Warning", "Your gas is almost empty");

    /*QMessageBox* msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Note");
    msgbox->setText("Successfully copied item foobar");
    msgbox->open();

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), msgbox, SLOT(close()));
    QObject::connect(timer, SIGNAL(timeout()), timer, SLOT(stop()));
    QObject::connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()));
    timer->start(2000);*/

    /*QTimer* timer = new QTimer(this);
    QGraphicsOpacityEffect* effect=new QGraphicsOpacityEffect();
    ui->label->setGraphicsEffect(effect);
    ui->label->setStyleSheet("border: 3px solid gray;border-radius:20px;background-color:#ffffff;color:gray");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText("Your Notification");
    QPropertyAnimation* a=new QPropertyAnimation(effect,"opacity");
    a->setDuration(1000);  // in miliseconds
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    ui->label->show();
    connect(timer,SIGNAL(timeout()),this,SLOT(fadeOut()));
    timer->start(2000); // 1000 ms to make the notification opacity full and 1000 seconds to call the fade out so total of 2000ms.*/
}

void homeLayout::fadeOut(){
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();
    ui->label->setGraphicsEffect(effect);
    QPropertyAnimation *a = new QPropertyAnimation(effect,"opacity");
    a->setDuration(1000); // it will took 1000ms to face out
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::OutBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),ui->label,SLOT(hide()));
}

void homeLayout::on_PushButtonAbout_clicked()
{
    NotificationParams params;
    params.title = "Trying to find existed file";
    params.message = Operation::DoSomething(Result::RESULT_SUCCESS);
    notificationLayout.AddNotificationWidget(this, params);
    this->playSound();
}

void homeLayout::on_PushButtonLevel_clicked()
{
    NotificationParams params;
    params.title = "Trying to find not existed file";
    params.message = Operation::DoSomething(Result::RESULT_ERROR);
    params.detailsButtonText = "Try again";
    params.callback = [this](){
        on_PushButtonAbout_clicked();
    };
    notificationLayout.AddNotificationWidget(this, params);
    this->playSound();
}

void homeLayout::on_PushButtonMaps_clicked()
{
    Maps *maps = new Maps;
    hide();
    //mainUI->setWindowState(Qt::WindowFullScreen);
    //mainUI->showFullScreen();
    maps->show();
}

void homeLayout::playSound(){
    QMediaPlayer *player = new QMediaPlayer;
    //player->setMedia(QUrl::fromLocalFile("/home/durr/serial/sound/blop.wav"));
    player->setMedia(QUrl("qrc:/sound/blop.wav"));
    player->setVolume(50);
    player->play();
}

void homeLayout::playVideo(){
    /*QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/durr/serial/video/wild.mp4"));
    player->setVolume(10);
    player->play();*/

    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *videoWidget = new QVideoWidget;

    player->setMedia(QUrl::fromLocalFile("/home/durr/serial/video/tayamum.mp4"));
    player->setVideoOutput(videoWidget);
    videoWidget->setGeometry(300,50,800,600);
    videoWidget->show();
    player->play();
}

void homeLayout::on_PushButtonHome_clicked()
{
    //this->playSound();
    this->playVideo();
}

void homeLayout::on_PushButtonReboot_clicked()
{
    QProcess process;
    process.startDetached("reboot");
}

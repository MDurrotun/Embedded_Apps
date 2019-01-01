#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "homelayout.h"
#include "QLabel"
#include "QPainter"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QPixmap pix("/home/durr/serial/picture/login.png");
    pix = pix.scaled(180, 180, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    //rotate pixmap
   /*QMatrix rm;
    rm.rotate(0);
    int pxw = pix.width(), pxh = pix.height();
    pix = pix.transformed(rm);
    pix = pix.copy((pix.width() - pxw)/2, (pix.height() - pxh)/2, pxw, pxh);*/

    ui->label_3->setPixmap(pix);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    homeLayout *homeUI = new homeLayout;
    hide();
    //mainUI->setWindowState(Qt::WindowFullScreen);
    //mainUI->showFullScreen();
    //mainUI->show();
    homeUI->show();

    /*if(username=="admin" && password=="admin")
    {
        QMessageBox::information(this, "login", "Username and Password is correct");
        hide();
        MainWindow *mainUI = new MainWindow;
        //mainUI->setWindowState(Qt::WindowFullScreen);
        //mainUI->showFullScreen();
        mainUI->show();
    }
    else
    {
        QMessageBox::warning(this, "login", "Username and Password is wrong");
    }*/
}

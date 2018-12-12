#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "homelayout.h"
#include "QLabel"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QPixmap pix("/home/durr/serial/picture/login.png");
    pix = pix.scaled(180, 180, Qt::IgnoreAspectRatio, Qt::FastTransformation);
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

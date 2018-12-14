#include "feedback.h"
#include "ui_feedback.h"
#include "homelayout.h"
#include "QMutex"

feedback::feedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::feedback)
{
    ui->setupUi(this);
    this->setGeometry(300,50,800,600);

    mThread = new myThread(this);

    connect(mThread,SIGNAL(numberChanged(int)), this, SLOT(onValueChanged(int)));
}

feedback::~feedback()
{
    delete ui;
}

void feedback::onValueChanged(int value){
    ui->label->setText(QString::number(value));
}

void feedback::on_PushButtonHome_clicked()
{
    hide();
    homeLayout *homeLayoutUI = new homeLayout;
    homeLayoutUI->show();
}

void feedback::on_PushButtonStart_clicked()
{
    mThread->stop=false;
    mThread->start();
}

void feedback::on_PushButtonStop_clicked()
{
    mThread->stop = true;
}

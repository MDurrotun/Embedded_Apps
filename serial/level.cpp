#include "level.h"
#include "ui_level.h"
#include "mainwindow.h"
#include "homelayout.h"

level::level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level)
{
    ui->setupUi(this);
    this->setGeometry(300,50,800,600);
    ui->progressBar->setValue(0);
    ui->progressBar2->setValue(0);

    QTimer *timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(myFunction()));
    connect(this,SIGNAL(counterReached(int)), this, SLOT(on_progressBar_valueChanged(int)));
    connect(this,SIGNAL(counterReached(int)), this, SLOT(on_progressBar2_valueChanged(int)));
    timer1->start(1000);

    //this->on_progressBar_valueChanged(100);
}

level::~level()
{
    delete ui;
}

void level::myFunction(){
    m_counter++;
    emit counterReached(m_counter);
}

void level::on_pushButtonHome_clicked()
{
    hide();
    homeLayout *home = new homeLayout;
    home->show();
}

void level::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void level::on_progressBar2_valueChanged(int value)
{
    ui->progressBar2->setValue(value);
}

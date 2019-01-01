#include "level.h"
#include "ui_level.h"
#include "mainwindow.h"
#include "homelayout.h"
#include "QPainter"
#include "QGraphicsPixmapItem"
#include "QGraphicsView"
#include "QSlider"

int counter = 0, angle=0;

level::level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level)
{
    ui->setupUi(this);
    this->setGeometry(300,50,800,600);

    QPixmap pix2(":/picture/speedo2.png");
    pix2 = pix2.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->label_2->setPixmap(pix2);

    QPixmap pix(":/picture/jarum.png");
    pix = pix.scaled(300, 300, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->label->setPixmap(pix);

    ui->progressBar->setValue(0);
    ui->progressBar2->setValue(0);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(80, 300, 180, 30);

    QObject::connect(slider,SIGNAL(valueChanged(int)),this,SLOT(setProgress(int)));

    QTimer *timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(myFunction()));
    connect(this,SIGNAL(counterReached(int)), this, SLOT(on_progressBar_valueChanged(int)));
    connect(this,SIGNAL(counterReached(int)), this, SLOT(on_progressBar2_valueChanged(int)));
    connect(this,SIGNAL(counterReached(int)), this, SLOT(on_progressBar3_valueChanged(int)));
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

void level::setProgress(int val)
{
    progress = (double)val/100;
    //yes, it is not very good, the best approach is to
    //create something similar to QProgressBar
    this->update();
}

void level::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPen pen;
    pen.setWidth(15);
    pen.setColor(Qt::blue);
    p.setPen(pen);

    p.setRenderHint(QPainter::Antialiasing);

    QRectF rectangle(75.0, 30.0, 220.0, 220.0);
    //to understand these magic numbers, look drawArc method in Qt doc
    int startAngle = -90 * 16;
    int spanAngle = progress * -360 * 16;

    p.drawArc(rectangle, startAngle, spanAngle);

    p.drawText(rectangle,Qt::AlignCenter,QString::number(progress*180)+" MPH");
}


void level::on_pushButtonRotate_clicked()
{
    while(true){

    QApplication::processEvents();

    /*QPixmap ship(":/picture/jarum.png");
    QPixmap rotate(ship.size());

    QPainter p(&rotate);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width()/2, rotate.size().height()/2);
    p.rotate(angle);
    p.translate(-rotate.size().width()/2, -rotate.size().height()/2);

    p.drawPixmap(0, 0, ship);
    p.end();

    ui->label->setPixmap(rotate);*/


    QGraphicsPixmapItem item;
    QGraphicsScene scene;
    QGraphicsView view;
    QPixmap pix(":/picture/jarum.png");


    /*item.setTransformationMode(Qt::SmoothTransformation);
    item.setPixmap(pix);
    scene.addItem(&item);
    view.setScene(&scene);
    view.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);*/
    //view.scale(0.2, 0.2);
    //window.setCentralWidget(&view);

    pix = pix.scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //rotate pixmap
    QMatrix rm;
    rm.rotate(angle);
    int pxw = pix.width(), pxh = pix.height();
    pix = pix.transformed(rm);
    //item.setTransformationMode(Qt::SmoothTransformation);
    pix = pix.copy((pix.width() - pxw)/2, (pix.height() - pxh)/2, pxw, pxh);
    ui->label->setPixmap(pix);

    if(counter%5==0)angle++;
    counter++;
    }
}

void level::on_progressBar3_valueChanged(int value)
{
    ui->progressBar3->setValue(value);
}

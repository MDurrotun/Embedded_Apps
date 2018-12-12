#include "alertwidget.h"
#include "ui_alertwidget.h"
#include "QMessageBox"
#include "QTimer"
#include "QGraphicsOpacityEffect"
#include "QGraphicsEffect"
#include "QPropertyAnimation"

AlertWidget::AlertWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlertWidget)
{
    ui->setupUi(this);
}

AlertWidget::~AlertWidget()
{
    delete ui;
}

/*AlertWidget::AlertWidget(QString title, QString body, QPixmap image, int duration) :
    QDialog(nullptr),
    ui(new Ui::AlertWidget)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#999999");
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowStaysOnTopHint|Qt::Popup);

    ui->title->setText(title); ui->title->setStyleSheet("color:#300000; font-weight: bold;");
    ui->body->setText(body);
    ui->image->setPixmap(image);

    QTimer::singleShot(duration, this, SLOT(close()));
    NotificationWidgetRecord::GetInstance().SetLastidx(NotificationWidgetRecord::GetInstance().LastIdx() + 1);
    qDebug()<<QString::number(NotificationWidgetRecord::GetInstance().LastIdx());
    NotificationWidgetRecord::GetInstance().AppendWidget(this);

    if(NotificationWidgetRecord::GetInstance().NotificationFlag())
        return;

    this->autoPos();
}

void AlertWidget::autoPos()
{
    auto desktopRect = QApplication::desktop()->screenGeometry();

    auto h_max = desktopRect.height() / this->height();
    int x, y;
    //do {//To do
        qDebug()<<QString::number(NotificationWidgetRecord::GetInstance().LastIdx());
        x = desktopRect.width() - (((NotificationWidgetRecord::GetInstance().LastIdx() / h_max) + 1) * this->width());
        //y = this->height() * (NotificationWidgetRecord::GetInstance().LastIdx() % h_max);
        y = this->height()*(h_max - NotificationWidgetRecord::GetInstance().LastIdx());
        if (x < 0) {
            NotificationWidgetRecord::GetInstance().SetLastidx(0);//lastIdx_ = 0;
        }
    //} while ( x < 0);
    this->move(x,y);
    this->show();
}

void AlertWidget::closeEvent(QCloseEvent *e)
{
    if(!(NotificationWidgetRecord::GetInstance().windows().contains(this)))
        return;

    auto i = NotificationWidgetRecord::GetInstance().windows().indexOf(this);
    qDebug()<<QString::number(i);
    NotificationWidgetRecord::GetInstance().RemoveWidget(i);

    if(NotificationWidgetRecord::GetInstance().windows().isEmpty())
        NotificationWidgetRecord::GetInstance().SetLastidx(0);
    else
        NotificationWidgetRecord::GetInstance().SetLastidx(NotificationWidgetRecord::GetInstance().LastIdx() - 1);

    e->accept();
}

void AlertWidget::on_pushButton_clicked()
{
    //QDialog::close();
    //this->close();
    close();
}*/

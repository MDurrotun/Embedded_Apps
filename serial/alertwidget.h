#ifndef ALERTWIDGET_H
#define ALERTWIDGET_H

#include <QWidget>

namespace Ui {
class AlertWidget;
}

class AlertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlertWidget(QWidget *parent = 0);
    ~AlertWidget();

private slots:

private:
    Ui::AlertWidget *ui;
};

#endif // ALERTWIDGET_H

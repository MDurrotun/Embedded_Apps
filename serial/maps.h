#ifndef MAPS_H
#define MAPS_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class Maps;
}

class Maps : public QWidget
{
    Q_OBJECT

public:
    explicit Maps(QWidget *parent = 0);
    ~Maps();

private slots:
    void on_pushButtonHome_clicked();

private:
    Ui::Maps *ui;
    QWebEngineView *m_view;
};

#endif // MAPS_H

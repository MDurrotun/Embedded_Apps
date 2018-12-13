#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>

namespace Ui {
class level;
}

class level : public QWidget
{
    Q_OBJECT

public:
    explicit level(QWidget *parent = 0);
    ~level();
    qint8 x=0;
    int m_counter;

private slots:
    void myFunction();
    void on_pushButtonHome_clicked();

    void on_progressBar_valueChanged(int value);

    void on_progressBar2_valueChanged(int value);

signals:
    int counterReached(int value);

private:
    Ui::level *ui;
};

#endif // LEVEL_H

#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include <mythread.h>

namespace Ui {
class feedback;
}

class feedback : public QWidget
{
    Q_OBJECT

public:
    explicit feedback(QWidget *parent = 0);
    ~feedback();
    //void run();
    //bool stop;
    myThread *mThread;

signals:
    //void numberChanged(int);

private slots:
    void on_PushButtonHome_clicked();
    void onValueChanged(int);
    void on_PushButtonStart_clicked();
    void on_PushButtonStop_clicked();

private:
    Ui::feedback *ui;
};

#endif // FEEDBACK_H

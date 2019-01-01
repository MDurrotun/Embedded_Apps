#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class myThread : public QThread
{
    Q_OBJECT

public:
    explicit myThread(QObject *parent = 0);
    void run();
    bool stop=false;

signals:
    int numberChanged(int);

public slots:


};

#endif // MYTHREAD_H

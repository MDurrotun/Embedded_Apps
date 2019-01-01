#include "mythread.h"
#include "QMutex"

myThread::myThread(QObject *parent) :
    QThread(parent)
{
}

void myThread::run(){
    QMutex mutex;
    for(int val=0; val<1000; val++){
        mutex.lock();
        if(this->stop) break;
        mutex.unlock();
        this->usleep(100000);

        emit numberChanged(val);
    }
}


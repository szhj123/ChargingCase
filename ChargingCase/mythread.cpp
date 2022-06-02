#include "mythread.h"

MyThread::MyThread(int threadId, QObject *parent) :
    threadId(threadId),
    QThread(parent)
{

}

void MyThread::run()
{

}

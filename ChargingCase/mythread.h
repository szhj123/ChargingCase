#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int threadId, QObject *parent = 0);
    void run();
    int threadId;
signals:

public slots:

};

#endif // MYTHREAD_H

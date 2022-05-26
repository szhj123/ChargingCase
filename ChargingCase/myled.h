#ifndef MYLED_H
#define MYLED_H

#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>

class MyLed : public QObject
{
    Q_OBJECT
public:
    explicit MyLed(QObject *parent = nullptr);
    void Set_Led_Enabled(Ui::MainWindow *ui, int index);
    void Set_Led_Mode(Ui::MainWindow *ui, int index);
signals:

};

#endif // MYLED_H

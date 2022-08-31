#ifndef MYUPGRADE_H
#define MYUPGRADE_H

#include "ui_mainwindow.h"
#include "myserialport.h"

#include <QWidget>
#include <QFileDialog>

class MyUpgrade : public QWidget
{
    Q_OBJECT
public:
    explicit MyUpgrade(QWidget *parent = nullptr);
    void Upgrade_Init(Ui::MainWindow *ui, MySerialPort *serialPort);
private:
    Ui::MainWindow *ui;
    MySerialPort *serialPort;
signals:

private slots:
    void on_btnAddFw_Clicked(void );

};

#endif // MYUPGRADE_H

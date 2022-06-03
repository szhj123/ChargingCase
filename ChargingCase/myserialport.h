#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>


class MySerialPort : public QObject
{
    Q_OBJECT
public:
    explicit MySerialPort(QObject *parent = nullptr);
    void Serial_Port_Init(Ui::MainWindow *ui);
    void Serial_Port_Refresh(Ui::MainWindow *ui);
    void Serial_Port_Open(Ui::MainWindow *ui);
    void Serial_Port_Close(Ui::MainWindow *ui);
    void Serial_Port_Enable(Ui::MainWindow *ui, bool enabled);
    void Serial_Port_Send_Data(char *pBuf, int length );
    void Serial_Port_Set_Opened(bool opened);
    bool Serial_Port_Get_Opened(void);
private:
    QSerialPort *mySerialPort;
    bool  serialPortOpened;

private slots:
    void Serial_Port_Recv_Data();

signals:

};

#endif // MYSERIALPORT_H

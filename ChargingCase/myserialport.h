#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

#define CMD_PIC_ERASE           0x02
#define CMD_PIC_DATA            0x03
#define CMD_PIC_ACK             0x04

#define CMD_SET_FW_ERASE        0x05
#define CMD_GET_FW_ERASE_ACK    (CMD_SET_FW_ERASE | 0x80)
#define CMD_SET_FW_DATA         0x06
#define CMD_GET_FW_DATA_ACK     (CMD_SET_FW_DATA | 0x80)
#define CMD_SET_FW_CHECKSUM     0x07
#define CDM_GET_FW_CHECKSUM_ACK (CMD_SET_FW_CHECKSUM | 0x80)

#define CMD_GET_VERSION      0x09

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

    void Serial_Send_Cmd_Pic_Erase(int imageTotalNum, int imageIndex, uint16_t width, uint16_t height);
    void Serial_Send_Cmd_Pic_Data(int offset, char *pBuf, int length);
    void Serial_Send_Cmd_Get_Version(void );
    void Serial_Send_Cmd_Fw_Erase(int fwLength );
    void Serial_Send_Cmd_Tx_Data(int offset, char *pBuf, int length );
    void Serial_Send_Cmd_Tx_Checksum(int fwChecksum );

private:
    QSerialPort *mySerialPort;
    bool  serialPortOpened;

private slots:
    void Serial_Port_Recv_Data(void);

signals:

};


#endif // MYSERIALPORT_H

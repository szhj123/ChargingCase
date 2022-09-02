#ifndef MYUPGRADE_H
#define MYUPGRADE_H

#include "ui_mainwindow.h"
#include "myserialport.h"

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#define FW_MAX_DATA_LENGTH               64

typedef enum
{
    UPG_STATE_ERASE_FLASH = 0,
    UPG_STATE_WAIT_ACK_FOR_ERASE,
    UPG_STATE_TX_FW_DATA,
    UPG_STATE_WAIT_ACK_FOR_TX,
    UPG_STATE_TX_FW_CHECKSUM,
    UPG_STATE_WATI_ACK_FOR_CHECKSUM
}upg_state_t;

typedef struct _fw_info_t
{
    int fwLength;
    int fwOffset;
    uchar *fwBuf;
    int fwTxLength;
    QByteArray fwArray;
}fw_info_t;
Q_DECLARE_METATYPE(fw_info_t)

class MyUpgrade : public QWidget
{
    Q_OBJECT
public:
    explicit MyUpgrade(QWidget *parent = nullptr);
    void Upgrade_Init(Ui::MainWindow *ui, MySerialPort *serialPort);
    void Upgrade_Set_Version(uchar fwBuildVer, uchar fwMinorVer, uchar fwMajorVer);
private:
    Ui::MainWindow *ui;
    MySerialPort *serialPort;
    QTimer *timer;
signals:

private slots:
    void on_btnAddFw_Clicked(void );
    void on_btnUpgEn_Clicked(void );
    void on_tabWidget_Clicked(int index );
    void Upg_Handler(void );
};

#endif // MYUPGRADE_H

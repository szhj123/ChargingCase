#include "myupgrade.h"

#define UPG_INTERVAL_TIME                5

static fw_info_t   fwInfo;
static upg_state_t upgState;

MyUpgrade::MyUpgrade(QWidget *parent) : QWidget(parent)
{

}

void MyUpgrade::Upgrade_Init(Ui::MainWindow *ui, MySerialPort *serialPort)
{
    this->ui = ui;

    this->serialPort = serialPort;

    connect(ui->btn_addFw, SIGNAL(clicked()), this, SLOT(on_btnAddFw_Clicked()));

    connect(ui->btn_upgEn, SIGNAL(clicked()), this, SLOT(on_btnUpgEn_Clicked()));

    connect(ui->tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(on_tabWidget_Clicked(int)));

    timer = new QTimer(this);
    timer->setInterval(UPG_INTERVAL_TIME);
    connect(timer, SIGNAL(timeout()), this, SLOT(Upg_Handler()));
}

void MyUpgrade::Upgrade_Set_Version(uchar fwBuildVer, uchar fwMinorVer, uchar fwMajorVer)
{
    QString str = "0.0.0";

    str[0] = fwBuildVer + 0x30;
    str[2] = fwMinorVer + 0x30;
    str[4] = fwMajorVer + 0x30;

    ui->label_fwVersion->setText(str);
}

void MyUpgrade::on_btnAddFw_Clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open Upgrade Firmware"),QDir::homePath(),tr("(*.bin)"));

    ui->lineEdit_fwPath->setText(filePath);

    QFile readFile(ui->lineEdit_fwPath->text());

    QFileInfo readFileInfo(readFile);

    if(!readFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Read File)"), tr("Cannot open file:\n%1").arg(ui->lineEdit_fwPath->text()));

        return ;
    }

    QDataStream binFileData(&readFile);

    fwInfo.fwLength = readFileInfo.size();

    static char *pBuf = new char[fwInfo.fwLength];

    binFileData.readRawData(pBuf, static_cast<int>(fwInfo.fwLength));

    fwInfo.fwArray = QByteArray(pBuf, static_cast<int>(fwInfo.fwLength));

    fwInfo.fwBuf = (uchar *)fwInfo.fwArray.data();


}

void MyUpgrade::on_btnUpgEn_Clicked()
{
    ui->btn_upgEn->setEnabled(false);

    upgState = UPG_STATE_ERASE_FLASH;

    timer->start();
}

void MyUpgrade::on_tabWidget_Clicked(int index)
{
    if(index == 2)
    {
        if(serialPort->Serial_Port_Get_Opened() == true)
        {
            serialPort->Serial_Send_Cmd_Get_Version();
        }
    }
}

void MyUpgrade::Upg_Handler()
{
    switch(upgState)
    {
        case UPG_STATE_ERASE_FLASH:
        {
            for(int i=0;i<fwInfo.fwLength;i++)
                qDebug() << QString().sprintf("0x%02x", fwInfo.fwBuf[i]);
            upgState = UPG_STATE_WAIT_ACK_FOR_ERASE;
            break;
        }
        case UPG_STATE_WAIT_ACK_FOR_ERASE:
        {
            break;
        }
        case UPG_STATE_TX_FW_DATA:
        {
            break;
        }
        case UPG_STATE_WAIT_ACK_FOR_TX:
        {
            break;
        }
        case UPG_STATE_TX_FW_CHECKSUM:
        {
            break;
        }
        case UPG_STATE_WATI_ACK_FOR_CHECKSUM:
        {
            break;
        }
        default: break;
    }
}



#include "myupgrade.h"

MyUpgrade::MyUpgrade(QWidget *parent) : QWidget(parent)
{

}

void MyUpgrade::Upgrade_Init(Ui::MainWindow *ui, MySerialPort *serialPort)
{
    this->ui = ui;

    this->serialPort = serialPort;

    connect(ui->btn_addFw, SIGNAL(clicked()), this, SLOT(on_btnAddFw_Clicked()));
}

void MyUpgrade::on_btnAddFw_Clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open Upgrade Firmware"),QDir::homePath(),tr("(*.bin)"));

    ui->lineEdit_fwPath->setText(filePath);
}

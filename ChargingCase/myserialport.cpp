#include "myserialport.h"


MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{

}

void MySerialPort::Serial_Port_Init(Ui::MainWindow *ui)
{
    //创建串口串口对象
    mySerialPort = new QSerialPort(this);
    //数据接收处理
    connect(mySerialPort,&QSerialPort::readyRead,this,&MySerialPort::Serial_Port_Recv_Data);

    QStringList slist;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        //检测是否可用
        if(!info.isBusy())
            slist<<info.portName();
    }
    if(slist.isEmpty()){
        qDebug()<<"未找到可用串口,请确认串口连接正常后点击刷新";
    }

    ui->boxPortName->clear();
    ui->boxPortName->addItems(slist);
}

void MySerialPort::Serial_Port_Refresh(Ui::MainWindow *ui)
{
    ui->boxPortName->clear();
    Serial_Port_Init(ui);
}

void MySerialPort::Serial_Port_Open(Ui::MainWindow *ui)
{
    const QString portnameStr=ui->boxPortName->currentText();

    if(!portnameStr.isEmpty())
    {
        QSerialPortInfo info(portnameStr);

        if(info.isBusy())
        {
            qDebug()<<"当前串口繁忙,可能已被占用,请确认后再连接"<<portnameStr;
            return;
        }

        qint32 baudrate=ui->boxBaudRate->currentText().toInt();

        QSerialPort::DataBits databit;
        switch (ui->boxDataBits->currentIndex())
        {
            case 0:databit=QSerialPort::Data5; break;
            case 1:databit=QSerialPort::Data6; break;
            case 2:databit=QSerialPort::Data7; break;
            case 3:databit=QSerialPort::Data8; break;
            default:databit=QSerialPort::Data8; break;
        }

        QSerialPort::Parity parity;
        switch (ui->boxParity->currentIndex())
        {
            case 0:parity=QSerialPort::NoParity; break;
            case 1:parity=QSerialPort::EvenParity; break;
            case 2:parity=QSerialPort::OddParity; break;
            case 3:parity=QSerialPort::SpaceParity; break;
            case 4:parity=QSerialPort::MarkParity; break;
            default:parity=QSerialPort::NoParity; break;
        }

        QSerialPort::StopBits stopbit;
        switch (ui->boxStopBits->currentIndex())
        {
            case 0:stopbit=QSerialPort::OneStop; break;
            case 1:stopbit=QSerialPort::OneAndHalfStop; break;
            case 2:stopbit=QSerialPort::TwoStop; break;
            default:stopbit=QSerialPort::OneStop; break;
        }

        QSerialPort::FlowControl flowcontrol;
        switch (ui->boxFlowControl->currentIndex())
        {
            case 0:flowcontrol=QSerialPort::NoFlowControl; break;
            case 1:flowcontrol=QSerialPort::HardwareControl; break;
            case 2:flowcontrol=QSerialPort::SoftwareControl; break;
            default:flowcontrol=QSerialPort::NoFlowControl; break;
        }

        //qDebug() <<"波特率："<<QString().sprintf("%d", baudrate);
        //qDebug() <<"数据位："<<QString().sprintf("%d", ui->boxDataBits->currentIndex());
        //qDebug() <<"奇偶校验位"<<QString().sprintf("%d", ui->boxParity->currentIndex());
        //qDebug() <<"停止位："<<QString().sprintf("%d", ui->boxStopBits->currentIndex());
        //qDebug() <<"流控制："<<QString().sprintf("%d", ui->boxFlowControl->currentIndex());
        //串口配置设置
        mySerialPort->setPortName(portnameStr);
        mySerialPort->setBaudRate(baudrate);
        mySerialPort->setDataBits(databit);
        mySerialPort->setParity(parity);
        mySerialPort->setStopBits(stopbit);
        mySerialPort->setFlowControl(flowcontrol);//这个我一般没用

        if(mySerialPort->open(QIODevice::ReadWrite))
        {
            qDebug()<<"串口已打开,读写模式";
            Serial_Port_Enable(ui, false);//改变ui状态
        }
        else
        {
            qDebug()<<"串口打开异常"<<portnameStr<<mySerialPort->errorString();
            mySerialPort->clearError();
            Serial_Port_Enable(ui, true);
        }
    }
    else
    {
        qDebug()<<"未找到可用串口,请确认串口连接正常后点击刷新";
    }
}

void MySerialPort::Serial_Port_Close(Ui::MainWindow *ui)
{
    mySerialPort->clear();
    mySerialPort->close();
    qDebug()<<"串口已关闭";
    Serial_Port_Enable(ui, true);
}


void MySerialPort::Serial_Port_Enable(Ui::MainWindow *ui, bool enabled)
{
    //打开成功就false不能再修改配置，关闭状态true可以进行设置
    ui->btnSerialOpen->setText(enabled?QString("打开"):QString("关闭"));
    //可以把btn和配置分在两个widget里，这样直接设置widget的enable就没这么麻烦了
    ui->boxPortName->setEnabled(enabled);
    ui->boxBaudRate->setEnabled(enabled);
    ui->boxDataBits->setEnabled(enabled);
    ui->boxParity->setEnabled(enabled);
    ui->boxStopBits->setEnabled(enabled);
    ui->boxFlowControl->setEnabled(enabled);
}

void MySerialPort::Serial_Port_Send_Data(char *pBuf, int length )
{
    if(pBuf == nullptr || length <=0)
        return ;
    if(mySerialPort->isOpen()){
        mySerialPort->write(pBuf, length);
        //qDebug()<<"已发送："<<QString::fromUtf8(send_data);
    }else{
        qDebug()<<"发送失败,串口未打开";
        return;
    }
    //Qt新版本默认值是30 000
    if(!mySerialPort->waitForBytesWritten(30000)){
        qDebug()<<"命令发送异常"<<mySerialPort->errorString();
        mySerialPort->clearError();
    }
}

void MySerialPort::Serial_Port_Recv_Data()
{
    if (mySerialPort->bytesAvailable())
    {
        //串口收到的数据可能不是连续的，需要的话应该把数据缓存下来再进行协议解析，类似tcp数据处理
        const QByteArray recv_data=mySerialPort->readAll();
        //接收发送要一致，如果是处理字节数据，可以把QByteArray当数组一样取下标，或者用data()方法转为char*形式
        //ui->textRecv->append(QString::fromUtf8(recv_data));
        qDebug()<<"已接收："<<QString::fromUtf8(recv_data);
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlag(Qt::FramelessWindowHint);

    setFixedSize(this->width(),this->height());

    ui->setupUi(this);

    setTabWidget();

    scanSerialPort();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTabWidget()
{
    ui->tabWidget->setTabText(0, tr("灯光设置"));
    ui->tabWidget->setTabText(1, tr("图片设置"));
    ui->tabWidget->setTabText(2, tr("固件升级"));

}

void MainWindow::scanSerialPort()
{
    //创建串口串口对象
    serialport = new QSerialPort(this);
    //数据接收处理
    //connect(serialport,&QSerialPort::readyRead,this,&MainWidget::recvData);

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

void MainWindow::refreshSerial()
{
    ui->boxPortName->clear();
    scanSerialPort();
}

void MainWindow::setSerialEnable(bool enabled)
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

void MainWindow::paintEvent(QPaintEvent *event)
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //获取title widget 的高度，这里固定为60px
    int titleHeight = ui->widget_logo->height();
    if(event->y() <titleHeight)
    {
        last = event->globalPos(); //获取到按压的位置
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int titleHeight = ui->widget_logo->height();
    if(event->y() <titleHeight)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        this->move(this->x()+dx,this->y()+dy);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int titleHeight = ui->widget_logo->height();
    if(event->y() <titleHeight)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        this->move(this->x()+dx,this->y()+dy);
    }
}


void MainWindow::on_lineEdit_PngNum_textChanged(const QString &arg1)
{
    bool ok;
    int  pngNum = arg1.toInt(&ok, 10);
    int  i;
    if(pngNum > 5)
        pngNum = 5;

    for(i=0;i<pngNum;i++)
    {

    }
}

void MainWindow::on_btnPng1_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

    image_png1_src = new QImage(filename);

    show_imgage(image_png1_src, ui->label_png1);

    read_image_rgb565(image_png1_src, image_png1_buf);
}

void MainWindow::on_btnSerialOpen_clicked()
{
    if(ui->btnSerialOpen->text()=="打开")
    {
        openSerial();
    }
    else
    {
        closeSerial();
    }
}

void MainWindow::show_imgage(QImage *pImage, QLabel *pLabel )
{
    QPixmap pixmap = QPixmap::fromImage(*pImage);
    int with = pLabel->width();
    int height = pLabel->height();
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    pLabel->setPixmap(fitpixmap);
}

void MainWindow::read_image_rgb565(QImage *pImage, QByteArray pImageDataBuf)
{
    QPixmap pixmap = QPixmap::fromImage(*pImage);

    if(pImage == nullptr)
        return ;

    int with = 320;
    int height = 240;

    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充

    QImage tempImage = fitpixmap.toImage().convertToFormat(QImage::Format_RGB16);

    uchar *pData;

    for(int i=0;i<tempImage.height();i++)
    {
        pData = tempImage.scanLine(i);

        for(int j=0;j<tempImage.width();j++)
        {
            qDebug() << QString().sprintf("%x", pData[2*j]);
            qDebug() << QString().sprintf("%x", pData[2*j+1]);
        }
    }

}

void MainWindow::openSerial()
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

        //串口配置设置
        serialport->setPortName(portnameStr);
        serialport->setBaudRate(baudrate);
        serialport->setDataBits(databit);
        serialport->setParity(parity);
        serialport->setStopBits(stopbit);
        serialport->setFlowControl(flowcontrol);//这个我一般没用

        if(serialport->open(QIODevice::ReadWrite))
        {
            qDebug()<<"串口已打开,读写模式";
            setSerialEnable(false);//改变ui状态
        }
        else
        {
            qDebug()<<"串口打开异常"<<portnameStr<<serialport->errorString();
            serialport->clearError();
            setSerialEnable(true);
        }
    }
    else
    {
        qDebug()<<"未找到可用串口,请确认串口连接正常后点击刷新";
    }
}

void MainWindow::closeSerial()
{
    serialport->clear();
    serialport->close();
    qDebug()<<"串口已关闭";
    setSerialEnable(true);
}


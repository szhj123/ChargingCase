#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myserialport.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlag(Qt::FramelessWindowHint);

    setFixedSize(this->width(),this->height());

    ui->setupUi(this);

    setTabWidget();

    myLed = new MyLed(this);
    myLed->Led_Init(ui);

    mySerialPort = new MySerialPort(this);

    mySerialPort->Serial_Port_Init(ui);

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
        mySerialPort->Serial_Port_Open(ui);
    }
    else
    {
        mySerialPort->Serial_Port_Close(ui);
    }
}

void MainWindow::on_btnSerialRefresh_clicked()
{
    mySerialPort->Serial_Port_Refresh(ui);
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

void MainWindow::on_btnSend_clicked()
{
    char buf[5] = {0,1,2,3,4};

    mySerialPort->Serial_Port_Send_Data(buf, 5);
}






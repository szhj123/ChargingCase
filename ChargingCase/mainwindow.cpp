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
    myPic = new MyPic(this);
    mySerialPort = new MySerialPort(this);

    myLed->Led_Init(ui);
    mySerialPort->Serial_Port_Init(ui);
    myPic->Pic_Init(ui, mySerialPort);
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


void MainWindow::on_btnSend_clicked()
{
    char buf[5] = {0,1,2,3,4};

    mySerialPort->Serial_Port_Send_Data(buf, 5);
}






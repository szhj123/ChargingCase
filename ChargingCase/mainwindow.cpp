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


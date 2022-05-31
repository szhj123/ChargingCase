#include "mypic.h"

MyPic::MyPic(QWidget *parent) : QWidget(parent)
{

}

MyPic::~MyPic()
{

}

void MyPic::Pic_Init(Ui::MainWindow *ui)
{
    this->ui = ui;

    connect(ui->btnPng1, SIGNAL(clicked()), this, SLOT(on_btnPng1_clicked()));
}

void MyPic::on_btnPng1_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

    image_png1_src = new QImage(filename);

    Pic_Show(image_png1_src, ui->label_png1);

    Pic_Read_Rgb565(image_png1_src, image_png1_buf);
}

void MyPic::Pic_Show(QImage *pImage, QLabel *pLabel )
{
    QPixmap pixmap = QPixmap::fromImage(*pImage);
    int with = pLabel->width();
    int height = pLabel->height();
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    pLabel->setPixmap(fitpixmap);
}

void MyPic::Pic_Read_Rgb565(QImage *pImage, QByteArray pImageDataBuf)
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


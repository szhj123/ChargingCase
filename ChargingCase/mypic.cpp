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
    connect(ui->btnPng2, SIGNAL(clicked()), this, SLOT(on_btnPng2_clicked()));
    connect(ui->btnPng3, SIGNAL(clicked()), this, SLOT(on_btnPng3_clicked()));
    connect(ui->btnPng4, SIGNAL(clicked()), this, SLOT(on_btnPng4_clicked()));
    connect(ui->btnPng5, SIGNAL(clicked()), this, SLOT(on_btnPng5_clicked()));
    connect(ui->btnPng6, SIGNAL(clicked()), this, SLOT(on_btnPng6_clicked()));

    connect(ui->btnDownload1, SIGNAL(clicked()), this, SLOT(on_btnDownload1_clicked()));

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(Pic_Data_Send()));
    timer->start();
}

void MyPic::on_btnPng1_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

    image1Src = new QImage(filename);

    Pic_Show(image1Src, ui->labelPng1);
}

void MyPic::on_btnPng2_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

}

void MyPic::on_btnPng3_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));


}

void MyPic::on_btnPng4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));


}

void MyPic::on_btnPng5_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));
}

void MyPic::on_btnPng6_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.gif)"));

    QMovie *movie = new QMovie(filename);

    QSize si(ui->labelPng6->width(),ui->labelPng6->height());

    ui->labelPng6->setMovie(movie);

    movie->setScaledSize(si);

    movie->start();
}

void MyPic::on_btnDownload1_clicked()
{
    //Pic_Read_Rgb565(image1Src, image_png1_buf);
    Pic_Queue_Set(1, image1Src);
}

void MyPic::Pic_Data_Send()
{
    static image_data_s imageData;
#if 1

    if(!Pic_Queue_Get(&imageData))
    {
        QPixmap pixmap = QPixmap::fromImage(*imageData.pImage);

        if(imageData.pImage == nullptr)
            return ;

        int with = 320;
        int height = 240;

        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充

        QImage tempImage = fitpixmap.toImage().convertToFormat(QImage::Format_RGB16);

        uchar *pData = tempImage.bits();

        for(int i=0;i<64;i++)
            qDebug() << QString().sprintf("%x", pData[i]);
    }
#else
    if(!Pic_Queue_Get(&imageData))
    {
        for(int i=0;i<64;i++)
            qDebug() << "hello";
    }
#endif
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

void MyPic::Pic_Queue_Set(int imageIndex, QImage *imageSrc)
{
    QPixmap pixmap = QPixmap::fromImage(*imageSrc);

    if(imageSrc == nullptr)
        return ;

    imageQueue.imageDataBuf[imageQueue.rear].pImage = imageSrc;
    imageQueue.imageDataBuf[imageQueue.rear].imageIndex = imageIndex;

    imageQueue.rear = (imageQueue.rear + 1) % 6;
}

uchar MyPic::Pic_Queue_Get(image_data_s *imageData)
{
    if(imageQueue.head != imageQueue.rear)
    {
        imageData->pImage = imageQueue.imageDataBuf[imageQueue.head].pImage;
        imageData->imageIndex = imageQueue.imageDataBuf[imageQueue.head].imageIndex;
        imageQueue.head = (imageQueue.head + 1) % 6;

        return 0;
    }
    else
        return 1;
}




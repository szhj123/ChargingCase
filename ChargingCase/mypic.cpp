#include "mypic.h"

MyPic::MyPic(QWidget *parent) : QWidget(parent)
{
    memset((void*)&imageQueue, 0, sizeof(image_queue_typedef));
}

MyPic::~MyPic()
{

}

void MyPic::Pic_Init(Ui::MainWindow *ui ,MySerialPort *serialPort)
{
    this->ui = ui;
    this->serialPort = serialPort;

    connect(ui->btnPng1, SIGNAL(clicked()), this, SLOT(on_btnPng1_clicked()));
    connect(ui->btnPng2, SIGNAL(clicked()), this, SLOT(on_btnPng2_clicked()));
    connect(ui->btnPng3, SIGNAL(clicked()), this, SLOT(on_btnPng3_clicked()));
    connect(ui->btnPng4, SIGNAL(clicked()), this, SLOT(on_btnPng4_clicked()));
    connect(ui->btnPng5, SIGNAL(clicked()), this, SLOT(on_btnPng5_clicked()));
    connect(ui->btnPng6, SIGNAL(clicked()), this, SLOT(on_btnPng6_clicked()));

    connect(ui->btnDownload1, SIGNAL(clicked()), this, SLOT(on_btnDownload1_clicked()));
    connect(ui->btnDownload2, SIGNAL(clicked()), this, SLOT(on_btnDownload2_clicked()));

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(Pic_Data_Send()));

}

void MyPic::on_btnPng1_clicked()
{
    static QString saveFileName = nullptr;
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

    if(saveFileName == nullptr && filename != nullptr)
    {
        saveFileName = filename;
    }
    else
    {
        if(filename == saveFileName)
        {
            return ;
        }
        else
        {
            saveFileName = filename;
        }
    }

    image1Src = new QImage(filename);

    Pic_Show(image1Src, ui->labelPng1);
}

void MyPic::on_btnPng2_clicked()
{
    static QString saveFileName = nullptr;

    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));

    if(saveFileName == nullptr && filename != nullptr)
    {
        saveFileName = filename;
    }
    else
    {
        if(filename == saveFileName)
        {
            return ;
        }
        else
        {
            saveFileName = filename;
        }
    }

    image2Src = new QImage(filename);

    Pic_Show(image2Src, ui->labelPng2);
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
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(1, image1Src);

        timer->start();
    }
}

void MyPic::on_btnDownload2_clicked()
{
    Pic_Queue_Set(2, image1Src);
}

void MyPic::Pic_Data_Send()
{
    static pic_send_state_typedef picSendState;
    static image_data_s imageData;

    static uchar *pData = nullptr;
    static int colNum;
    static QImage tempImage;

    switch(picSendState)
    {
        case GET_IMAGE:
        {
            if(Pic_Queue_Get(&imageData) == true)
            {
                QPixmap pixmap = QPixmap::fromImage(*imageData.pImage);

                if(imageData.pImage == nullptr)
                    return ;

                int width = 320;
                int height = 240;

                if(pixmap.width() > width && pixmap.height() > height)
                {
                    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
                    tempImage = fitpixmap.toImage().convertToFormat(QImage::Format_RGB16);
                }
                else
                {
                    tempImage = pixmap.toImage().convertToFormat(QImage::Format_RGB16);
                }
                imageData.rowIndex = 0;
                imageData.colIndex = 0;
                picSendState = GET_ROW_DATA;
            }
            else
            {
                timer->stop();
            }
            break;
        }
        case GET_ROW_DATA:
        {
            if(imageData.rowIndex < tempImage.height())
            {
                pData = tempImage.scanLine(imageData.rowIndex);
                imageData.rowIndex++;
                colNum = tempImage.width();
                picSendState = SEND_COL_DATA;
            }
            else
            {
                picSendState = GET_IMAGE;
            }
            break;
        }
        case SEND_COL_DATA:
        {
            int i;

            if(colNum > 32)
            {
                serialPort->Serial_Port_Send_Data((char *)pData, 64);
                pData += 64;
                imageData.colIndex += 64;

                qDebug() << QString().sprintf("send count:%d", imageData.colIndex);
                colNum -= 32;
            }
            else
            {
                serialPort->Serial_Port_Send_Data((char *)pData, colNum*2);
                imageData.colIndex += colNum*2;

                qDebug() << QString().sprintf("send count:%d", imageData.colIndex);

                picSendState = GET_ROW_DATA;
            }
            break;
        }
        default: break;
    }

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
    if(imageSrc == nullptr)
        return ;

    imageQueue.imageDataBuf[imageQueue.rear].pImage = imageSrc;
    imageQueue.imageDataBuf[imageQueue.rear].imageIndex = imageIndex;

    imageQueue.rear = (imageQueue.rear + 1) % 6;

}

bool MyPic::Pic_Queue_Get(image_data_s *imageData)
{
    if(imageQueue.head != imageQueue.rear)
    {
        imageData->pImage = imageQueue.imageDataBuf[imageQueue.head].pImage;
        imageData->imageIndex = imageQueue.imageDataBuf[imageQueue.head].imageIndex;
        imageQueue.head = (imageQueue.head + 1) % 6;

        return true;
    }
    else
        return false;
}




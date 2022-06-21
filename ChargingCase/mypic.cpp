#include "mypic.h"

MyPic::MyPic(QWidget *parent) : QWidget(parent)
{
    Pic_Queue_Clr();

    picSendState = GET_IMAGE;

    movie = nullptr;
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
    connect(ui->btnDownload3, SIGNAL(clicked()), this, SLOT(on_btnDownload3_clicked()));
    connect(ui->btnDownload4, SIGNAL(clicked()), this, SLOT(on_btnDownload4_clicked()));
    connect(ui->btnDownload5, SIGNAL(clicked()), this, SLOT(on_btnDownload5_clicked()));
    connect(ui->btnDownload6, SIGNAL(clicked()), this, SLOT(on_btnDownload6_clkcked()));

    connect(ui->btnCancelDownload, SIGNAL(clicked()), this, SLOT(on_btnCancelDownload_clicked()));

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

    if(filename == nullptr)
    {
        return ;
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

    if(filename == nullptr)
    {
        return ;
    }

    image2Src = new QImage(filename);

    Pic_Show(image2Src, ui->labelPng2);
}

void MyPic::on_btnPng3_clicked()
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

    if(filename == nullptr)
    {
        return ;
    }

    image3Src = new QImage(filename);

    Pic_Show(image3Src, ui->labelPng3);

}

void MyPic::on_btnPng4_clicked()
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

    if(filename == nullptr)
    {
        return ;
    }

    image4Src = new QImage(filename);

    Pic_Show(image4Src, ui->labelPng4);

}

void MyPic::on_btnPng5_clicked()
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

    if(filename == nullptr)
    {
        return ;
    }

    image5Src = new QImage(filename);

    Pic_Show(image5Src, ui->labelPng5);
}

void MyPic::on_btnPng6_clicked()
{
    QMovie *tmpMovie = nullptr;

    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.gif)"));

    if(filename != nullptr)
    {
        return ;
    }

    movie = new QMovie(filename);

    movie->setFileName(filename);

    movie->setCacheMode(QMovie::CacheAll);

    tmpMovie = new QMovie(filename);

    QSize si(ui->labelPng6->width(),ui->labelPng6->height());

    ui->labelPng6->setMovie(tmpMovie);

    tmpMovie->setScaledSize(si);

    tmpMovie->start();
}

void MyPic::on_btnDownload1_clicked()
{
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(image1Src);

        timer->start();
    }
}

void MyPic::on_btnDownload2_clicked()
{
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(image2Src);

        timer->start();
    }
}

void MyPic::on_btnDownload3_clicked()
{
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(image3Src);

        timer->start();
    }
}

void MyPic::on_btnDownload4_clicked()
{
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(image4Src);

        timer->start();
    }
}

void MyPic::on_btnDownload5_clicked()
{
    if(serialPort->Serial_Port_Get_Opened() == true)
    {
        Pic_Queue_Set(image5Src);

        timer->start();
    }
}

void MyPic::on_btnDownload6_clkcked()
{
    static QImage image;

    if(movie == nullptr || serialPort->Serial_Port_Get_Opened() == false)
    {
        return ;
    }

    int gifFrameNum = movie->frameCount() > GIF_FRAME_NUM ? GIF_FRAME_NUM : movie->frameCount();

    qDebug() << QString().sprintf("gif frame count:%d", gifFrameNum);

    for(int i=0;i<gifFrameNum;i++)
    {
        movie->jumpToFrame(0);

        image = movie->currentImage();

        Pic_Queue_Set(&image);
    }

    timer->start();
}

void MyPic::on_btnCancelDownload_clicked()
{
    Pic_Queue_Clr();

    picSendState = GET_IMAGE;
}

void MyPic::Pic_Data_Send()
{

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

                if(pixmap.width() > IMAGE_MAX_WIDTH && pixmap.height() > IMAGE_MAX_HEIGHT)
                {
                    QPixmap fitpixmap = pixmap.scaled(IMAGE_MAX_WIDTH, IMAGE_MAX_HEIGHT, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
                    tempImage = fitpixmap.toImage().convertToFormat(QImage::Format_RGB16);
                }
                else
                {
                    tempImage = pixmap.toImage().convertToFormat(QImage::Format_RGB16);
                }
                imageData.rowIndex = 0;
                imageData.colIndex = 0;

                qDebug() << QString().sprintf("gif frame index:%d", imageData.imageIndex);
                picSendState = GET_ROW_DATA;
            }
            else
            {
                Pic_Queue_Clr();

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

void MyPic::Pic_Queue_Set(QImage *imageSrc)
{
    if(imageSrc == nullptr)
        return ;

    imageQueue.imageDataBuf[imageQueue.rear].pImage = imageSrc;

    imageQueue.rear = (imageQueue.rear + 1) % GIF_FRAME_NUM;

}

bool MyPic::Pic_Queue_Get(image_data_s *imageData)
{
    if(imageQueue.head != imageQueue.rear)
    {
        imageData->pImage = imageQueue.imageDataBuf[imageQueue.head].pImage;
        imageData->imageIndex = imageQueue.head;
        imageQueue.head = (imageQueue.head + 1) % GIF_FRAME_NUM;

        return true;
    }
    else
        return false;
}

void MyPic::Pic_Queue_Clr()
{
    memset((void*)&imageQueue, 0, sizeof(image_queue_typedef));
}




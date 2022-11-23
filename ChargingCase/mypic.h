#ifndef MYPIC_H
#define MYPIC_H

#include <QWidget>
#include "ui_mainwindow.h"
#include "myserialport.h"
#include "mythread.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>
#include <QFile>
#include <QListView>
#include <QString>
#include <QFileDialog>
#include <QMovie>
#include <QTimer>
#include <QProgressBar>

#define GIF_FRAME_NUM                (128)
#define IMAGE_MAX_WIDTH              (120)
#define IMAGE_MAX_HEIGHT             (160)

typedef struct
{
    QImage *pImage;
    QImage scalingImage;
    uchar  *pData;
    int    imageWidth;
    int    imageHeightCnt;
    int    imageTotalNum;
    int    imageIndex;
    int    imageTotalLength;
    int    imageDataCnt;
    int    gifImageNum;
    int    timeout;
    int    imageTransErrCnt;
}image_data_s;

Q_DECLARE_METATYPE(image_data_s)

typedef struct
{
    image_data_s imageDataBuf[GIF_FRAME_NUM];
    int head;
    int rear;
}image_queue_typedef;

Q_DECLARE_METATYPE(image_queue_typedef)

typedef enum
{
    GET_IMAGE = 0,
    WAIT_RECV_ENABLE_ACK,
    GET_ROW_DATA,
    SEND_COL_DATA,
    WAIT_RECV_DATA_ACK
}pic_send_state_typedef;

class MyPic : public QWidget
{
    Q_OBJECT
public:
    explicit MyPic(QWidget *parent = nullptr);
    ~MyPic();

    void Pic_Init(Ui::MainWindow *ui, MySerialPort *serialPort);
    void Pic_Show(QImage *pImage, QLabel *pLabel );
    void Pic_Read_Rgb565(QImage *pImage, QByteArray pImageDataBuf );
    void Pic_Set_Progress_Bar(void );
    void Pic_Queue_Set(QImage *imageSrc, int imageIndex );
    bool Pic_Queue_Get(image_data_s *imageData);
    void Pic_Queue_Clr(void );
    void Pic_Set_Gif_Image_Num(int imageNum);
    int  Pic_Get_Gif_Image_Num(void );
    void Pic_Set_Ack(unsigned char ack );
    void Pic_Clr_Ack(void );
    unsigned char Pic_Get_Ack(void );
private:
    Ui::MainWindow *ui;
    MySerialPort *serialPort;

    QImage *image1Src;
    QImage *image2Src;
    QImage *image3Src;
    QImage *image4Src;
    QImage *image5Src;

    QMovie *movie;

    QByteArray image_png1_buf;

    pic_send_state_typedef picSendState;

    image_queue_typedef imageQueue;

    QTimer *timer;

    unsigned char ack;

private slots:
    void on_btnPng1_clicked(void);
    void on_btnPng2_clicked(void);
    void on_btnPng3_clicked(void);
    void on_btnPng4_clicked(void);
    void on_btnPng5_clicked(void);
    void on_btnPng6_clicked(void);

    void on_btnDownload1_clicked(void );
    void on_btnDownload2_clicked(void );
    void on_btnDownload3_clicked(void );
    void on_btnDownload4_clicked(void );
    void on_btnDownload5_clicked(void );
    void on_btnDownload6_clkcked(void );
    void on_btnCancelDownload_clicked(void );
    void Pic_Send_Handler(void);
signals:

};

#endif // MYPIC_H

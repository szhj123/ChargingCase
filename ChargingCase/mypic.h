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

#define GIF_FRAME_NUM                (64)
#define IMAGE_MAX_WIDTH              (320)
#define IMAGE_MAX_HEIGHT             (240)

typedef struct
{
    QImage *pImage;
    int    imageIndex;
    int    rowIndex;
    int    colIndex;
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
    GET_ROW_DATA,
    SEND_COL_DATA
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
    void Pic_Queue_Set(QImage *imageSrc );
    bool Pic_Queue_Get(image_data_s *imageData);
    void Pic_Queue_Clr(void );
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

    image_queue_typedef imageQueue;

    QTimer *timer;

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
    void Pic_Data_Send(void);
signals:

};

#endif // MYPIC_H

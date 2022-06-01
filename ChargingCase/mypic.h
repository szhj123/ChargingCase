#ifndef MYPIC_H
#define MYPIC_H

#include <QWidget>
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>
#include <QFile>
#include <QListView>
#include <QString>
#include <QFileDialog>
#include <QMovie>
#include <QTimer>

typedef struct
{
    QImage *pImage;
    int    imageIndex;
    int    rowIndex;
    int    colIndex;
}image_data_s;

typedef struct
{
    image_data_s imageDataBuf[6];
    int head;
    int rear;
}image_queue_typedef;

class MyPic : public QWidget
{
    Q_OBJECT
public:
    explicit MyPic(QWidget *parent = nullptr);
    ~MyPic();

    void Pic_Init(Ui::MainWindow *ui);
    void Pic_Show(QImage *pImage, QLabel *pLabel );
    void Pic_Read_Rgb565(QImage *pImage, QByteArray pImageDataBuf );
    void Pic_Queue_Set(int imageIndex, QImage *imageSrc );
    uchar Pic_Queue_Get(image_data_s *imageData);
private:
    Ui::MainWindow *ui;
    QMovie *movie;
    QImage *image1Src;
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

    void Pic_Data_Send(void);
signals:

};

#endif // MYPIC_H

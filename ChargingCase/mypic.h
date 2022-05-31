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

class MyPic : public QWidget
{
    Q_OBJECT
public:
    explicit MyPic(QWidget *parent = nullptr);
    ~MyPic();

    void Pic_Init(Ui::MainWindow *ui);
    void Pic_Show(QImage *pImage, QLabel *pLabel );
    void Pic_Read_Rgb565(QImage *pImage, QByteArray pImageDataBuf );
private:
    Ui::MainWindow *ui;

    QImage *image_png1_src;
    QByteArray image_png1_buf;
private slots:
    void on_btnPng1_clicked(void);
signals:

};

#endif // MYPIC_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myserialport.h"
#include "myled.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QListView>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QString>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTabWidget();
    void show_imgage(QImage *pImage, QLabel *pLabel );
    void read_image_rgb565(QImage *pImage, QByteArray pImageDataBuf );
protected:
    void paintEvent(QPaintEvent *event );
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event );
    void mouseReleaseEvent(QMouseEvent *event );
private slots:

    void on_lineEdit_PngNum_textChanged(const QString &arg1);

    void on_btnPng1_clicked();

    void on_btnSerialOpen_clicked();

    void on_btnSerialRefresh_clicked();

    void on_btnSend_clicked();

    void on_cbxLedNum_currentIndexChanged(int index);

    void on_cbxLed1Mode_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    MySerialPort *mySerialPort;
    MyLed *myLed;
    QPoint last;
    QImage *image_png1_src;
    QByteArray image_png1_buf;
};
#endif // MAINWINDOW_H

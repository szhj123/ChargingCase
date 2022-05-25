#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QSerialPort>
#include <QSerialPortInfo>
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
    void scanSerialPort();
    void openSerial();
    void closeSerial();
    void setSerialEnable(bool enabled);
    void refreshSerial();
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

private:
    Ui::MainWindow *ui;
    QPoint last;
    QSerialPort *serialport;
    QImage *image_png1_src;
    QByteArray image_png1_buf;
};
#endif // MAINWINDOW_H

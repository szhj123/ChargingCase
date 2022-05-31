#ifndef MYLED_H
#define MYLED_H

#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMainWindow>

typedef enum
{
    LED1 = 1,
    LED2,
    LED3
}led_name_typedef;

typedef enum
{
    LED_SOLIED_ON = 0,
    LED_FLASH,
    LED_BREATH
}led_style_typedef;

typedef struct
{
    led_name_typedef ledName;
    led_style_typedef ledStyle;
    int ledOnTime;
    int ledOffTime;
    int ledBreathTime;
}led_typedef;

class MyLed : public QObject
{
    Q_OBJECT
public:
    explicit MyLed(QObject *parent = nullptr);
    void Led_Init(Ui::MainWindow *ui);
    void Led_Set_Enabled(Ui::MainWindow *ui, int index);
private:
    Ui::MainWindow *ui;
    led_typedef led1;
    led_typedef led2;
    led_typedef led3;
private slots:
    void on_cbxLedNum_currentIndexChanged(int index);
    void on_led1Btn_checked(bool checked);
    void on_led1StyleOn_checked(bool checked);
    void on_led1StyleFlash_checked(bool checked);
    void on_led1StyleBreath_checked(bool checked);
    void on_led1Slider_Changed(int value);

    void on_led2Btn_checked(bool checked);
    void on_led2StyleOn_checked(bool checked);
    void on_led2StyleFlash_checked(bool checked);
    void on_led2StyleBreath_checked(bool checked);
    void on_led2Slider_Changed(int value);

    void on_led3Btn_checked(bool checked);
    void on_led3StyleOn_checked(bool checked);
    void on_led3StyleFlash_checked(bool checked);
    void on_led3StyleBreath_checked(bool checked);
    void on_led3Slider_Changed(int value);

signals:

};

#endif // MYLED_H

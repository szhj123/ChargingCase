#ifndef MYLED_H
#define MYLED_H

#include "ui_mainwindow.h"
#include "myserialport.h"
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
    LED_SOLID_OFF = 0,
    LED_SOLID_ON,
    LED_FLASH_SLOW,
    LED_FLASH_REGULAR,
    LED_FLASH_QUICK,
    LED_BREATH
}led_style_typedef;

typedef struct
{
    led_name_typedef ledName;
    led_style_typedef ledStyle;
    int ledEnabled;
    int ledRegularOnTime;
    int ledRegularOffTime;
    int ledSlowOnTime;
    int ledSlowOffTime;
    int ledQuickOnTime;
    int ledQuickOffTime;
    int ledSpeed;
}led_typedef;

class MyLed : public QObject
{
    Q_OBJECT
public:
    explicit MyLed(QObject *parent = nullptr);
    void Led_Init(Ui::MainWindow *ui, MySerialPort *serialPort);
    void Led_Set_Enabled(Ui::MainWindow *ui, int index);
    void Led_Send(led_typedef *led );
    void Led_Set(led_typedef *led, led_name_typedef name, led_style_typedef style);
private:
    Ui::MainWindow *ui;
    MySerialPort *serialPort;
    led_typedef led1;
    led_typedef led2;
    led_typedef led3;
private slots:
    void on_cbxLedNum_currentIndexChanged(int index);
    void on_led1Btn_checked(bool checked);
    void on_led1StyleSolid_checked(bool checked);
    void on_led1StyleSlow_checked(bool checked);
    void on_led1StyleRegular_checked(bool checked);
    void on_led1StyleQuick_checked(bool checked);
    void on_led1StyleBreath_checked(bool checked);
    void on_led1Slider_Changed(int value);

    void on_led2Btn_checked(bool checked);
    void on_led2StyleSolid_checked(bool checked);
    void on_led2StyleFlash_checked(bool checked);
    void on_led2StyleBreath_checked(bool checked);
    void on_led2Slider_Changed(int value);

    void on_led3Btn_checked(bool checked);
    void on_led3StyleSolid_checked(bool checked);
    void on_led3StyleFlash_checked(bool checked);
    void on_led3StyleBreath_checked(bool checked);
    void on_led3Slider_Changed(int value);

    void on_led4Btn_checked(bool checked);
    void on_led4StyleSolid_checked(bool checked);
    void on_led4StyleFlash_checked(bool checked);
    void on_led4StyleBreath_checked(bool checked);
    void on_led4Slider_Changed(int value);

signals:

};

#endif // MYLED_H

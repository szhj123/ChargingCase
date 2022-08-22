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
    LED3,
    LED4
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
    led_typedef led4;
private slots:
    void on_lineEditSlowOn_changed(const QString &);
    void on_lineEditSlowOff_changed(const QString &);
    void on_lineEditRegularOn_changed(const QString &);
    void on_lineEditRegularOff_changed(const QString &);
    void on_lineEditQuickOn_changed(const QString &);
    void on_lineEditQuickOff_changed(const QString &);
    void on_sliderBreathSpeed_changed(int value);

    void on_led1Btn_checked(bool checked);
    void on_led1StyleSolid_checked(bool checked);
    void on_led1StyleSlow_checked(bool checked);
    void on_led1StyleRegular_checked(bool checked);
    void on_led1StyleQuick_checked(bool checked);
    void on_led1StyleBreath_checked(bool checked);

    void on_led2Btn_checked(bool checked);
    void on_led2StyleSolid_checked(bool checked);
    void on_led2StyleSlow_checked(bool checked);
    void on_led2StyleRegular_checked(bool checked);
    void on_led2StyleQuick_checked(bool checked);
    void on_led2StyleBreath_checked(bool checked);

    void on_led3Btn_checked(bool checked);
    void on_led3StyleSolid_checked(bool checked);
    void on_led3StyleSlow_checked(bool checked);
    void on_led3StyleRegular_checked(bool checked);
    void on_led3StyleQuick_checked(bool checked);
    void on_led3StyleBreath_checked(bool checked);

    void on_led4Btn_checked(bool checked);
    void on_led4StyleSolid_checked(bool checked);
    void on_led4StyleSlow_checked(bool checked);
    void on_led4StyleRegular_checked(bool checked);
    void on_led4StyleQuick_checked(bool checked);
    void on_led4StyleBreath_checked(bool checked);

signals:

};

#endif // MYLED_H

#include "myled.h"
#include "mybtn.h"


MyLed::MyLed(QObject *parent) : QObject(parent)
{

}

void MyLed::Led_Init(Ui::MainWindow *ui, MySerialPort *serialPort)
{
    this->ui = ui;
    this->serialPort = serialPort;

    QDoubleValidator* lineDouble = new QDoubleValidator(0, 100000, 3, nullptr);

    ui->lineEditRegularOn->setValidator(lineDouble);
    ui->lineEditRegularOff->setValidator(lineDouble);
    ui->lineEditSlowOn->setValidator(lineDouble);
    ui->lineEditSlowOff->setValidator(lineDouble);
    ui->lineEditQuickOn->setValidator(lineDouble);
    ui->lineEditQuickOff->setValidator(lineDouble);

    connect(ui->led1Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led1Btn_checked(bool)));
    connect(ui->led1StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleSolid_checked(bool)));
    connect(ui->led1StyleSlow, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleSlow_checked(bool)));
    connect(ui->led1StyleRegular, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleRegular_checked(bool)));
    connect(ui->led1StyleQuick, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleQuick_checked(bool)));
    connect(ui->led1StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleBreath_checked(bool)));

    connect(ui->led2Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led2Btn_checked(bool)));
    connect(ui->led2StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleSolid_checked(bool)));
    connect(ui->led2StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleBreath_checked(bool)));

    connect(ui->led3Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led3Btn_checked(bool)));
    connect(ui->led3StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleSolid_checked(bool)));
    connect(ui->led3StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleBreath_checked(bool)));

    connect(ui->led4Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led4Btn_checked(bool)));
    connect(ui->led4StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleSolid_checked(bool)));
    connect(ui->led4StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleBreath_checked(bool)));
}

void MyLed::Led_Set_Enabled(Ui::MainWindow *ui, int index)
{
    switch(index)
    {
        case 0:
        {
            ui->led1Group->show();
            ui->led2Group->hide();
            ui->led3Group->hide();

            break;
        }
        case 1:
        {
            ui->led1Group->hide();
            ui->led1Group->show();
            ui->led2Group->show();
            break;
        }
         case 2:
        {
            ui->led1Group->show();
            ui->led2Group->show();
            ui->led3Group->show();
            break;
        }
        default:
            break;
    }
}

void MyLed::Led_Send(led_typedef *led)
{
    static char buf[20] = {0};
    char checksum = 0;

    buf[0] = 0x5a;
    buf[1] = 0x5a;
    buf[2] = 0x11;
    buf[3] = 0x1;
    buf[4] = (char )led->ledName;
    buf[5] = (char )led->ledStyle;
    buf[6] = (char )led->ledSlowOnTime;
    buf[7] = (char )(led->ledSlowOnTime >> 8);
    buf[8] = (char )led->ledSlowOffTime;
    buf[9] = (char )(led->ledSlowOffTime >> 8);
    buf[10] = (char )led->ledRegularOnTime;
    buf[11] = (char )(led->ledRegularOnTime >> 8);
    buf[12] = (char )led->ledRegularOffTime;
    buf[13] = (char )(led->ledRegularOffTime >> 8);
    buf[14] = (char )led->ledQuickOnTime;
    buf[15] = (char )(led->ledQuickOnTime >> 8);
    buf[16] = (char )led->ledQuickOffTime;
    buf[17] = (char )(led->ledQuickOffTime >> 8);
    buf[18] = led->ledSpeed;

    for(int i = 0;i<buf[2];i++)
    {
        checksum += buf[i+2];
    }

    buf[19] = (char)checksum;

    serialPort->Serial_Port_Send_Data(buf, sizeof(buf));

}

void MyLed::Led_Set(led_typedef *led, led_name_typedef name, led_style_typedef style )
{
    led->ledName = name;
    led->ledStyle = style;
    led->ledRegularOnTime = ui->lineEditRegularOn->text().toInt();
    led->ledRegularOffTime = ui->lineEditRegularOff->text().toInt();
    led->ledSlowOnTime = ui->lineEditSlowOn->text().toInt();
    led->ledSlowOffTime = ui->lineEditSlowOff->text().toInt();
    led->ledQuickOnTime = ui->lineEditQuickOn->text().toInt();
    led->ledQuickOffTime = ui->lineEditQuickOff->text().toInt();
    led->ledSpeed = ui->sliderBreathSpeed->value();
}

void MyLed::on_cbxLedNum_currentIndexChanged(int index)
{
    Led_Set_Enabled(ui, index);
}

void MyLed::on_led1Btn_checked(bool checked)
{
    if(checked)
    {
        bool led1BtnChecked = ui->led1StyleSolid->isChecked() | ui->led1StyleSlow->isChecked() | ui->led1StyleRegular->isChecked() |\
                              ui->led1StyleQuick->isChecked() |ui->led1StyleBreath->isChecked();

        if(led1BtnChecked == false)
        {
            ui->led1StyleSolid->setChecked(true);

            Led_Set(&led1, LED1, LED_SOLID_ON);
        }
        else
        {
            if(ui->led1StyleSolid->isChecked())
            {
                Led_Set(&led1, LED1, LED_SOLID_ON);
            }
            else if(ui->led1StyleSlow->isChecked())
            {
                Led_Set(&led1, LED1, LED_FLASH_SLOW);
            }
            else if(ui->led1StyleRegular->isChecked())
            {
                Led_Set(&led1, LED1, LED_FLASH_REGULAR);
            }
            else if(ui->led1StyleQuick->isChecked())
            {
                Led_Set(&led1, LED1, LED_FLASH_QUICK);
            }
            else if(ui->led1StyleBreath->isChecked())
            {
                Led_Set(&led1, LED1, LED_BREATH);
            }
        }
    }
    else
    {
        Led_Set(&led1, LED1, LED_SOLID_OFF);
    }

    Led_Send(&led1);

}

void MyLed::on_led1StyleSolid_checked(bool checked)
{
    qDebug() << "led flash solid pressed on";

}

void MyLed::on_led1StyleSlow_checked(bool checked)
{
    qDebug() << "led flash slow pressed on";
}

void MyLed::on_led1StyleRegular_checked(bool checked)
{
    qDebug() << "led flash regular pressed on";
}

void MyLed::on_led1StyleQuick_checked(bool checked)
{
    qDebug() << "led flash quick pressed on";
}

void MyLed::on_led1StyleBreath_checked(bool checked)
{

}

void MyLed::on_led1Slider_Changed(int value)
{
    QString text = QString::number(value, 10);
    text += "s";
}

void MyLed::on_led2Btn_checked(bool checked)
{
    if(checked)
    {
        bool led1BtnChecked = ui->led2StyleSolid->isChecked() | ui->led2StyleSlow->isChecked() |\
                              ui->led2StyleRegular->isChecked() | ui->led2StyleQuick->isChecked() | ui->led2StyleBreath->isChecked();

        if(led1BtnChecked == false)
        {
            ui->led2StyleSolid->setChecked(true);

            Led_Set(&led2, LED2, LED_SOLID_ON);
        }
        else
        {
            if(ui->led2StyleSolid->isChecked())
            {
                Led_Set(&led2, LED2, LED_SOLID_ON);
            }
            else if(ui->led2StyleSlow->isChecked())
            {
                Led_Set(&led2, LED2, LED_FLASH_SLOW);
            }
            else if(ui->led2StyleRegular->isChecked())
            {
                Led_Set(&led2, LED2, LED_FLASH_REGULAR);
            }
            else if(ui->led2StyleQuick->isChecked())
            {
                Led_Set(&led2, LED2, LED_FLASH_QUICK);
            }
            else if(ui->led2StyleBreath->isChecked())
            {
                Led_Set(&led2, LED2, LED_BREATH);
            }
        }
    }
    else
    {
        Led_Set(&led2, LED2, LED_SOLID_OFF);
    }
}

void MyLed::on_led2StyleSolid_checked(bool checked)
{

}

void MyLed::on_led2StyleFlash_checked(bool checked)
{

}

void MyLed::on_led2StyleBreath_checked(bool checked)
{

}

void MyLed::on_led2Slider_Changed(int value)
{
    QString text = QString::number(value, 10);
    text += "s";
}

void MyLed::on_led3Btn_checked(bool checked)
{
    if(checked)
    {
        bool led1BtnChecked = ui->led3StyleSolid->isChecked() | ui->led3StyleSlow->isChecked() |\
                              ui->led3StyleRegular->isChecked() | ui->led3StyleQuick->isChecked() | ui->led3StyleBreath->isChecked();


        if(led1BtnChecked == false)
        {
            ui->led3StyleSolid->setChecked(true);

            Led_Set(&led3, LED3, LED_SOLID_ON);
        }
        else
        {
            if(ui->led3StyleSolid->isChecked())
            {
                if(ui->led3StyleSolid->isChecked())
                {
                    Led_Set(&led3, LED3, LED_SOLID_ON);
                }
                else if(ui->led3StyleSlow->isChecked())
                {
                    Led_Set(&led3, LED3, LED_FLASH_SLOW);
                }
                else if(ui->led3StyleRegular->isChecked())
                {
                    Led_Set(&led3, LED3, LED_FLASH_REGULAR);
                }
                else if(ui->led3StyleQuick->isChecked())
                {
                    Led_Set(&led3, LED3, LED_FLASH_QUICK);
                }
                else if(ui->led3StyleBreath->isChecked())
                {
                    Led_Set(&led3, LED3, LED_BREATH);
                }
            }

        }
    }
    else
    {

    }
}

void MyLed::on_led3StyleSolid_checked(bool checked)
{

}

void MyLed::on_led3StyleFlash_checked(bool checked)
{

}

void MyLed::on_led3StyleBreath_checked(bool checked)
{

}

void MyLed::on_led3Slider_Changed(int value)
{
    QString text = QString::number(value, 10);
    text += "s";
}

void MyLed::on_led4Btn_checked(bool checked)
{

}

void MyLed::on_led4StyleSolid_checked(bool checked)
{

}

void MyLed::on_led4StyleFlash_checked(bool checked)
{

}

void MyLed::on_led4StyleBreath_checked(bool checked)
{

}

void MyLed::on_led4Slider_Changed(int value)
{

}







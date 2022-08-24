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

    connect(ui->lineEditSlowOn, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditSlowOn_changed(const QString &)));
    connect(ui->lineEditSlowOff, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditSlowOff_changed(const QString &)));
    connect(ui->lineEditRegularOn, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditRegularOn_changed(const QString &)));
    connect(ui->lineEditRegularOff, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditRegularOff_changed(const QString &)));
    connect(ui->lineEditQuickOn, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditQuickOn_changed(const QString &)));
    connect(ui->lineEditQuickOff, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEditQuickOff_changed(const QString &)));
    //connect(ui->sliderBreathSpeed, SIGNAL(valueChanged(int value)), this, SLOT(on_sliderBreathSpeed_changed(int value)));

    connect(ui->led1Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led1Btn_checked(bool)));
    connect(ui->led1StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleSolid_checked(bool)));
    connect(ui->led1StyleSlow, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleSlow_checked(bool)));
    connect(ui->led1StyleRegular, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleRegular_checked(bool)));
    connect(ui->led1StyleQuick, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleQuick_checked(bool)));
    connect(ui->led1StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led1StyleBreath_checked(bool)));

    connect(ui->led2Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led2Btn_checked(bool)));
    connect(ui->led2StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleSolid_checked(bool)));
    connect(ui->led2StyleSlow, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleSlow_checked(bool)));
    connect(ui->led2StyleRegular, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleRegular_checked(bool)));
    connect(ui->led2StyleQuick, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleQuick_checked(bool)));
    connect(ui->led2StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led2StyleBreath_checked(bool)));

    connect(ui->led3Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led3Btn_checked(bool)));
    connect(ui->led3StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleSolid_checked(bool)));
    connect(ui->led3StyleSlow, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleSlow_checked(bool)));
    connect(ui->led3StyleRegular, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleRegular_checked(bool)));
    connect(ui->led3StyleQuick, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleQuick_checked(bool)));
    connect(ui->led3StyleBreath, SIGNAL(clicked(bool)), this, SLOT(on_led3StyleBreath_checked(bool)));

    connect(ui->led4Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_led4Btn_checked(bool)));
    connect(ui->led4StyleSolid, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleSolid_checked(bool)));
    connect(ui->led4StyleSlow, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleSlow_checked(bool)));
    connect(ui->led4StyleRegular, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleRegular_checked(bool)));
    connect(ui->led4StyleQuick, SIGNAL(clicked(bool)), this, SLOT(on_led4StyleQuick_checked(bool)));
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

void MyLed::on_lineEditSlowOn_changed(const QString &)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledSlowOnTime = ui->lineEditSlowOn->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledSlowOnTime = ui->lineEditSlowOn->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledSlowOnTime = ui->lineEditSlowOn->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledSlowOnTime = ui->lineEditSlowOn->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_lineEditSlowOff_changed(const QString &)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledSlowOffTime = ui->lineEditSlowOff->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledSlowOffTime = ui->lineEditSlowOff->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledSlowOffTime = ui->lineEditSlowOff->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledSlowOffTime = ui->lineEditSlowOff->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_lineEditRegularOn_changed(const QString &)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledRegularOnTime = ui->lineEditRegularOn->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledRegularOnTime = ui->lineEditRegularOn->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledRegularOnTime = ui->lineEditRegularOn->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledRegularOnTime = ui->lineEditRegularOn->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_lineEditRegularOff_changed(const QString &)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledRegularOffTime = ui->lineEditRegularOff->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledRegularOffTime = ui->lineEditRegularOff->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledRegularOffTime = ui->lineEditRegularOff->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledRegularOffTime = ui->lineEditRegularOff->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_lineEditQuickOn_changed(const QString &text)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledQuickOnTime = ui->lineEditQuickOn->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledQuickOnTime = ui->lineEditQuickOn->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledQuickOnTime = ui->lineEditQuickOn->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledQuickOnTime = ui->lineEditQuickOn->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_lineEditQuickOff_changed(const QString &)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledQuickOffTime = ui->lineEditQuickOff->text().toInt();
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledQuickOffTime = ui->lineEditQuickOff->text().toInt();
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledQuickOffTime = ui->lineEditQuickOff->text().toInt();
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledQuickOffTime = ui->lineEditQuickOff->text().toInt();
        Led_Send(&led4);
    }
}

void MyLed::on_sliderBreathSpeed_changed(int value)
{
    if(ui->led1Btn->Get_Checked())
    {
        led1.ledSpeed = value;
        Led_Send(&led1);
    }
    else if(ui->led2Btn->Get_Checked())
    {
        led2.ledSpeed = value;
        Led_Send(&led2);
    }
    else if(ui->led3Btn->Get_Checked())
    {
        led3.ledSpeed = value;
        Led_Send(&led3);
    }
    else if(ui->led4Btn->Get_Checked())
    {
        led4.ledSpeed = value;
        Led_Send(&led4);
    }
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
    Led_Set(&led1, LED1, LED_SOLID_ON);
    Led_Send(&led1);
}

void MyLed::on_led1StyleSlow_checked(bool checked)
{
    Led_Set(&led1, LED1, LED_FLASH_SLOW);
    Led_Send(&led1);
}

void MyLed::on_led1StyleRegular_checked(bool checked)
{
    Led_Set(&led1, LED1, LED_FLASH_REGULAR);
    Led_Send(&led1);
}

void MyLed::on_led1StyleQuick_checked(bool checked)
{
    Led_Set(&led1, LED1, LED_FLASH_QUICK);
    Led_Send(&led1);
}

void MyLed::on_led1StyleBreath_checked(bool checked)
{
    Led_Set(&led1, LED1, LED_BREATH);
    Led_Send(&led1);
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

    Led_Send(&led2);
}

void MyLed::on_led2StyleSolid_checked(bool checked)
{
    Led_Set(&led2, LED2, LED_SOLID_ON);
    Led_Send(&led2);
}

void MyLed::on_led2StyleSlow_checked(bool checked)
{
    Led_Set(&led2, LED2, LED_FLASH_SLOW);
    Led_Send(&led2);
}

void MyLed::on_led2StyleRegular_checked(bool checked)
{
    Led_Set(&led2, LED2, LED_FLASH_REGULAR);
    Led_Send(&led2);
}

void MyLed::on_led2StyleQuick_checked(bool checked)
{
    Led_Set(&led2, LED2, LED_FLASH_QUICK);
    Led_Send(&led2);
}

void MyLed::on_led2StyleBreath_checked(bool checked)
{
    Led_Set(&led2, LED2, LED_BREATH);
    Led_Send(&led2);
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
        Led_Set(&led3, LED3, LED_SOLID_OFF);
    }

    Led_Send(&led3);
}

void MyLed::on_led3StyleSolid_checked(bool checked)
{
    Led_Set(&led3, LED3, LED_SOLID_ON);
    Led_Send(&led3);
}

void MyLed::on_led3StyleSlow_checked(bool checked)
{
    Led_Set(&led3, LED3, LED_FLASH_SLOW);
    Led_Send(&led3);
}

void MyLed::on_led3StyleRegular_checked(bool checked)
{
    Led_Set(&led3, LED3, LED_FLASH_REGULAR);
    Led_Send(&led3);
}

void MyLed::on_led3StyleQuick_checked(bool checked)
{
    Led_Set(&led3, LED3, LED_FLASH_QUICK);
    Led_Send(&led3);
}

void MyLed::on_led3StyleBreath_checked(bool checked)
{
    Led_Set(&led3, LED3, LED_BREATH);
    Led_Send(&led3);
}


void MyLed::on_led4Btn_checked(bool checked)
{
    if(checked)
    {
        bool led1BtnChecked = ui->led4StyleSolid->isChecked() | ui->led4StyleSlow->isChecked() |\
                              ui->led4StyleRegular->isChecked() | ui->led4StyleQuick->isChecked() | ui->led4StyleBreath->isChecked();


        if(led1BtnChecked == false)
        {
            ui->led4StyleSolid->setChecked(true);

            Led_Set(&led4, LED4, LED_SOLID_ON);
        }
        else
        {
            if(ui->led4StyleSolid->isChecked())
            {
                if(ui->led4StyleSolid->isChecked())
                {
                    Led_Set(&led4, LED4, LED_SOLID_ON);
                }
                else if(ui->led4StyleSlow->isChecked())
                {
                    Led_Set(&led4, LED4, LED_FLASH_SLOW);
                }
                else if(ui->led4StyleRegular->isChecked())
                {
                    Led_Set(&led4, LED4, LED_FLASH_REGULAR);
                }
                else if(ui->led4StyleQuick->isChecked())
                {
                    Led_Set(&led4, LED4, LED_FLASH_QUICK);
                }
                else if(ui->led4StyleBreath->isChecked())
                {
                    Led_Set(&led4, LED4, LED_BREATH);
                }
            }

        }
    }
    else
    {
        Led_Set(&led4, LED4, LED_SOLID_OFF);
    }

    Led_Send(&led4);
}

void MyLed::on_led4StyleSolid_checked(bool checked)
{
    Led_Set(&led4, LED4, LED_SOLID_ON);
    Led_Send(&led4);
}

void MyLed::on_led4StyleSlow_checked(bool checked)
{
    Led_Set(&led4, LED4, LED_FLASH_SLOW);
    Led_Send(&led4);
}

void MyLed::on_led4StyleRegular_checked(bool checked)
{
    Led_Set(&led4, LED4, LED_FLASH_REGULAR);
    Led_Send(&led4);
}

void MyLed::on_led4StyleQuick_checked(bool checked)
{
    Led_Set(&led4, LED4, LED_FLASH_QUICK);
    Led_Send(&led4);
}


void MyLed::on_led4StyleBreath_checked(bool checked)
{
    Led_Set(&led4, LED4, LED_BREATH);
    Led_Send(&led4);
}








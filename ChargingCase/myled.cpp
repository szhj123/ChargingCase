#include "myled.h"
#include "mybtn.h"

MyLed::MyLed(QObject *parent) : QObject(parent)
{

}

void MyLed::Led_Init(Ui::MainWindow *ui)
{
    this->ui = ui;

    connect(ui->cbxLedNum, SIGNAL(currentIndexChanged(int )), this, SLOT(on_cbxLedNum_currentIndexChanged(int)));

    connect(ui->led1Btn, SIGNAL(checkedChanged(bool)), this, SLOT(on_le1Btn_checked(bool)));

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

void MyLed::on_cbxLedNum_currentIndexChanged(int index)
{
    Led_Set_Enabled(ui, index);
}

void MyLed::on_le1Btn_checked(bool checked)
{
    if(checked)
    {
        ui->led1StyleOn->setEnabled(true);
        ui->led1StyleFlash->setEnabled(true);
        ui->led1StyleBreath->setEnabled(true);

        bool led1BtnChecked = ui->led1StyleOn->isChecked() | ui->led1StyleFlash->isChecked() | ui->led1StyleBreath->isChecked();

        if(led1BtnChecked == false)
        {
            ui->led1StyleOn->setChecked(true);

            led1.ledName = LED1;
            led1.ledStyle = LED_SOLIED_ON;
            led1.ledOnTime = 0;
            led1.ledOffTime = 0;
            led1.ledBreathTime = 0;
        }
        else
        {
            if(ui->led1StyleOn->isChecked())
            {
                led1.ledName = LED1;
                led1.ledStyle = LED_SOLIED_ON;
                led1.ledOnTime = 0;
                led1.ledOffTime = 0;
                led1.ledBreathTime = 0;
            }
            else if(ui->led1StyleFlash->isChecked())
            {
                led1.ledName = LED1;
                led1.ledStyle = LED_FLASH;
                led1.ledOnTime = ui->led1OnTime->text().toInt();
                led1.ledOffTime = ui->led1OffTime->text().toInt();
                led1.ledBreathTime = 0;
            }
            else
            {

            }

        }
    }
    else
    {
        ui->led1StyleOn->setDisabled(true);
        ui->led1StyleFlash->setDisabled(true);
        ui->led1StyleBreath->setDisabled(true);
    }
}



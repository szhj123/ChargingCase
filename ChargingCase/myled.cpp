#include "myled.h"

MyLed::MyLed(QObject *parent) : QObject(parent)
{

}

void MyLed::Set_Led_Enabled(Ui::MainWindow *ui, int index)
{
    switch(index)
    {
        case 0:
        {
            ui->ledWidget1->show();
            ui->ledWidget2->hide();
            ui->ledWidget3->hide();
            break;
        }
        case 1:
        {
            ui->ledWidget2->show();
            break;
        }
         case 2:
        {
            ui->ledWidget3->show();
            break;
        }
        default:
            break;
    }
}

void MyLed::Set_Led_Mode(Ui::MainWindow *ui, int index)
{
    switch(index)
    {
        case 0:
        {
            ui->led1OnTime->setEnabled(false);
            ui->led1OffTime->setEnabled(false);
            break;
        }
        case 1:
        {
            ui->led1OnTime->setEnabled(false);
            ui->led1OffTime->setEnabled(false);
            break;
        }
         case 2:
        {
            ui->led1OnTime->setEnabled(true);
            ui->led1OffTime->setEnabled(true);

            break;
        }
        case 3:
        {

        }
        default:
            break;
    }
}

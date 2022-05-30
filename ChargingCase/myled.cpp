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

            break;
        }
        case 1:
        {

            break;
        }
         case 2:
        {
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
            break;
        }
        case 1:
        {
            break;
        }
         case 2:
        {

            break;
        }
        case 3:
        {

        }
        default:
            break;
    }
}

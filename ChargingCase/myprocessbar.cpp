#include "myprocessbar.h"

MyProcessBar::MyProcessBar(QWidget *parent) : QWidget(parent)
{
    bgColor = QColor(85, 125, 200);
    processBgColor = QColor(255, 255, 255);
    processPieColor = QColor(51, 254, 255);
    textColor = QColor(255, 255, 255);

    marginVal = 15;

    minVal = 0;
    maxVal = 100;
    currVal = 0;

    processWidth = 10;

    setMinimumSize(50, 50);
}

MyProcessBar::~MyProcessBar()
{

}

void MyProcessBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    Draw_Process(&painter);

    Draw_Text(&painter);
}

void MyProcessBar::Draw_Process(QPainter *painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int diameter = qMin(width, height);

    QRect rectCircle(0, 0, diameter, diameter);

    painter->setBrush(bgColor);
    painter->drawEllipse(rectCircle);

    QColor processColor = currVal > 0 ? processPieColor : processBgColor;

    QPen pen;
    pen.setWidth(processWidth);
    pen.setColor(processColor);
    painter->setBrush(Qt::NoBrush);
    painter->setPen(pen);
    painter->drawEllipse(marginVal, marginVal, diameter-marginVal*2, diameter-marginVal*2);


    painter->restore();

}

void MyProcessBar::Draw_Text(QPainter *painter)
{

}

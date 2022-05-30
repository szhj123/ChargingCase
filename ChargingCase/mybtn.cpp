#include "mybtn.h"

MyBtn::MyBtn(QWidget *parent) : QWidget(parent)
{
    bgOnColor = QColor(51, 254, 255);
    bgOffColor = QColor(128, 128, 128);
    sliderOnColor = QColor(96, 96, 96);

    textOnColor = QColor(255, 255, 255);
    textOffColor = QColor(240, 240, 240);

    btnStyle = BTN_STYLE_SQUARE;

    marginVal = 2;
    sliderStartX = 0;
    sliderEndX = 0;
    stepVal = width()/10;

    checked = false;
    animationEnabled = true;

    timer = new QTimer(this);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update_Val()));

}

MyBtn::~MyBtn()
{

}

void MyBtn::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    Draw_Bg(&painter);

    Draw_Slider(&painter);
}

void MyBtn::mousePressEvent(QMouseEvent *event)
{
    int width = this->width();
    int height = this->height();

    checked = !checked;

    emit checkedChanged(checked);

    if(checked)
    {
        sliderEndX = width - height;
        timer->start();
    }
    else
    {
        sliderEndX = 0;
        timer->start();
    }
}

void MyBtn::mouseReleaseEvent(QMouseEvent *event)
{

}

void MyBtn::Draw_Bg(QPainter *painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int diameter = qMin(width, height);

    QColor bgColor = checked ? bgOnColor : bgOffColor;
    QColor textColor = checked ? textOnColor : textOffColor;

    QRect rect(0, 0, width, height);

    if(btnStyle == BTN_STYLE_CIRCLE)
    {
        QPainterPath path1;
        path1.addEllipse(rect.x(), rect.y(), diameter, diameter);
        QPainterPath path2;
        path2.addRect(rect.x()+diameter/2, rect.y(), width-diameter, rect.height());
        QPainterPath path3;
        path3.addEllipse(rect.width()-diameter, rect.y(), diameter, diameter);
        QPainterPath path = path1 + path2 + path3;

        painter->setBrush(bgColor);
        painter->drawPath(path);
    }
    else
    {
        painter->setBrush(bgColor);
        painter->drawRect(rect);
    }

    QPen pen;
    pen.setColor(textColor);
    pen.setWidth(5);
    QFont font;
    font.setFamily(tr("微软雅黑"));
    font.setBold(true);
    painter->setFont(font);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    if(checked)
    {
        QRect rectText(rect.x(), rect.y(), width-diameter, height);
        painter->drawText(rectText, Qt::AlignCenter, tr("ON"));
    }
    else
    {
        QRect rectText(diameter, rect.y(), width-diameter, height);
        painter->drawText(rectText, Qt::AlignCenter, tr("OFF"));
    }

    painter->restore();

}

void MyBtn::Draw_Slider(QPainter *painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int diameter = qMin(width, height)- marginVal * 2;

    QRect rectSlider(marginVal+sliderStartX, marginVal, diameter, diameter);

    //创建了一个QRadialGradient对象实例，参数分别为中心坐标，半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致
    QRadialGradient radialGradient(sliderStartX + marginVal + diameter / 2,
                                   marginVal+diameter/2,
                                   diameter/2,
                                   sliderStartX+marginVal+diameter/2,
                                   marginVal+diameter/2);

    if(checked)
    {
        radialGradient.setColorAt(0,Qt::black);
        radialGradient.setColorAt(1.0,QColor(51, 254, 255));
    }
    else
    {
        radialGradient.setColorAt(0,Qt::black);
        radialGradient.setColorAt(1.0,Qt::white);
    }

    painter->setBrush(radialGradient);
    if(btnStyle == BTN_STYLE_CIRCLE)
        painter->drawEllipse(rectSlider);
    else
        painter->drawRect(rectSlider);

    painter->restore();
}

void MyBtn::Update_Val()
{
    if(checked)
    {
        sliderStartX += stepVal;

        if(sliderStartX >= sliderEndX)
        {
            sliderStartX = sliderEndX;
            timer->stop();
        }
    }
    else
    {
        sliderStartX -= stepVal;

        if(sliderStartX <= sliderEndX)
        {
            sliderStartX = sliderEndX;
            timer->stop();
        }
    }

    update();
}

#ifndef MYPROCESSBAR_H
#define MYPROCESSBAR_H

#include <QWidget>
#include <QPainter>

class MyProcessBar : public QWidget
{
    Q_OBJECT
public:
    explicit MyProcessBar(QWidget *parent = nullptr);
    ~MyProcessBar();
protected:
    void paintEvent(QPaintEvent *event);
    void Draw_Process(QPainter *painter);
    void Draw_Text(QPainter *painter);
private:
    int minVal;
    int maxVal;
    int currVal;

    int processWidth;
    int marginVal;

    QColor bgColor;
    QColor processPieColor;
    QColor processBgColor;
    QColor textColor;




signals:

};

#endif // MYPROCESSBAR_H

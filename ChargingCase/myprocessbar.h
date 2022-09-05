#ifndef MYPROCESSBAR_H
#define MYPROCESSBAR_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class MyProcessBar : public QWidget
{
    Q_OBJECT
public:
    explicit MyProcessBar(QWidget *parent = nullptr);
    ~MyProcessBar();
    void Update_Val(uint8_t val);
protected:
    void paintEvent(QPaintEvent *event);
    void Draw_Process(QPainter *painter);
    void Draw_Text(QPainter *painter);

private:
    int minVal;
    int maxVal;
    int currVal;

    int processWidth;
    int textWidth;
    int marginVal;

    QColor bgColor;
    QColor processPieColor;
    QColor processBgColor;
    QColor textColor;

private slots:

signals:

};

#endif // MYPROCESSBAR_H

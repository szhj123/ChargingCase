#ifndef MYBTN_H
#define MYBTN_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

typedef enum
{
    BTN_STYLE_SQUARE = 0,
    BTN_STYLE_CIRCLE
}btnStyle_typedef;

class MyBtn : public QWidget
{
    Q_OBJECT
public:
    explicit MyBtn(QWidget *parent = nullptr);
    ~MyBtn();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void Draw_Bg(QPainter *painter);
    void Draw_Slider(QPainter *painter);
private:
    QColor bgOnColor;
    QColor bgOffColor;
    QColor sliderOnColor;
    QColor sliderOffColor;
    QColor textOnColor;
    QColor textOffColor;

    int marginVal;
    int sliderStartX;
    int sliderEndX;
    int stepVal;

    bool checked;
    bool animationEnabled;

    btnStyle_typedef btnStyle;
    QTimer *timer;

private slots:
    void Update_Val(void );
public:
    bool Get_Checked(void );

signals:
    void checkedChanged(bool checked);

};

#endif // MYBTN_H

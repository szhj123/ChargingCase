/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myprocessbar.h>
#include "mybtn.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_logo;
    QLabel *labelLogoText;
    QPushButton *pushButton_close;
    QPushButton *pushButton_min;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *labelLogoPic;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QLabel *labelLedNum;
    QComboBox *cbxLedNum;
    QGroupBox *led1Group;
    MyBtn *led1Btn;
    QWidget *led1Attribute;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *led1StyleOn;
    QRadioButton *led1StyleFlash;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *led1OnTime;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *led1OffTime;
    QLabel *label_4;
    QRadioButton *led1StyleBreath;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSlider *led1Slider;
    QLabel *led1SliderValue;
    QGroupBox *led2Group;
    MyBtn *led2Btn;
    QWidget *widget_6;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *led2StyleOn;
    QRadioButton *led2StyleFlash;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *led2OnTime;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *led2OffTime;
    QLabel *label_13;
    QRadioButton *led2StyleBreath;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QSlider *led2Slider;
    QLabel *led2SliderValue;
    QGroupBox *led3Group;
    MyBtn *led3Btn;
    QWidget *widget_7;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *led3StyleOn;
    QRadioButton *led3StyleFlash;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QLineEdit *led3OnTime;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_19;
    QLineEdit *led3OffTime;
    QLabel *label_20;
    QRadioButton *led3StyleBreath;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QSlider *led3Slider;
    QLabel *led3SliderValue;
    QWidget *tab2;
    QLabel *label_24;
    QLabel *labelPng1;
    QPushButton *btnDownload1;
    QLabel *labelPng4;
    QPushButton *btnPng4;
    QPushButton *btnDownload4;
    QLabel *labelPng2;
    QLabel *labelPng3;
    QPushButton *btnPng2;
    QPushButton *btnDownload2;
    QPushButton *btnPng3;
    QPushButton *btnDownload3;
    QLabel *labelPng5;
    QLabel *labelPng6;
    QPushButton *btnPng5;
    QPushButton *btnDownload5;
    QPushButton *btnDownload6;
    QPushButton *btnPng6;
    QPushButton *btnPng1;
    QWidget *tab3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_5;
    QLabel *label_26;
    QLabel *label_27;
    MyProcessBar *widget_2;
    QWidget *tab4;
    QGroupBox *groupBoxSerial;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *boxBaudRate;
    QLabel *labelStopBits;
    QComboBox *boxStopBits;
    QLabel *labelPortName;
    QComboBox *boxPortName;
    QLabel *labelDataBits;
    QComboBox *boxParity;
    QComboBox *boxDataBits;
    QLabel *labelParity;
    QLabel *labelBaudRate;
    QLabel *labelFlowControl;
    QComboBox *boxFlowControl;
    QPushButton *btnSerialOpen;
    QPushButton *btnSerialRefresh;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 400);
        MainWindow->setMinimumSize(QSize(640, 400));
        MainWindow->setMaximumSize(QSize(640, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_logo = new QWidget(centralwidget);
        widget_logo->setObjectName(QString::fromUtf8("widget_logo"));
        widget_logo->setGeometry(QRect(0, 0, 640, 35));
        widget_logo->setMaximumSize(QSize(640, 60));
        labelLogoText = new QLabel(widget_logo);
        labelLogoText->setObjectName(QString::fromUtf8("labelLogoText"));
        labelLogoText->setGeometry(QRect(80, 2, 341, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(14);
        labelLogoText->setFont(font);
        pushButton_close = new QPushButton(widget_logo);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(610, 10, 21, 20));
        pushButton_min = new QPushButton(widget_logo);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(580, 10, 21, 20));
        label_28 = new QLabel(widget_logo);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(380, 0, 31, 41));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_29 = new QLabel(widget_logo);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(410, 10, 41, 21));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_30 = new QLabel(widget_logo);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(460, 0, 31, 41));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_31 = new QLabel(widget_logo);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(490, 10, 41, 21));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelLogoPic = new QLabel(widget_logo);
        labelLogoPic->setObjectName(QString::fromUtf8("labelLogoPic"));
        labelLogoPic->setGeometry(QRect(10, 2, 61, 31));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(170, 50, 460, 321));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        labelLedNum = new QLabel(tab1);
        labelLedNum->setObjectName(QString::fromUtf8("labelLedNum"));
        labelLedNum->setGeometry(QRect(10, 10, 51, 20));
        labelLedNum->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelLedNum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cbxLedNum = new QComboBox(tab1);
        cbxLedNum->addItem(QString());
        cbxLedNum->addItem(QString());
        cbxLedNum->addItem(QString());
        cbxLedNum->setObjectName(QString::fromUtf8("cbxLedNum"));
        cbxLedNum->setGeometry(QRect(70, 10, 41, 21));
        cbxLedNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led1Group = new QGroupBox(tab1);
        led1Group->setObjectName(QString::fromUtf8("led1Group"));
        led1Group->setGeometry(QRect(10, 40, 131, 241));
        led1Group->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led1Btn = new MyBtn(led1Group);
        led1Btn->setObjectName(QString::fromUtf8("led1Btn"));
        led1Btn->setGeometry(QRect(0, 20, 81, 31));
        led1Attribute = new QWidget(led1Group);
        led1Attribute->setObjectName(QString::fromUtf8("led1Attribute"));
        led1Attribute->setGeometry(QRect(0, 60, 141, 181));
        verticalLayoutWidget = new QWidget(led1Attribute);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -1, 131, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        led1StyleOn = new QRadioButton(verticalLayoutWidget);
        led1StyleOn->setObjectName(QString::fromUtf8("led1StyleOn"));

        verticalLayout->addWidget(led1StyleOn);

        led1StyleFlash = new QRadioButton(verticalLayoutWidget);
        led1StyleFlash->setObjectName(QString::fromUtf8("led1StyleFlash"));

        verticalLayout->addWidget(led1StyleFlash);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        led1OnTime = new QLineEdit(verticalLayoutWidget);
        led1OnTime->setObjectName(QString::fromUtf8("led1OnTime"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(led1OnTime->sizePolicy().hasHeightForWidth());
        led1OnTime->setSizePolicy(sizePolicy);
        led1OnTime->setMinimumSize(QSize(40, 0));
        led1OnTime->setMaximumSize(QSize(30, 16777215));
        led1OnTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led1OnTime->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(led1OnTime);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        led1OffTime = new QLineEdit(verticalLayoutWidget);
        led1OffTime->setObjectName(QString::fromUtf8("led1OffTime"));
        sizePolicy.setHeightForWidth(led1OffTime->sizePolicy().hasHeightForWidth());
        led1OffTime->setSizePolicy(sizePolicy);
        led1OffTime->setMinimumSize(QSize(40, 0));
        led1OffTime->setMaximumSize(QSize(30, 16777215));
        led1OffTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led1OffTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(led1OffTime);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        led1StyleBreath = new QRadioButton(verticalLayoutWidget);
        led1StyleBreath->setObjectName(QString::fromUtf8("led1StyleBreath"));

        verticalLayout->addWidget(led1StyleBreath);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        led1Slider = new QSlider(verticalLayoutWidget);
        led1Slider->setObjectName(QString::fromUtf8("led1Slider"));
        led1Slider->setMinimum(0);
        led1Slider->setMaximum(5);
        led1Slider->setSingleStep(1);
        led1Slider->setPageStep(1);
        led1Slider->setValue(0);
        led1Slider->setSliderPosition(0);
        led1Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(led1Slider);

        led1SliderValue = new QLabel(verticalLayoutWidget);
        led1SliderValue->setObjectName(QString::fromUtf8("led1SliderValue"));

        horizontalLayout_3->addWidget(led1SliderValue);


        verticalLayout->addLayout(horizontalLayout_3);

        led2Group = new QGroupBox(tab1);
        led2Group->setObjectName(QString::fromUtf8("led2Group"));
        led2Group->setGeometry(QRect(160, 40, 131, 241));
        led2Group->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led2Btn = new MyBtn(led2Group);
        led2Btn->setObjectName(QString::fromUtf8("led2Btn"));
        led2Btn->setGeometry(QRect(0, 20, 81, 31));
        widget_6 = new QWidget(led2Group);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 60, 141, 181));
        verticalLayoutWidget_2 = new QWidget(widget_6);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, -1, 131, 181));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        led2StyleOn = new QRadioButton(verticalLayoutWidget_2);
        led2StyleOn->setObjectName(QString::fromUtf8("led2StyleOn"));

        verticalLayout_2->addWidget(led2StyleOn);

        led2StyleFlash = new QRadioButton(verticalLayoutWidget_2);
        led2StyleFlash->setObjectName(QString::fromUtf8("led2StyleFlash"));

        verticalLayout_2->addWidget(led2StyleFlash);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        led2OnTime = new QLineEdit(verticalLayoutWidget_2);
        led2OnTime->setObjectName(QString::fromUtf8("led2OnTime"));
        sizePolicy.setHeightForWidth(led2OnTime->sizePolicy().hasHeightForWidth());
        led2OnTime->setSizePolicy(sizePolicy);
        led2OnTime->setMinimumSize(QSize(40, 0));
        led2OnTime->setMaximumSize(QSize(30, 16777215));
        led2OnTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led2OnTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(led2OnTime);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_4->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        led2OffTime = new QLineEdit(verticalLayoutWidget_2);
        led2OffTime->setObjectName(QString::fromUtf8("led2OffTime"));
        sizePolicy.setHeightForWidth(led2OffTime->sizePolicy().hasHeightForWidth());
        led2OffTime->setSizePolicy(sizePolicy);
        led2OffTime->setMinimumSize(QSize(40, 0));
        led2OffTime->setMaximumSize(QSize(30, 16777215));
        led2OffTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led2OffTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(led2OffTime);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout_2->addLayout(horizontalLayout_5);

        led2StyleBreath = new QRadioButton(verticalLayoutWidget_2);
        led2StyleBreath->setObjectName(QString::fromUtf8("led2StyleBreath"));

        verticalLayout_2->addWidget(led2StyleBreath);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_6->addWidget(label_14);

        led2Slider = new QSlider(verticalLayoutWidget_2);
        led2Slider->setObjectName(QString::fromUtf8("led2Slider"));
        led2Slider->setMaximum(5);
        led2Slider->setPageStep(1);
        led2Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(led2Slider);

        led2SliderValue = new QLabel(verticalLayoutWidget_2);
        led2SliderValue->setObjectName(QString::fromUtf8("led2SliderValue"));

        horizontalLayout_6->addWidget(led2SliderValue);


        verticalLayout_2->addLayout(horizontalLayout_6);

        led3Group = new QGroupBox(tab1);
        led3Group->setObjectName(QString::fromUtf8("led3Group"));
        led3Group->setGeometry(QRect(310, 40, 131, 241));
        led3Group->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led3Btn = new MyBtn(led3Group);
        led3Btn->setObjectName(QString::fromUtf8("led3Btn"));
        led3Btn->setGeometry(QRect(0, 20, 81, 31));
        widget_7 = new QWidget(led3Group);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 60, 141, 181));
        verticalLayoutWidget_3 = new QWidget(widget_7);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, -1, 131, 181));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        led3StyleOn = new QRadioButton(verticalLayoutWidget_3);
        led3StyleOn->setObjectName(QString::fromUtf8("led3StyleOn"));

        verticalLayout_3->addWidget(led3StyleOn);

        led3StyleFlash = new QRadioButton(verticalLayoutWidget_3);
        led3StyleFlash->setObjectName(QString::fromUtf8("led3StyleFlash"));

        verticalLayout_3->addWidget(led3StyleFlash);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        led3OnTime = new QLineEdit(verticalLayoutWidget_3);
        led3OnTime->setObjectName(QString::fromUtf8("led3OnTime"));
        sizePolicy.setHeightForWidth(led3OnTime->sizePolicy().hasHeightForWidth());
        led3OnTime->setSizePolicy(sizePolicy);
        led3OnTime->setMinimumSize(QSize(40, 0));
        led3OnTime->setMaximumSize(QSize(30, 16777215));
        led3OnTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led3OnTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(led3OnTime);

        label_18 = new QLabel(verticalLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_7->addWidget(label_18);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_19 = new QLabel(verticalLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_8->addWidget(label_19);

        led3OffTime = new QLineEdit(verticalLayoutWidget_3);
        led3OffTime->setObjectName(QString::fromUtf8("led3OffTime"));
        sizePolicy.setHeightForWidth(led3OffTime->sizePolicy().hasHeightForWidth());
        led3OffTime->setSizePolicy(sizePolicy);
        led3OffTime->setMinimumSize(QSize(40, 0));
        led3OffTime->setMaximumSize(QSize(30, 16777215));
        led3OffTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        led3OffTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(led3OffTime);

        label_20 = new QLabel(verticalLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_8->addWidget(label_20);


        verticalLayout_3->addLayout(horizontalLayout_8);

        led3StyleBreath = new QRadioButton(verticalLayoutWidget_3);
        led3StyleBreath->setObjectName(QString::fromUtf8("led3StyleBreath"));

        verticalLayout_3->addWidget(led3StyleBreath);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_21 = new QLabel(verticalLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_9->addWidget(label_21);

        led3Slider = new QSlider(verticalLayoutWidget_3);
        led3Slider->setObjectName(QString::fromUtf8("led3Slider"));
        led3Slider->setMaximum(5);
        led3Slider->setPageStep(1);
        led3Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(led3Slider);

        led3SliderValue = new QLabel(verticalLayoutWidget_3);
        led3SliderValue->setObjectName(QString::fromUtf8("led3SliderValue"));

        horizontalLayout_9->addWidget(led3SliderValue);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        label_24 = new QLabel(tab2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 5, 101, 16));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_24->setAlignment(Qt::AlignCenter);
        labelPng1 = new QLabel(tab2);
        labelPng1->setObjectName(QString::fromUtf8("labelPng1"));
        labelPng1->setGeometry(QRect(10, 30, 121, 91));
        labelPng1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        btnDownload1 = new QPushButton(tab2);
        btnDownload1->setObjectName(QString::fromUtf8("btnDownload1"));
        btnDownload1->setGeometry(QRect(90, 125, 41, 24));
        btnDownload1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelPng4 = new QLabel(tab2);
        labelPng4->setObjectName(QString::fromUtf8("labelPng4"));
        labelPng4->setGeometry(QRect(10, 160, 121, 91));
        labelPng4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        btnPng4 = new QPushButton(tab2);
        btnPng4->setObjectName(QString::fromUtf8("btnPng4"));
        btnPng4->setGeometry(QRect(10, 255, 41, 24));
        btnPng4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnDownload4 = new QPushButton(tab2);
        btnDownload4->setObjectName(QString::fromUtf8("btnDownload4"));
        btnDownload4->setGeometry(QRect(90, 255, 41, 24));
        btnDownload4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelPng2 = new QLabel(tab2);
        labelPng2->setObjectName(QString::fromUtf8("labelPng2"));
        labelPng2->setGeometry(QRect(170, 30, 121, 91));
        labelPng2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        labelPng3 = new QLabel(tab2);
        labelPng3->setObjectName(QString::fromUtf8("labelPng3"));
        labelPng3->setGeometry(QRect(330, 30, 121, 91));
        labelPng3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        btnPng2 = new QPushButton(tab2);
        btnPng2->setObjectName(QString::fromUtf8("btnPng2"));
        btnPng2->setGeometry(QRect(170, 125, 41, 24));
        btnPng2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnDownload2 = new QPushButton(tab2);
        btnDownload2->setObjectName(QString::fromUtf8("btnDownload2"));
        btnDownload2->setGeometry(QRect(250, 125, 41, 24));
        btnDownload2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnPng3 = new QPushButton(tab2);
        btnPng3->setObjectName(QString::fromUtf8("btnPng3"));
        btnPng3->setGeometry(QRect(330, 125, 41, 24));
        btnPng3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnDownload3 = new QPushButton(tab2);
        btnDownload3->setObjectName(QString::fromUtf8("btnDownload3"));
        btnDownload3->setGeometry(QRect(410, 125, 41, 24));
        btnDownload3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelPng5 = new QLabel(tab2);
        labelPng5->setObjectName(QString::fromUtf8("labelPng5"));
        labelPng5->setGeometry(QRect(170, 160, 121, 91));
        labelPng5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        labelPng6 = new QLabel(tab2);
        labelPng6->setObjectName(QString::fromUtf8("labelPng6"));
        labelPng6->setGeometry(QRect(330, 160, 121, 91));
        labelPng6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        btnPng5 = new QPushButton(tab2);
        btnPng5->setObjectName(QString::fromUtf8("btnPng5"));
        btnPng5->setGeometry(QRect(170, 255, 41, 24));
        btnPng5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnDownload5 = new QPushButton(tab2);
        btnDownload5->setObjectName(QString::fromUtf8("btnDownload5"));
        btnDownload5->setGeometry(QRect(250, 255, 41, 24));
        btnDownload5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnDownload6 = new QPushButton(tab2);
        btnDownload6->setObjectName(QString::fromUtf8("btnDownload6"));
        btnDownload6->setGeometry(QRect(410, 255, 41, 24));
        btnDownload6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnPng6 = new QPushButton(tab2);
        btnPng6->setObjectName(QString::fromUtf8("btnPng6"));
        btnPng6->setGeometry(QRect(330, 255, 41, 24));
        btnPng6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnPng1 = new QPushButton(tab2);
        btnPng1->setObjectName(QString::fromUtf8("btnPng1"));
        btnPng1->setGeometry(QRect(10, 125, 41, 24));
        btnPng1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        pushButton_4 = new QPushButton(tab3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(19, 30, 71, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        lineEdit_9 = new QLineEdit(tab3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 29, 251, 31));
        pushButton_5 = new QPushButton(tab3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 230, 71, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_26 = new QLabel(tab3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(340, 70, 101, 20));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 10pt \"Microsoft YaHei UI\";"));
        label_27 = new QLabel(tab3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(370, 100, 71, 21));
        widget_2 = new MyProcessBar(tab3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(140, 100, 211, 161));
        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        tabWidget->addTab(tab4, QString());
        groupBoxSerial = new QGroupBox(centralwidget);
        groupBoxSerial->setObjectName(QString::fromUtf8("groupBoxSerial"));
        groupBoxSerial->setGeometry(QRect(9, 80, 151, 291));
        groupBoxSerial->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        groupBoxSerial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBoxSerial->setFlat(false);
        groupBoxSerial->setCheckable(false);
        gridLayoutWidget = new QWidget(groupBoxSerial);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 133, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        boxBaudRate = new QComboBox(gridLayoutWidget);
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->addItem(QString());
        boxBaudRate->setObjectName(QString::fromUtf8("boxBaudRate"));
        boxBaudRate->setMaximumSize(QSize(75, 16777215));
        boxBaudRate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxBaudRate, 1, 1, 1, 1);

        labelStopBits = new QLabel(gridLayoutWidget);
        labelStopBits->setObjectName(QString::fromUtf8("labelStopBits"));
        labelStopBits->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelStopBits->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelStopBits, 4, 0, 1, 1);

        boxStopBits = new QComboBox(gridLayoutWidget);
        boxStopBits->addItem(QString());
        boxStopBits->addItem(QString());
        boxStopBits->addItem(QString());
        boxStopBits->setObjectName(QString::fromUtf8("boxStopBits"));
        boxStopBits->setMaximumSize(QSize(75, 16777215));
        boxStopBits->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxStopBits, 4, 1, 1, 1);

        labelPortName = new QLabel(gridLayoutWidget);
        labelPortName->setObjectName(QString::fromUtf8("labelPortName"));
        labelPortName->setMinimumSize(QSize(50, 0));
        labelPortName->setMaximumSize(QSize(50, 16777215));
        labelPortName->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelPortName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPortName, 0, 0, 1, 1);

        boxPortName = new QComboBox(gridLayoutWidget);
        boxPortName->setObjectName(QString::fromUtf8("boxPortName"));
        boxPortName->setMaximumSize(QSize(75, 16777215));
        boxPortName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxPortName, 0, 1, 1, 1);

        labelDataBits = new QLabel(gridLayoutWidget);
        labelDataBits->setObjectName(QString::fromUtf8("labelDataBits"));
        labelDataBits->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelDataBits->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDataBits, 2, 0, 1, 1);

        boxParity = new QComboBox(gridLayoutWidget);
        boxParity->addItem(QString());
        boxParity->addItem(QString());
        boxParity->addItem(QString());
        boxParity->addItem(QString());
        boxParity->addItem(QString());
        boxParity->setObjectName(QString::fromUtf8("boxParity"));
        boxParity->setMaximumSize(QSize(75, 16777215));
        boxParity->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxParity, 2, 1, 1, 1);

        boxDataBits = new QComboBox(gridLayoutWidget);
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->setObjectName(QString::fromUtf8("boxDataBits"));
        boxDataBits->setMaximumSize(QSize(75, 16777215));
        boxDataBits->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxDataBits, 3, 1, 1, 1);

        labelParity = new QLabel(gridLayoutWidget);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelParity->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelParity, 3, 0, 1, 1);

        labelBaudRate = new QLabel(gridLayoutWidget);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        labelBaudRate->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelBaudRate->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBaudRate, 1, 0, 1, 1);

        labelFlowControl = new QLabel(gridLayoutWidget);
        labelFlowControl->setObjectName(QString::fromUtf8("labelFlowControl"));
        labelFlowControl->setMinimumSize(QSize(0, 22));
        labelFlowControl->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelFlowControl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelFlowControl, 5, 0, 1, 1);

        boxFlowControl = new QComboBox(gridLayoutWidget);
        boxFlowControl->addItem(QString());
        boxFlowControl->addItem(QString());
        boxFlowControl->addItem(QString());
        boxFlowControl->setObjectName(QString::fromUtf8("boxFlowControl"));
        boxFlowControl->setMaximumSize(QSize(75, 16777215));
        boxFlowControl->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxFlowControl, 5, 1, 1, 1);

        btnSerialOpen = new QPushButton(groupBoxSerial);
        btnSerialOpen->setObjectName(QString::fromUtf8("btnSerialOpen"));
        btnSerialOpen->setGeometry(QRect(80, 220, 58, 30));
        btnSerialOpen->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnSerialRefresh = new QPushButton(groupBoxSerial);
        btnSerialRefresh->setObjectName(QString::fromUtf8("btnSerialRefresh"));
        btnSerialRefresh->setGeometry(QRect(10, 220, 58, 30));
        btnSerialRefresh->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 50, 111, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft JhengHei UI"));
        font1.setPointSize(12);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setToolTipDuration(1);
        statusbar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        cbxLedNum->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelLogoText->setText(QCoreApplication::translate("MainWindow", "TWS Charging Case", nullptr));
        pushButton_close->setText(QString());
        pushButton_min->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\347\224\265\351\207\217:", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        labelLogoPic->setText(QString());
        labelLedNum->setText(QCoreApplication::translate("MainWindow", "LED\346\225\260\351\207\217", nullptr));
        cbxLedNum->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cbxLedNum->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        cbxLedNum->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        cbxLedNum->setCurrentText(QCoreApplication::translate("MainWindow", "3", nullptr));
        led1Group->setTitle(QCoreApplication::translate("MainWindow", "LED1", nullptr));
        led1StyleOn->setText(QCoreApplication::translate("MainWindow", "LED\345\270\270\344\272\256", nullptr));
        led1StyleFlash->setText(QCoreApplication::translate("MainWindow", "LED\351\227\252\347\203\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        led1OnTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        led1OffTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        led1StyleBreath->setText(QCoreApplication::translate("MainWindow", "LED\345\221\274\345\220\270", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\351\200\237\347\216\207", nullptr));
        led1SliderValue->setText(QCoreApplication::translate("MainWindow", "0s", nullptr));
        led2Group->setTitle(QCoreApplication::translate("MainWindow", "LED2", nullptr));
        led2StyleOn->setText(QCoreApplication::translate("MainWindow", "LED\345\270\270\344\272\256", nullptr));
        led2StyleFlash->setText(QCoreApplication::translate("MainWindow", "LED\351\227\252\347\203\201", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        led2OnTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        led2OffTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        led2StyleBreath->setText(QCoreApplication::translate("MainWindow", "LED\345\221\274\345\220\270", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\200\237\347\216\207", nullptr));
        led2SliderValue->setText(QCoreApplication::translate("MainWindow", "0s", nullptr));
        led3Group->setTitle(QCoreApplication::translate("MainWindow", "LED3", nullptr));
        led3StyleOn->setText(QCoreApplication::translate("MainWindow", "LED\345\270\270\344\272\256", nullptr));
        led3StyleFlash->setText(QCoreApplication::translate("MainWindow", "LED\351\227\252\347\203\201", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        led3OnTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        led3OffTime->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        led3StyleBreath->setText(QCoreApplication::translate("MainWindow", "LED\345\221\274\345\220\270", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\351\200\237\347\216\207", nullptr));
        led3SliderValue->setText(QCoreApplication::translate("MainWindow", "0s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\345\257\274\345\205\245", nullptr));
        labelPng1->setText(QString());
        btnDownload1->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        labelPng4->setText(QString());
        btnPng4->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnDownload4->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        labelPng2->setText(QString());
        labelPng3->setText(QString());
        btnPng2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnDownload2->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        btnPng3->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnDownload3->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        labelPng5->setText(QString());
        labelPng6->setText(QString());
        btnPng5->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnDownload5->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        btnDownload6->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        btnPng6->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnPng1->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\272\344\273\266", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\345\233\272\344\273\266", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\233\272\344\273\266\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        label_27->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        groupBoxSerial->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        boxBaudRate->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        boxBaudRate->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        boxBaudRate->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        boxBaudRate->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        boxBaudRate->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        boxBaudRate->setItemText(5, QCoreApplication::translate("MainWindow", "38400", nullptr));
        boxBaudRate->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        boxBaudRate->setItemText(7, QCoreApplication::translate("MainWindow", "115200", nullptr));
        boxBaudRate->setItemText(8, QCoreApplication::translate("MainWindow", "128000", nullptr));
        boxBaudRate->setItemText(9, QCoreApplication::translate("MainWindow", "230400", nullptr));

        boxBaudRate->setCurrentText(QCoreApplication::translate("MainWindow", "1200", nullptr));
        labelStopBits->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        boxStopBits->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        boxStopBits->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        boxStopBits->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        labelPortName->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        boxPortName->setCurrentText(QString());
        labelDataBits->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        boxParity->setItemText(0, QCoreApplication::translate("MainWindow", "NONE", nullptr));
        boxParity->setItemText(1, QCoreApplication::translate("MainWindow", "Even\345\201\266", nullptr));
        boxParity->setItemText(2, QCoreApplication::translate("MainWindow", "Odd\345\245\207", nullptr));
        boxParity->setItemText(3, QCoreApplication::translate("MainWindow", "Space", nullptr));
        boxParity->setItemText(4, QCoreApplication::translate("MainWindow", "Mark", nullptr));

        boxDataBits->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        boxDataBits->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        boxDataBits->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        boxDataBits->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        boxDataBits->setCurrentText(QCoreApplication::translate("MainWindow", "5", nullptr));
        labelParity->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        labelBaudRate->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        labelFlowControl->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\216\247\345\210\266", nullptr));
        boxFlowControl->setItemText(0, QCoreApplication::translate("MainWindow", "No", nullptr));
        boxFlowControl->setItemText(1, QCoreApplication::translate("MainWindow", "Hardware", nullptr));
        boxFlowControl->setItemText(2, QCoreApplication::translate("MainWindow", "Software", nullptr));

        btnSerialOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnSerialRefresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\351\200\232\344\277\241\350\256\276\345\244\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

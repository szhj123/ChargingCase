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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

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
    QWidget *tab_3;
    QLabel *label_8;
    QComboBox *comboBox_7;
    QWidget *widget_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QComboBox *comboBox_8;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QLabel *label_18;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QLabel *label_19;
    QWidget *widget_3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QComboBox *comboBox_9;
    QLabel *label_13;
    QLineEdit *lineEdit_3;
    QLabel *label_20;
    QLabel *label_14;
    QLineEdit *lineEdit_4;
    QLabel *label_21;
    QWidget *widget_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QComboBox *comboBox_10;
    QLabel *label_16;
    QLineEdit *lineEdit_5;
    QLabel *label_22;
    QLabel *label_17;
    QLineEdit *lineEdit_6;
    QLabel *label_23;
    QWidget *tab;
    QLabel *label_24;
    QLabel *label_png1;
    QPushButton *btnPng1;
    QPushButton *btnPng1_2;
    QWidget *tab_4;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_5;
    QLabel *label_26;
    QLabel *label_27;
    QWidget *tab_2;
    QTextEdit *textRecv;
    QTextEdit *textSend;
    QPushButton *btnSend;
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
"font: 75 10pt \"Microsoft JhengHei UI\";"));
        label_29 = new QLabel(widget_logo);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(410, 10, 41, 21));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 75 10pt \"Microsoft JhengHei UI\";"));
        label_30 = new QLabel(widget_logo);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(460, 0, 31, 41));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 75 10pt \"Microsoft JhengHei UI\";"));
        label_31 = new QLabel(widget_logo);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(490, 10, 41, 21));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 75 10pt \"Microsoft JhengHei UI\";"));
        labelLogoPic = new QLabel(widget_logo);
        labelLogoPic->setObjectName(QString::fromUtf8("labelLogoPic"));
        labelLogoPic->setGeometry(QRect(10, 2, 61, 31));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(160, 50, 471, 311));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 51, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox_7 = new QComboBox(tab_3);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(60, 10, 31, 16));
        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 50, 451, 41));
        horizontalLayoutWidget = new QWidget(widget_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 451, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_9);

        comboBox_8 = new QComboBox(horizontalLayoutWidget);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        horizontalLayout->addWidget(comboBox_8);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_10);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_18 = new QLabel(horizontalLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_18);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_11);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        label_19 = new QLabel(horizontalLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_19);

        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 110, 451, 41));
        horizontalLayoutWidget_2 = new QWidget(widget_3);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 451, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_12);

        comboBox_9 = new QComboBox(horizontalLayoutWidget_2);
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));

        horizontalLayout_2->addWidget(comboBox_9);

        label_13 = new QLabel(horizontalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_13);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);

        label_20 = new QLabel(horizontalLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_20);

        label_14 = new QLabel(horizontalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_14);

        lineEdit_4 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);

        label_21 = new QLabel(horizontalLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_2->addWidget(label_21);

        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(10, 170, 451, 41));
        horizontalLayoutWidget_3 = new QWidget(widget_4);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 451, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(horizontalLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(label_15);

        comboBox_10 = new QComboBox(horizontalLayoutWidget_3);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName(QString::fromUtf8("comboBox_10"));

        horizontalLayout_3->addWidget(comboBox_10);

        label_16 = new QLabel(horizontalLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(label_16);

        lineEdit_5 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_3->addWidget(lineEdit_5);

        label_22 = new QLabel(horizontalLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(label_22);

        label_17 = new QLabel(horizontalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(label_17);

        lineEdit_6 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_3->addWidget(lineEdit_6);

        label_23 = new QLabel(horizontalLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(label_23);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 10, 101, 21));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        label_24->setAlignment(Qt::AlignCenter);
        label_png1 = new QLabel(tab);
        label_png1->setObjectName(QString::fromUtf8("label_png1"));
        label_png1->setGeometry(QRect(10, 40, 100, 100));
        label_png1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/add_pic.png);"));
        btnPng1 = new QPushButton(tab);
        btnPng1->setObjectName(QString::fromUtf8("btnPng1"));
        btnPng1->setGeometry(QRect(10, 150, 41, 21));
        btnPng1_2 = new QPushButton(tab);
        btnPng1_2->setObjectName(QString::fromUtf8("btnPng1_2"));
        btnPng1_2->setGeometry(QRect(70, 150, 41, 21));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(19, 30, 71, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(40, 40, 40);\n"
"font: 10pt \"Microsoft YaHei UI\";"));
        lineEdit_9 = new QLineEdit(tab_4);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 29, 231, 31));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 189, 71, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(40, 40, 40);\n"
"font: 10pt \"Microsoft YaHei UI\";"));
        label_26 = new QLabel(tab_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(330, 90, 101, 16));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 10pt \"Microsoft YaHei UI\";"));
        label_27 = new QLabel(tab_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(330, 120, 54, 12));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textRecv = new QTextEdit(tab_2);
        textRecv->setObjectName(QString::fromUtf8("textRecv"));
        textRecv->setGeometry(QRect(0, 0, 291, 111));
        textSend = new QTextEdit(tab_2);
        textSend->setObjectName(QString::fromUtf8("textSend"));
        textSend->setGeometry(QRect(0, 130, 291, 111));
        btnSend = new QPushButton(tab_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(340, 170, 75, 23));
        tabWidget->addTab(tab_2, QString());
        groupBoxSerial = new QGroupBox(centralwidget);
        groupBoxSerial->setObjectName(QString::fromUtf8("groupBoxSerial"));
        groupBoxSerial->setGeometry(QRect(9, 80, 141, 241));
        groupBoxSerial->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        groupBoxSerial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBoxSerial->setFlat(false);
        groupBoxSerial->setCheckable(false);
        gridLayoutWidget = new QWidget(groupBoxSerial);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 121, 171));
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
        boxBaudRate->setMaximumSize(QSize(60, 16777215));
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
        boxStopBits->setMaximumSize(QSize(60, 16777215));
        boxStopBits->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxStopBits, 4, 1, 1, 1);

        labelPortName = new QLabel(gridLayoutWidget);
        labelPortName->setObjectName(QString::fromUtf8("labelPortName"));
        labelPortName->setStyleSheet(QString::fromUtf8("color: rgb(240, 240, 240);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        labelPortName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPortName, 0, 0, 1, 1);

        boxPortName = new QComboBox(gridLayoutWidget);
        boxPortName->setObjectName(QString::fromUtf8("boxPortName"));
        boxPortName->setMaximumSize(QSize(60, 16777215));
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
        boxParity->setMaximumSize(QSize(60, 16777215));
        boxParity->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxParity, 2, 1, 1, 1);

        boxDataBits = new QComboBox(gridLayoutWidget);
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->addItem(QString());
        boxDataBits->setObjectName(QString::fromUtf8("boxDataBits"));
        boxDataBits->setMaximumSize(QSize(60, 16777215));
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
        boxFlowControl->setMaximumSize(QSize(60, 16777215));
        boxFlowControl->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(boxFlowControl, 5, 1, 1, 1);

        btnSerialOpen = new QPushButton(groupBoxSerial);
        btnSerialOpen->setObjectName(QString::fromUtf8("btnSerialOpen"));
        btnSerialOpen->setGeometry(QRect(70, 200, 58, 30));
        btnSerialOpen->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"Microsoft YaHei UI\";"));
        btnSerialRefresh = new QPushButton(groupBoxSerial);
        btnSerialRefresh->setObjectName(QString::fromUtf8("btnSerialRefresh"));
        btnSerialRefresh->setGeometry(QRect(10, 200, 58, 30));
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

        tabWidget->setCurrentIndex(0);


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
        label_8->setText(QCoreApplication::translate("MainWindow", "LED\346\225\260\351\207\217", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "LED1:", nullptr));
        comboBox_8->setItemText(0, QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255", nullptr));
        comboBox_8->setItemText(1, QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256", nullptr));
        comboBox_8->setItemText(2, QCoreApplication::translate("MainWindow", "\351\227\252\347\203\201", nullptr));
        comboBox_8->setItemText(3, QCoreApplication::translate("MainWindow", "\345\221\274\345\220\270", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "LED2:", nullptr));
        comboBox_9->setItemText(0, QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256", nullptr));
        comboBox_9->setItemText(2, QCoreApplication::translate("MainWindow", "\351\227\252\347\203\201", nullptr));
        comboBox_9->setItemText(3, QCoreApplication::translate("MainWindow", "\345\221\274\345\220\270", nullptr));

        label_13->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "LED3:", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "\351\227\252\347\203\201", nullptr));
        comboBox_10->setItemText(3, QCoreApplication::translate("MainWindow", "\345\221\274\345\220\270", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "\345\270\270\344\272\256\346\227\266\351\227\264:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\201\255\346\227\266\351\227\264:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\346\257\253\347\247\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201\345\233\276\347\211\207\346\225\260\351\207\217", nullptr));
        label_png1->setText(QString());
        btnPng1->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        btnPng1_2->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\272\344\273\266", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\345\233\272\344\273\266", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\233\272\344\273\266\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        label_27->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
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

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_power;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_x;
    QPushButton *pushButton_0;
    QPushButton *pushButton_log;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_upBracket;
    QPushButton *pushButton_downBracket;
    QPushButton *pushButton_Graph;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_Backspace;
    QLabel *label;
    QCustomPlot *widgetPlot;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(300, 200, 100, 100));
        QFont font;
        font.setPointSize(16);
        pushButton_1->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 200, 100, 100));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(500, 200, 100, 100));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(300, 300, 100, 100));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(400, 300, 100, 100));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(500, 300, 100, 100));
        pushButton_6->setFont(font);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(300, 400, 100, 100));
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(400, 400, 100, 100));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(500, 400, 100, 100));
        pushButton_9->setFont(font);
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(100, 200, 100, 100));
        pushButton_sin->setFont(font);
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(100, 300, 100, 100));
        pushButton_cos->setFont(font);
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(100, 400, 100, 100));
        pushButton_tan->setFont(font);
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(0, 300, 100, 100));
        pushButton_acos->setFont(font);
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(0, 400, 100, 100));
        pushButton_atan->setFont(font);
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(0, 200, 100, 100));
        pushButton_asin->setFont(font);
        pushButton_power = new QPushButton(centralwidget);
        pushButton_power->setObjectName("pushButton_power");
        pushButton_power->setGeometry(QRect(200, 300, 100, 100));
        pushButton_power->setFont(font);
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(200, 400, 100, 100));
        pushButton_sqrt->setFont(font);
        pushButton_percent = new QPushButton(centralwidget);
        pushButton_percent->setObjectName("pushButton_percent");
        pushButton_percent->setGeometry(QRect(200, 200, 100, 100));
        pushButton_percent->setFont(font);
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(400, 500, 100, 100));
        pushButton_dot->setFont(font);
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(100, 500, 100, 100));
        pushButton_ln->setFont(font);
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(200, 500, 100, 100));
        pushButton_x->setFont(font);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(300, 500, 100, 100));
        pushButton_0->setFont(font);
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(0, 500, 100, 100));
        pushButton_log->setFont(font);
        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setGeometry(QRect(500, 500, 100, 100));
        pushButton_equal->setFont(font);
        pushButton_divide = new QPushButton(centralwidget);
        pushButton_divide->setObjectName("pushButton_divide");
        pushButton_divide->setGeometry(QRect(600, 200, 100, 100));
        pushButton_divide->setFont(font);
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(600, 500, 100, 100));
        pushButton_plus->setFont(font);
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(600, 400, 100, 100));
        pushButton_minus->setFont(font);
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName("pushButton_multiply");
        pushButton_multiply->setGeometry(QRect(600, 300, 100, 100));
        pushButton_multiply->setFont(font);
        pushButton_upBracket = new QPushButton(centralwidget);
        pushButton_upBracket->setObjectName("pushButton_upBracket");
        pushButton_upBracket->setGeometry(QRect(400, 100, 100, 100));
        pushButton_upBracket->setFont(font);
        pushButton_downBracket = new QPushButton(centralwidget);
        pushButton_downBracket->setObjectName("pushButton_downBracket");
        pushButton_downBracket->setGeometry(QRect(500, 100, 100, 100));
        pushButton_downBracket->setFont(font);
        pushButton_Graph = new QPushButton(centralwidget);
        pushButton_Graph->setObjectName("pushButton_Graph");
        pushButton_Graph->setGeometry(QRect(300, 100, 100, 100));
        pushButton_Graph->setFont(font);
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(600, 100, 100, 100));
        pushButton_mod->setFont(font);
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName("pushButton_AC");
        pushButton_AC->setGeometry(QRect(0, 100, 100, 100));
        pushButton_AC->setFont(font);
        pushButton_Backspace = new QPushButton(centralwidget);
        pushButton_Backspace->setObjectName("pushButton_Backspace");
        pushButton_Backspace->setGeometry(QRect(100, 100, 201, 100));
        pushButton_Backspace->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 100));
        QFont font1;
        font1.setPointSize(36);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"padding-right: 30px;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widgetPlot = new QCustomPlot(centralwidget);
        widgetPlot->setObjectName("widgetPlot");
        widgetPlot->setGeometry(QRect(700, 100, 600, 500));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(700, 0, 100, 50));
        QFont font2;
        font2.setPointSize(24);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(700, 50, 100, 50));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(800, 0, 250, 50));
        doubleSpinBox->setMinimum(-100.000000000000000);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(1050, 0, 250, 50));
        doubleSpinBox_2->setMinimum(-100.000000000000000);
        doubleSpinBox_2->setMaximum(100.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(800, 50, 250, 50));
        doubleSpinBox_3->setMinimum(-100.000000000000000);
        doubleSpinBox_3->setMaximum(100.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(1050, 50, 250, 50));
        doubleSpinBox_4->setMinimum(-100.000000000000000);
        doubleSpinBox_4->setMaximum(100.000000000000000);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_power->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_upBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_downBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_Graph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_Backspace->setText(QCoreApplication::translate("MainWindow", "Backspace", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

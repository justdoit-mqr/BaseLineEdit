/*
 *@author:  缪庆瑞
 *@date:    2020.04.10
 *@brief:   用来测试基类行编辑框的功能接口
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include "baselineedit.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void initBaseLineEditUi();//初始化BaseLineEdit功能测试界面

    Ui::Widget *ui;
    BaseLineEdit *lineEdit1;
    QToolButton *btn1;

    BaseLineEdit *lineEdit2;
    QToolButton *btn2;

    BaseLineEdit *lineEdit3;
    QToolButton *btn3;
    QToolButton *btn3_2;

    BaseLineEdit *lineEdit4;

public slots:
    void btn3_2Slot();

};

#endif // WIDGET_H

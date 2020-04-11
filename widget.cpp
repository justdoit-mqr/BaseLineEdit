/*
 *@author:  缪庆瑞
 *@date:    2020.04.10
 *@brief:   用来测试基类行编辑框的功能接口
 */
#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedWidth(500);

    initBaseLineEditUi();
}

Widget::~Widget()
{
    delete ui;
}
/*
 *@brief:   初始化BaseLineEdit功能测试界面
 *@author:  缪庆瑞
 *@date:    2020.04.10
 */
void Widget::initBaseLineEditUi()
{
    //编辑框1
    btn1 = new QToolButton();
    btn1->setIcon(QIcon(QPixmap("./images/search.png")));
    btn1->setIconSize(QSize(32,32));
    btn1->setStyleSheet("background-color:transparent;");
    lineEdit1 = new BaseLineEdit(this,0,btn1);
    lineEdit1->setFixedHeight(50);
    //lineEdit1->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    lineEdit1->setStyleSheet("QLineEdit{border-radius:25px;font-size:15pt;}");
    lineEdit1->setLeftRightLayoutMargin(20,20);
    lineEdit1->setPlaceholderText("please input search content");
    ui->horizontalLayout->addWidget(lineEdit1);
    //编辑框2
    btn2 = new QToolButton();
    btn2->setIcon(QIcon(QPixmap("./images/calendar.png")));
    btn2->setIconSize(QSize(32,32));
    btn2->setStyleSheet("background-color:transparent;");
    lineEdit2 = new BaseLineEdit(this,btn2);
    lineEdit2->setFixedHeight(50);
    lineEdit2->setLeftRightLayoutMargin(5,20);
    ui->horizontalLayout_2->addWidget(lineEdit2);
    //编辑框3
    btn3 = new QToolButton();
    btn3->setIcon(QIcon(QPixmap("./images/search.png")));
    btn3->setIconSize(QSize(32,32));
    btn3->setStyleSheet("background-color:transparent;");
    btn3_2 = new QToolButton();
    btn3_2->setIcon(QIcon(QPixmap("./images/delete.png")));
    btn3_2->setIconSize(QSize(32,32));
    btn3_2->setStyleSheet("background-color:transparent;");
    connect(btn3_2,SIGNAL(clicked(bool)),this,SLOT(btn3_2Slot()));
    lineEdit3 = new BaseLineEdit(this,btn3,btn3_2);
    lineEdit3->setFixedHeight(50);
    lineEdit3->setLeftRightLayoutMargin(5,5);
    lineEdit3->setText("delete");
    ui->horizontalLayout_3->addWidget(lineEdit3);
    //编辑框4
    lineEdit4 = new BaseLineEdit(this);
    lineEdit4->setFixedHeight(50);
    ui->horizontalLayout_4->addWidget(lineEdit4);

}
/*
 *@brief:   按钮点击响应槽
 *@author:  缪庆瑞
 *@date:    2020.04.11
 */
void Widget::btn3_2Slot()
{
    lineEdit3->clear();
}

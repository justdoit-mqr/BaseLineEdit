/*
 *@author: 缪庆瑞
 *@date:   2020.04.11
 *@brief:  基类行编辑框
 */
#include "baselineedit.h"
#include <QDebug>

/*
 *@brief:   构造方法
 *@author:  缪庆瑞
 *@date:    2020.04.11
 *@param:   parent:父对象
 *@param:   leftWid:行编辑框左侧部件  0表示无部件
 *@param:   rightWid:行编辑框右侧部件 0表示无部件
 */
BaseLineEdit::BaseLineEdit(QWidget *parent, QWidget *leftWid, QWidget *rightWid)
    : QLineEdit(parent),leftRightLayout(0),leftWidget(leftWid),rightWidget(rightWid)
{
    if(leftWidget || rightWidget)
    {
        //对行编辑框内的部件进行布局
        leftRightLayout = new QHBoxLayout(this);
        leftRightLayout->setMargin(2);
        leftRightLayout->setSpacing(0);
        if(leftWidget)
        {
            leftRightLayout->addWidget(leftWidget);
        }
        leftRightLayout->addStretch();
        if(rightWidget)
        {
            leftRightLayout->addWidget(rightWidget);
        }
    }
    setTextSelectionEnabled(true);//默认文本可以被选中
}
/*
 *@brief:   主动发射编辑信号editSig()
 * 因为Qt4中signals是protected权限，无法类外调用，所以这里设置一个public权限接口，实现在类外
 * 调用主动发射编辑信号
 *@author:  缪庆瑞
 *@date:    2020.05.26
 */
void BaseLineEdit::emitEditSig()
{
    this->setFocus();
    emit editSig();
}
/*
 *@brief:   设置行编辑框左右布局margin，主要为了方便调整左右侧部件的位置
 *@author:  缪庆瑞
 *@date:    2020.04.11
 *@param:   left:左边间距 right:右边间距
 *@param:   top:上边间距 bottom:下边间距 默认0,一般不需要调整
 */
void BaseLineEdit::setLeftRightLayoutMargin(int left, int right, int top, int bottom)
{
    if(leftRightLayout)
    {
        leftRightLayout->setContentsMargins(left,top,right,bottom);
        /* 在编辑框显示之前左右部件的大小如果没有fixed，那么默认将采用部件自身的推荐大小。所以
         * 这里只在部件显示(内部已完成布局)的情况下才自动调整文本的margin，避免按照部件推荐大小
         * 设置margin导致编辑框的大小策略受到不良影响。
         */
        if(this->isVisible())
        {
            autoAdjustTextMargins();
        }
    }
}
/*
 *@brief:   鼠标移动事件处理
 *@author:  缪庆瑞
 *@date:    2020.05.20
 *@param:   event:鼠标事件
 */
void BaseLineEdit::mouseMoveEvent(QMouseEvent *event)
{
    if(textSelectionEnabled)
    {
        QLineEdit::mouseMoveEvent(event);
    }
}
/*
 *@brief:   鼠标释放事件处理
 *@author:  缪庆瑞
 *@date:    2020.04.11
 *@param:   event:鼠标事件
 */
void BaseLineEdit::mouseReleaseEvent(QMouseEvent *event)
{
    //左键释放&&非只读模式
    if(event->button() == Qt::LeftButton && !this->isReadOnly())
    {
        emit editSig();//发射编辑信号
    }
    QLineEdit::mouseReleaseEvent(event);
}
/*
 *@brief:   鼠标双击事件处理
 *@author:  缪庆瑞
 *@date:    2020.05.20
 *@param:   event:鼠标事件
 */
void BaseLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(textSelectionEnabled)
    {
        QLineEdit::mouseDoubleClickEvent(event);
    }
}
/*
 *@brief:   部件大小调整事件处理 (用来自动调整编辑框文本的margins)
 *@author:  缪庆瑞
 *@date:    2020.04.11
 *@param:   event:大小事件
 */
void BaseLineEdit::resizeEvent(QResizeEvent *event)
{
    QLineEdit::resizeEvent(event);
    autoAdjustTextMargins();
}
/*
 *@brief:   根据布局的边距和部件的宽度，自动调整编辑框文本的margins
 *@author:  缪庆瑞
 *@date:    2020.04.11
 */
void BaseLineEdit::autoAdjustTextMargins()
{
    if(leftRightLayout)
    {
        int leftMargin = leftWidget?leftWidget->width():0;
        int rightMargin = rightWidget?rightWidget->width():0;
        leftMargin += leftRightLayout->contentsMargins().left();
        rightMargin += leftRightLayout->contentsMargins().right();
        //qDebug()<<leftMargin<<rightMargin;
        //设置编辑框的margin 确保文本不会被部件遮挡
        this->setTextMargins(leftMargin,0,rightMargin,0);
    }
}

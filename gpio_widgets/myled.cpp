/* This software is released under GPL
 * For example code programming use only.
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include "myled.h"
#include <QPainter>

MyLed::MyLed(QWidget *parent) : QLabel(parent)
{
    m_value  = false;
    pOnImage = new QPixmap(":/leds/Images/circle_green.png");
    pOffImage= new QPixmap(":/leds/Images/circle_grey.png");
}

MyLed::~MyLed(){

    delete pOnImage;
    delete pOffImage;

}

void MyLed::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    if(m_value)
        painter.drawPixmap(0,0, (*pOnImage).scaled(this->size(), Qt::KeepAspectRatio));
    else
         painter.drawPixmap(0,0,(*pOffImage).scaled(this->size(),Qt::KeepAspectRatio));
}

void MyLed::setValue(bool value)
{
    m_value=value;
    update();
}

void MyLed::toggleValue()
{
    m_value=!m_value;
    update();
}

/* This software is released under GPL
 * For example code programming use only.
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include "myledsvg.h"

#ifdef _ENABLE_SVG
#include <QtSvg>
#include <QSvgRenderer>
#endif

// Remember to add:
// QT += svg
// into .PRO file

MyLedSvg::MyLedSvg(QWidget *parent) : QLabel(parent)
{
    m_value  =false;

#ifdef _ENABLE_SVG
    renderer = new QSvgRenderer();
#endif
#ifdef _ENABLE_SVG
    ledOffImge = QString(":/leds/Images/circle_grey.svg");
    ledOnImge  = QString(":/leds/Images/circle_red.svg");
#else
    ledOnImge   = QString(":/leds/Images/circle_green.png");
    ledOffImge  = QString(":/leds/Images/circle_grey.png");
#endif
    m_value = false;
    storeValue(m_value);
}


MyLedSvg::~MyLedSvg()
{
    #ifdef _ENABLE_SVG
        delete renderer;
    #endif

}

void MyLedSvg::paintEvent(QPaintEvent *eve)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

#ifdef _ENABLE_SVG
    if(m_value)
        renderer->load(ledOnImge);
    else
        renderer->load(ledOffImge);

    renderer->render(&painter);
#else
    QLabel::paintEvent(eve);
#endif
}

void MyLedSvg::storeValue(bool newvalue){

    if(newvalue != m_value){

        m_value = newvalue;

#ifndef _ENABLE_SVG
        if(m_value)
            this->setPixmap(QPixmap(ledOnImge));
        else
            this->setPixmap(QPixmap(ledOffImge));
#endif
    }
}

void MyLedSvg::setValue(bool value)
{
    storeValue(value);
    update();
}

void MyLedSvg::toggleValue()
{
    storeValue(!m_value);
    update();
}

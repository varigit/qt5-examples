/* This software is released under GPL
 * For example code programming use only.
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
*/

#include "myplot.h"
#include <QPainter>
#include <QDebug>

MyPlot::MyPlot(QWidget *parent) : QWidget(parent)
{
    m_timerId = -1;
    init();
}

void MyPlot::start(){

    init();
    //We use a timer to update the screen.
    m_timerId = startTimer(1000/100);
}

void MyPlot::init(){

    m_HSegments         =   100;
    m_PixelForSegment   = static_cast<float>( width()/(m_HSegments*1.0) );

    m_Ch1_Values.clear();
    for(int i=0;i<m_HSegments;i++){
        m_Ch1_Values.append(0);
    }
}

/*
 !!!! NOTE:
 There are many other different ways to paint the screen in an efficient way.
 The code below is only a starting point and it is useful to explain step by step the painting process.
 Consider using a different procedure for a commercial product.
*/
void MyPlot::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    //Border
    p.fillRect(this->rect().adjusted(1,1,-1,-1),Qt::black);

    //Draw grid
    QPen pen;
    pen.setColor(Qt::lightGray);
    pen.setWidth(1);
    pen.setStyle(Qt::DotLine);
    p.setPen(pen);

    float dx = this->width()/10;
    for(int i=1;i<10;i++){
        p.drawLine(i*dx,1,i*dx,this->height()-1);
    }

    float dy = this->height()/10;
    for(int i=1;i<10;i++){
        p.drawLine(1,i*dy,this->width()-1,i*dy);
    }

    //Border
    pen.setColor(Qt::black);
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    p.setPen(pen);
    p.drawRect(this->rect().adjusted(1,1,-1,-1));

    //Traces
    pen.setColor(Qt::green);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    for(int i=1; i<m_HSegments; i++){

        QPoint p1 = QPoint(static_cast<int>((i-1)*m_PixelForSegment), m_Ch1_Values[i-1] + this->height()/2);
        QPoint p2 = QPoint(static_cast<int>(i*m_PixelForSegment),     m_Ch1_Values[i]   + this->height()/2);

        //Persistence
        int dx = 0;
        if( i < m_cursorPosition){
            dx = m_cursorPosition - i;
        }else
        if( i == m_cursorPosition){
            //Cursor pointer
            p.setPen(pen);
            p.drawEllipse(p2,2,2);
        }else
        if( i > m_cursorPosition){
            dx = (m_HSegments - i) + m_cursorPosition;
        }

        int x = static_cast<int>((200.0/m_HSegments)*dx);

        pen.setColor(QColor(x,255,x,255-x));
        p.setPen(pen);

        p.drawLine(p1,p2);
    }
}

void MyPlot::setInput(bool onoff){
    inCh = (onoff*50)*(-1);
}

void MyPlot::timerEvent(QTimerEvent *event){

    Q_UNUSED(event)

    m_cursorPosition++;

    if(m_cursorPosition >= m_HSegments){
        m_cursorPosition = 0;
    }

    //Sampling
    m_Ch1_Values[m_cursorPosition] = inCh;

    this->update();
}

void MyPlot::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    if(m_timerId != -1)
        this->killTimer(m_timerId);
    start();
}

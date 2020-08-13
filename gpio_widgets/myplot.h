#ifndef MYPLOT_H
#define MYPLOT_H

#include <QWidget>

class MyPlot : public QWidget
{
    Q_OBJECT

private:
    int   m_HSegments;
    float m_PixelForSegment;
    int m_cursorPosition;

    QVector <int> m_Ch1_Values;

    int m_timerId;

    int inCh = 0;

    void init();


public:
    explicit MyPlot(QWidget *parent = 0);


    void setInput(bool onoff);
    void start();

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:

public slots:
};

#endif // MYPLOT_H

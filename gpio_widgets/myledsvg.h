#ifndef MYLEDSVG_H
#define MYLEDSVG_H

#include <QLabel>

#define _ENABLE_SVG

class QSvgRenderer;

class MyLedSvg : public QLabel

{
    Q_OBJECT

private:
     QSvgRenderer *renderer;
     bool m_value;

     QString ledOnImge;
     QString ledOffImge;

     void storeValue(bool newvalue);

public:
    explicit MyLedSvg(QWidget *parent = 0);
    virtual ~MyLedSvg();


public slots:
     void setValue(bool value);
     void toggleValue();

protected:
     void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // MYLEDSVG_H

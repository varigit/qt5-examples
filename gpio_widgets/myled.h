#ifndef MYLED_H
#define MYLED_H

#include <QLabel>

class MyLed : public QLabel
{
    Q_OBJECT

private:
    bool m_value;
    QPixmap* pOnImage;
    QPixmap* pOffImage;


protected:
    void paintEvent(QPaintEvent *event);

public:
    explicit MyLed(QWidget *parent = 0);
    virtual ~MyLed();

signals:

public slots:
    void setValue(bool);
    void toggleValue();
};

#endif // MYLED_H

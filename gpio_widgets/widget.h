#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    int m_polling;

    void setDemo(){
        gDemoMode = true;
        m_polling = this->startTimer(250);
    }

    bool gDemoMode;
    unsigned int  _lamp;
    unsigned int  _mask;

private slots:
    void on_P1_Button_clicked(bool checked);

    void on_P2_Button_clicked(bool checked);

    void on_p3_Button_clicked(bool checked);

    void on_p4_Button_pressed();

    void on_p4_Button_released();

private:
    Ui::Widget *ui;

    void setPin(int pin, QString inout);
    void writePin(int pin, QString value);
    bool readPin(int pin);

protected:
    void timerEvent(QTimerEvent* eve);
    void keyPressEvent(QKeyEvent* ev);
    void keyReleaseEvent(QKeyEvent* ev);

};

#endif // WIDGET_H

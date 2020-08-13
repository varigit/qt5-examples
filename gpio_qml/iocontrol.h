#ifndef IOCONTROL_H
#define IOCONTROL_H

#include <QObject>

class IoControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool pin4Status READ getPin4Status WRITE setPin4Status NOTIFY pin4StatusChanged)

private:
    void setPinMode(int pin, QString inout);
    void writePin(int pin, QString value);
    bool readPin(int pin);

    bool m_pin4 = false;
    int m_timerId;

public:
    explicit IoControl(QObject *parent = nullptr);

    bool getPin4Status() const
    {
        return m_pin4;
    }

    Q_INVOKABLE void autoBlink();

signals:

    void pin4StatusChanged(bool pin4);

public slots:
    //Gli slots possono essere chiamati dal QML
    void setPinSlot(int nPin, bool onoff);

    void setPin4Status(bool pin4);


    void onClicked();

protected slots:
    void timerEvent(QTimerEvent* ev);

};

#endif // IOCONTROL_H

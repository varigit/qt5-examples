/* This software is released under GPL
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include <QFile>
#include <QDebug>
#include "iocontrol.h"

IoControl::IoControl(QObject *parent) : QObject(parent)
{
    m_pin4    = false;
    m_timerId = -1;

    //GPIO ID LED
    // 99 - 100 - 110 - 113

    setPinMode(99,"out");
    setPinMode(100,"out");
    setPinMode(110,"out");
    setPinMode(113,"out");

}

void IoControl::setPinMode(int pin, QString inout){

    QFile exportFile("/sys/class/gpio/export");
    if(exportFile.open(QIODevice::WriteOnly)){
        QString gpioNumber = QString::number(pin);
        exportFile.write(gpioNumber.toUtf8());
        exportFile.close();

        QString s = QString("/sys/class/gpio/gpio%1/direction").arg(pin);
        qDebug() << s;
        QFile outFile(s);
        if(outFile.open(QIODevice::WriteOnly)){
            outFile.write(inout.toUtf8());
            outFile.close();

            qDebug() << "GPIO pin: " << pin << " Ok";

        }else{
            qDebug() << "GPIO set direction pin: " << pin << " failed";
        }
    }else {

        qDebug() << "GPIO export pin: " << pin << " failed";
    }
}

void IoControl::writePin(int pin, QString value){

    qDebug() << __FUNCTION__ << " pin:" << pin << " value:" << value;

    QFile valFile(QString("/sys/class/gpio/gpio%1/value").arg(pin));
    if(valFile.open(QIODevice::WriteOnly)){

        valFile.write(value.toUtf8());

        //qDebug() << " nPin: " << pin << " value:" << value;

        valFile.close();
    }
}

bool IoControl::readPin(int pin){

    qDebug() << __FUNCTION__;

    QByteArray contents;
    QFile valFile(QString("/sys/class/gpio/gpio%1/value").arg(pin));
    if(valFile.open(QIODevice::ReadOnly)){
        valFile.seek(0);
        contents = valFile.readAll();
        valFile.close();
    }
    qDebug() << contents.toHex();
    return((bool)contents.at(0));

}

void IoControl::setPinSlot(int nPin, bool onoff){

    qDebug() << __FUNCTION__ << " nPin:" << nPin  << " onOff:" << onoff;

    int idPin = 99;

    if(nPin == 1){
        idPin = 100;
    }else
        if(nPin == 2){
            idPin = 110;
        }else
            if(nPin == 3){
                idPin = 99;
            }

    if(onoff){
        writePin(idPin,QString("1"));
    }else
        writePin(idPin,QString("0"));


    if(nPin == 1){
        if(onoff){
            //qDebug() << "Start blink timer";
            m_timerId = this->startTimer(250);
        }else{
            //qDebug() << "Stop blink timer";
            this->killTimer(m_timerId);
        }
    }

}

void IoControl::timerEvent(QTimerEvent *ev)
{
    //qDebug() << __FUNCTION__ << " m_pin4:" << m_pin4;

    if(m_pin4)
        setPin4Status(0);
    else
        setPin4Status(1);
}

void IoControl::setPin4Status(bool pin4)
{
    if (m_pin4 == pin4)
        return;

    m_pin4 = pin4;
    emit pin4StatusChanged(pin4);
}

void IoControl::autoBlink(){

    if (m_timerId == -1)
        m_timerId = startTimer(250);
    else{
       killTimer(m_timerId);
       m_timerId = -1;
    }
}

void IoControl::onClicked(){
    qDebug() << "Test Slot";
}

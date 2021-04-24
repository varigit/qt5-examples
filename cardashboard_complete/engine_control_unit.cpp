#include "engine_control_unit.h"
#include <QVariant>
#include <QDebug>
#include <QTime>
#include <QTimerEvent>

EngineControlUnit::EngineControlUnit(QObject *parent) : QObject(parent)
{
    m_speed = 0;
    m_incr_speed = 0.8f;

    ccGear = 0;

    m_currentTime = QString("9:20");


    QLocale locale(QLocale("en_US"));
    QString dateString = locale.toString(QDate::currentDate());
    m_date = dateString;
    setProperty("currentime",m_date);

    g = 1;
    setProperty("gear",g);

    ccIcon = 0;
    m_leds = 0x0000;

    int idx = 0;
    ledsMap[idx++] = 0x0800;
    ledsMap[idx++] = 0x0000;
    ledsMap[idx++] = 0x0080;
    ledsMap[idx++] = 0x0001;
    ledsMap[idx++] = 0x0000;
    ledsMap[idx++] = 0x0010;
    ledsMap[idx++] = 0x0000;
    ledsMap[idx++] = 0x0120;
    ledsMap[idx++] = 0x0000;
    ledIdx = 0;

    setProperty("leds",m_leds);

    m_totalKm = 124000;
    setProperty("totalKm",m_totalKm);

    m_fuelLevel = 60;
    setProperty("fuelLevel",m_fuelLevel);

    m_oilLevel  = 80;
    setProperty("oilLevel",m_oilLevel);

    hiResTimerId = this->startTimer(16);

    loResTimerId = this->startTimer(1000);

}

void EngineControlUnit::timerEvent(QTimerEvent *event) {

    if(event->timerId() == hiResTimerId){

        float sp = m_speed + m_incr_speed ;

        if (sp < 0){
            sp = 0;
            m_incr_speed = -m_incr_speed;
        }

        setProperty("speed", sp);

        if ((m_speed > 180 || m_speed < 0)&&(m_incr_speed > 0)) {
            m_incr_speed = -m_incr_speed;
        }

        m_currentTime =  QTime::currentTime().toString();                      
        emit currentTimeChanged(m_currentTime);

        QLocale locale(QLocale("en_US"));
        QDateTime date = QDateTime::currentDateTime();
        QString dateString = locale.toString(date);



        m_totalKm += ((m_speed/3.6)/10000)*16;
        emit totalKmChanged(m_totalKm);


        decFuel = m_speed/10000;
        if(m_fuelLevel > 0)
            m_fuelLevel = m_fuelLevel - decFuel;

        decOil = 0.9;
        if(m_oilLevel > 0)
            m_oilLevel = m_oilLevel - decOil;


    }else{

        if(event->timerId() == loResTimerId){

            ccGear++;
            if(ccGear == 3){
                //qDebug() << " Cambia";
                ccGear  = 0;
                g++;
                setProperty("gear",g);

                if( g > 4 )
                    g = 1;
            }

            ccIcon++;
            if(ccIcon > 2){

                ccIcon = 0;

                m_leds = ledsMap[ledIdx++];

                if(ledIdx > MAX_LED_IDX)
                    ledIdx = 0;

                emit ledsChanged(m_leds);

                qDebug() << m_leds;

            }


            emit fuelLevelChanged(m_fuelLevel);

            emit fuelLevelChanged(m_oilLevel);


            //Date.
            QLocale locale(QLocale("en_US"));
            QString dateString = locale.toString(QDate::currentDate());
            m_date = dateString;
            emit currentDateChanged(m_date);

        }
    }
}


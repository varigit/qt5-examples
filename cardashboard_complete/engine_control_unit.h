#ifndef ENGINE_CONTROL_UNIT_H
#define ENGINE_CONTROL_UNIT_H

#include <QObject>

class EngineControlUnit : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentdate MEMBER m_date                            NOTIFY currentDateChanged)
    Q_PROPERTY(QString currentime  READ currentTime WRITE setCurrentTime    NOTIFY currentTimeChanged)

    Q_PROPERTY(int   leds         MEMBER m_leds                             NOTIFY ledsChanged)
    Q_PROPERTY(float fuelLevel    MEMBER m_fuelLevel                        NOTIFY fuelLevelChanged)
    Q_PROPERTY(float oilLevel     MEMBER m_oilLevel                         NOTIFY oilLevelChanged)
    Q_PROPERTY(int   totalKm      MEMBER m_totalKm                          NOTIFY totalKmChanged)

    Q_PROPERTY(float    speed     MEMBER m_speed                            NOTIFY speedChanged)
    Q_PROPERTY(CarGear  gear      MEMBER m_gear                             NOTIFY gearChanged)

public:
    explicit EngineControlUnit(QObject *parent = nullptr);

    void timerEvent(QTimerEvent *event);

    QString currentTime(){
        return(m_currentTime);
    }
    void setCurrentTime(QString ctime){
        m_currentTime = ctime;
    }


    enum CarGear {
        P = 1,
        R = 2,
        N = 3,
        D = 4
    };
    Q_ENUM(CarGear)

signals:
    void speedChanged(float speed);
    void gearChanged(CarGear gear);
    void currentTimeChanged(QString currentime);
    void currentDateChanged(QString currentdate);

    void ledsChanged(int leds);
    void fuelLevelChanged(float fuelLevel);
    void oilLevelChanged (float oilLevel);
    void totalKmChanged(float totalKm);


public slots:

private:
    float m_speed;
    float m_incr_speed;

    QString m_currentTime;
    QString m_date;

    CarGear m_gear;

    int ccGear;
    int g;

    bool m_run_ani;

    int ccIcon;

    #define MAX_LED_IDX 9
    int ledsMap[MAX_LED_IDX];
    int ledIdx;

    int m_leds;

    float decFuel;
    float m_fuelLevel;
    float decOil;
    float m_oilLevel;

    float m_totalKm;
    float inc_km;

    int hiResTimerId;
    int loResTimerId;
};

#endif // ENGINE_H

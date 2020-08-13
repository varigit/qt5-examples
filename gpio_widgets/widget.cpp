/* This software is released under GPL
 * For example code programming use only.
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFile>
#include <QKeyEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //
    // Set StyleSheet for application
    //
    QFile file(":/gui/styleCss.txt");
    file.open(QFile::ReadOnly);
    QString mStyleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(mStyleSheet);

    //GPIO ID LED
    // 99 - 100 - 110 - 113

    QFile exportFile("/sys/class/gpio/export");
    exportFile.open(QIODevice::WriteOnly);
    QString gpioNumber = QString::number(99);
    exportFile.write(gpioNumber.toUtf8());
    exportFile.close();

    QFile outFile("/sys/class/gpio/gpio99/direction");
    outFile.open(QIODevice::WriteOnly);
    QString outString = QString("out");
    outFile.write(outString.toUtf8());
    outFile.close();


    setPin(100,"out");
    setPin(110,"out");
    setPin(113,"out");

    gDemoMode = false;
    _lamp = 0x87035a7a;
    _mask = 0x00000001;

}

Widget::~Widget()
{
    delete ui;

    QFile exportFile("/sys/class/gpio/unexport");
    if(exportFile.open(QIODevice::WriteOnly)){
        QString gpioNumber = QString::number(99);
        exportFile.write(gpioNumber.toUtf8());
        exportFile.close();
    }
}

void Widget::setPin(int pin, QString inout){

    QFile exportFile("/sys/class/gpio/export");
    if(exportFile.open(QIODevice::WriteOnly)){
        QString gpioNumber = QString::number(pin);
        exportFile.write(gpioNumber.toUtf8());
        exportFile.close();

        QFile outFile(QString("/sys/class/gpio/gpio%1/direction").arg(pin));
        if(outFile.open(QIODevice::WriteOnly)){
            outFile.write(inout.toUtf8());
            outFile.close();
        }else{
            qDebug() << "GPIO set direction pin: " << pin << " failed";
        }
    }else {
        qDebug() << "GPIO export pin: " << pin << " failed";
    }
}

void Widget::writePin(int pin, QString value){

    QFile valFile(QString("/sys/class/gpio/gpio%1/value").arg(pin));
    if(valFile.open(QIODevice::WriteOnly)){
        valFile.write(value.toUtf8());
        valFile.close();
    }
}

bool Widget::readPin(int pin){

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

void Widget::timerEvent(QTimerEvent *eve)
{
    if(eve->timerId() == m_polling){

        if(_lamp & _mask){
            ui->p4_Button->animateClick();
        }
        _mask = _mask << 1;
        if( _mask == 0){
            _mask = 0x00000001;
        }

    }
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
    qDebug() << "Press :" << ev->key();

    if(ev->key() == 16777313){
        ui->p4_Button->animateClick();
    }
}

void Widget::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << "Release :" << ev->key();

    if(ev->key() == 16777313){
        ui->p4_Button->animateClick();
    }else
    if(ev->key() == 16777235){
        ui->p3_Button->animateClick();
    }else
    if(ev->key() == 16777232){
        ui->P2_Button->animateClick();
    }else
    if(ev->key() == 16777237){
        ui->P1_Button->animateClick();
    }
}

void Widget::on_P1_Button_clicked(bool checked)
{
    qDebug() << "P1 press status: " << checked;

    //ui->Led1_label->setText(QString("LED1=%1").arg(checked));
    ui->Led1_label->setValue(checked);

    if(checked)
        writePin(100,"1");
    else
        writePin(100,"0");
}

void Widget::on_P2_Button_clicked(bool checked)
{
    qDebug() << "P2 press status: " << checked;

    //ui->Led2_label->setText(QString("LED2=%1").arg(checked));
    ui->Led2_label->setValue(checked);

    if(checked)
        writePin(110,"1");
    else
        writePin(110,"0");
}

void Widget::on_p3_Button_clicked(bool checked)
{
    qDebug() << "P3 press status: " << checked;

    //ui->Led3_label->setText(QString("LED3=%1").arg(checked));
    ui->Led3_label->setValue(checked);

    if(checked)
        writePin(113,"1");
    else
        writePin(113,"0");
}

void Widget::on_p4_Button_pressed()
{
    qDebug() << "P4 Pressed";

    //ui->Led4_label->setText(QString("LED4=ON"));
    ui->Led4_label->setValue(true);
    ui->plotWidget->setInput(true);

    QFile valFile("/sys/class/gpio/gpio99/value");
    valFile.open(QIODevice::WriteOnly);
    QString outString = QString("1");
    valFile.write(outString.toUtf8());
    valFile.close();
}

void Widget::on_p4_Button_released()
{
    qDebug() << "P4 Released";

    //ui->Led4_label->setText(QString("LED4=OFF"));
    ui->Led4_label->setValue(false);
    ui->plotWidget->setInput(false);

    QFile valFile("/sys/class/gpio/gpio99/value");
    valFile.open(QIODevice::WriteOnly);
    QString outString = QString("0");
    valFile.write(outString.toUtf8());
    valFile.close();
}

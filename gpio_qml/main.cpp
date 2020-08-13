#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
/* This software is released under GPL
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include "iocontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    IoControl iocontrol;

    engine.rootContext()->setContextProperty("iocontrol",&iocontrol);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

/*  //To excanche data from c++ to QML connect signals:
    QObject* pMyScope = engine.rootObjects().first()->findChild<QObject*>("myScope");
    pMyScope->setProperty("colorLine","red");
    QObject::connect(pMyScope, SIGNAL(myclicked()), &iocontrol, SLOT(onClicked()));
*/

    return app.exec();
}

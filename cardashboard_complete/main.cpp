#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "engine_control_unit.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    EngineControlUnit engine_control_unit;

    engine.rootContext()->setContextProperty("_engine_control_unit", &engine_control_unit);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}

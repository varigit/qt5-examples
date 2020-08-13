/* This software is released under GPL
 * For example code programming use only.
 * Program is free and you can use it at your own risk there is no warranty of any kind.
 * This software is not optimized and it is used only as an example for workshop and web tutorial.
 * 2019, Giorgio Marinangeli, <giorgiomarinangeli71@gmail.com>
 */

#include "widget.h"
#include <QApplication>
#include <QDebug>


void crashMessageOutput(QtMsgType type, const QMessageLogContext &, const QString & str) {

    const char * msg = str.toStdString().c_str();

    //qDebug() << "Global msg handler: " << QString(str);

    Q_UNUSED(type)
    Q_UNUSED(msg)
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QStringList args = QCoreApplication::arguments();
    if(args.count()){
        qDebug() << args.at(0);
        for(int i=1;i<args.count();i++){
            if(args.at(i).contains("--demo")){
                w.setDemo();

                qDebug() << "DEMO MODE";
                qInstallMessageHandler(crashMessageOutput);

            }
        }
    }

#ifdef DESKTOP_PLATFORM
    w.show();
#else
    w.showFullScreen();
#endif

    return a.exec();
}

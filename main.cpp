#include <QCoreApplication>
#include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
    //
    // return a.exec();


    Debugging *debug = Debugging::getInstance();
    qDebug() << "Hello, World!";
    qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);

    qDebug() << "Hello, World!";



    return 0;
}

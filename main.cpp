#include <QCoreApplication>
#include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);
    qDebug() << "Hello, World!";

    return 0;
}

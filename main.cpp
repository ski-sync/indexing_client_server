#include <QCoreApplication>
// #include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);
    qDebug() << "Hello, World!";

    return 0;
}

#include <QCoreApplication>
#include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    // debugging needs to be a pointer to be able to use the singleton pattern
    const Debugging *debugging = Debugging::getInstance();
    qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);
    qDebug() << "Hello, World!";

    return 0;
}

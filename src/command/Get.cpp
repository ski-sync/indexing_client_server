#include "../../includes/command/Get.h"

Get::Get(): ICommand()
{
    qDebug() << "Hello, World!";
}

void Get::execute()
{
    qDebug() << "Get command executed";
}
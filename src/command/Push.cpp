#include "../../includes/command/Push.h"

Push::Push(): ICommand()
{
    qDebug() << "Hello, World!";
}

void Push::execute()
{
    qDebug() << "Push command executed";
}
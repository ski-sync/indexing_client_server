#include "../../includes/command/Add.h"

Add::Add(): ICommand()
{
   qDebug() << "Hello, World!";
}

void Add::execute()
{
    qDebug() << "Add command executed";
}

#include "../../includes/command/Clear.h"

void Clear::execute()
{
    qDebug() << "Clear command executed";
}

Clear::Clear(): ICommand()
{
    qDebug() << "Hello, World!";
}

#include "../../includes/command/Search.h"

void Search::execute()
{
    qDebug() << "Search command executed";
}

Search::Search(): ICommand()
{
    qDebug() << "Hello, World!";
}
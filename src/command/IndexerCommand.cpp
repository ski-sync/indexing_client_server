#include "../../includes/command/IndexerCommand.h"

IndexerCommand::IndexerCommand(): ICommand()
{
    qDebug() << "Hello, World!";
}

void IndexerCommand::execute()
{
    qDebug() << "Indexer command executed";
}

#ifndef INDEXER_COMMAND_H
#define INDEXER_COMMAND_H

#include "../interface/ICommand.h"
#include "qdebug.h"

class IndexerCommand : public ICommand
{
    void execute() override;
    public:
        IndexerCommand();
};
#endif //INDEXER_COMMAND_H

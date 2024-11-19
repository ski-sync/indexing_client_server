#ifndef INDEXER_COMMAND_H
#define INDEXER_COMMAND_H

#include "../interface/ICommand.h"

class IndexerCommand : public ICommand
{
    void execute() override;
    public:
        IndexerCommand();
};
#endif //INDEXER_COMMAND_H

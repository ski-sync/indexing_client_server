#ifndef INDEXER_COMMAND_H
#define INDEXER_COMMAND_H

#include <QDebug>
#include "../interface/ICommand.h"
#include "../IndexerThread.h"

class IndexerCommand : public ICommand {
public:
    void execute(const QList<Token> &tokens) override;
};
#endif //INDEXER_COMMAND_H

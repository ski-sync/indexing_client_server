#ifndef INDEXER_COMMAND_H
#define INDEXER_COMMAND_H

#include <QDebug>
#include "../interface/ICommand.h"

class IndexerCommand : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing INDEXER command with tokens:" << tokens;
    }
};
#endif //INDEXER_COMMAND_H

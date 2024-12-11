#ifndef SEARCH_H
#define SEARCH_H

#include <QDebug>
#include "../interface/ICommand.h"

class Search : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing SEARCH command with tokens:" << tokens;
    }
};
#endif //SEARCH_H

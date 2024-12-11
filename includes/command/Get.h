#ifndef GET_H
#define GET_H

#include <QDebug>
#include "../interface/ICommand.h"

class Get : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing GET command with tokens:" << tokens;
    }
};
#endif //GET_H

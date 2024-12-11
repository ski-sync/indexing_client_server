#ifndef PUSH_H
#define PUSH_H

#include <QDebug>
#include "../interface/ICommand.h"

class Push : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing PUSH command with tokens:" << tokens;
    }
};

#endif //PUSH_H

#ifndef CLEAR_H
#define CLEAR_H

#include <QDebug>
#include "../interface/ICommand.h"

class Clear : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing CLEAR command with tokens:" << tokens;
    }
};
#endif //CLEAR_H

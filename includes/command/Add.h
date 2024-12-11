#ifndef ADD_H
#define ADD_H

#include <QDebug>
#include "../interface/ICommand.h"

class Add : public ICommand {
public:
    void execute(const QList<Token> &tokens) override {
        // Handle INDEXER commands like START, STOP, STATUS, etc.
        qDebug() << "Executing ADD command with tokens:" << tokens;
    }
};
#endif //ADD_H

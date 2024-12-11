#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QList>
#include "../token.h"

class ICommand {
public:
    virtual void execute(const QList<Token> &tokens) = 0;
    virtual ~ICommand() = default;
};

#endif // ICOMMAND_H

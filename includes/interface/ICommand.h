//
// Created by louis on 18/11/2024.
//

#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <qlist.h>
#include "../enum/CommandEnum.h"

class ICommand {
    QStringList tokens;
public:
    virtual void execute() = 0;
    ICommand() = default;
private:
};

#endif //ICOMMAND_H

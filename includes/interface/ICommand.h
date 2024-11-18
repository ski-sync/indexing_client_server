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
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    QMap<Command, QStringList> ICommand::commandParse();
    Command ICommand::stringToCommand(const QString& token);


private:
    ICommand() = default;
};

#endif //ICOMMAND_H

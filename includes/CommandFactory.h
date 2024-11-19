
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "QString"
#include "../includes/interface/ICommand.h"
#include <stdio.h>

class CommandFactory
{
    public:
         std::unique_ptr<ICommand> createCommand(QString commandName);

};


#endif //COMMANDFACTORY_H

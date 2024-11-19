
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "QString"
#include "../includes/interface/ICommand.h"
#include "../includes/Command/Add.h"
#include "../includes/Command/Clear.h"
#include "../includes/Command/Get.h"
#include "../includes/Command/IndexerCommand.h"
#include "../includes/Command/Push.h"
#include <stdio.h>

class CommandFactory
{
    public:
         std::unique_ptr<ICommand> createCommand(QString commandName);

};


#endif //COMMANDFACTORY_H


#include "../includes/CommandFactory.h"
#include "../includes/Command/Add.h"
#include "../includes/Command/Clear.h"
#include "../includes/Command/Get.h"
#include "../includes/Command/IndexerCommand.h"
#include "../includes/Command/Push.h"

std::unique_ptr<ICommand> CommandFactory::createCommand(QString commandName)
{
    if(commandName == "add")
    {
        return std::make_unique<Add>(); // Error: no matching function for call to 'make_unique<Add>()'
    }
    else if(commandName == "clear")
    {
        return std::make_unique<Clear>();
    }
    else if(commandName == "get")
    {
        return std::make_unique<Get>();
    }
    else if(commandName == "indexercommand")
    {
        return std::make_unique<IndexerCommand>();
    }
    else if(commandName == "push")
    {
        return std::make_unique<Push>();
    }
    else
    {
        return nullptr;
    }
}


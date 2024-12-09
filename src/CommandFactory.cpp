
#include "../includes/CommandFactory.h"
#include "../includes/Command/Add.h"
#include "../includes/Command/Clear.h"
#include "../includes/Command/Get.h"
#include "../includes/Command/IndexerCommand.h"
#include "../includes/Command/Push.h"

std::unique_ptr<ICommand> CommandFactory::createCommand(Command commandName)
{
    switch (commandName)
    {
        case Command::ADD:
            return std::make_unique<Add>();
        case Command::CLEAR:
            return std::make_unique<Clear>();
        case Command::GET:
            return std::make_unique<Get>();
        case Command::INDEXER:
            return std::make_unique<IndexerCommand>();
        case Command::PUSH:
            return std::make_unique<Push>();
        default:
            return nullptr;
    }
}


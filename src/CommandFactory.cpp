
#include "../includes/CommandFactory.h"
#include "../includes/Command/Add.h"
#include "../includes/Command/Clear.h"
#include "../includes/Command/Get.h"
#include "../includes/Command/IndexerCommand.h"
#include "../includes/Command/Push.h"

std::unique_ptr<ICommand> CommandFactory::createCommand(const QString &commandType) {
    if (commandType == "INDEXER") {
        qDebug() << "Creating INDEXER command";
        return std::make_unique<IndexerCommand>();
    } else if (commandType == "GET") {
        qDebug() << "Creating GET command";
        return std::make_unique<Get>();
    } else if (commandType == "CLEAR") {
        qDebug() << "Creating CLEAR command";
        return std::make_unique<Clear>();
    } else if (commandType == "ADD") {
        qDebug() << "Creating ADD command";
        return std::make_unique<Add>();
    } else if (commandType == "PUSH") {
        qDebug() << "Creating PUSH command";
        return std::make_unique<Push>();
    } else if (commandType == "SEARCH") {
        qDebug() << "Creating SEARCH command";
        return std::make_unique<Search>();
    }
    return nullptr;
}

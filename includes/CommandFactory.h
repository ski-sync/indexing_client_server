
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H


#include <memory>

#include "command/Add.h"
#include "command/Clear.h"
#include "command/Get.h"
#include "interface/ICommand.h"
#include "command/IndexerCommand.h"
#include "command/Push.h"
#include "command/Search.h"

class CommandFactory {
public:
    static std::unique_ptr<ICommand> createCommand(const QString &commandType);
};


#endif //COMMANDFACTORY_H

#include "../../includes/interface/ICommand.h"


QMap<Command, QStringList> ICommand::commandParse() {
    QMap<Command, QStringList> commandMap;
    for (int i = 0; i < tokens.size(); i++) {
        QString token = tokens[i];
        switch (stringToCommand(token)) {
            case Command::UNKNOWN:
                continue;
            default:
                commandMap[stringToCommand(token)] = QStringList();
            while (i + 1 < tokens.size() && stringToCommand(tokens[i + 1]) == Command::UNKNOWN) {
                commandMap[stringToCommand(token)].append(tokens[++i]);
            }
            return commandMap;
        }
    }
    return commandMap;
}


Command ICommand::stringToCommand(const QString& token) {
    if (token == "indexer") return Command::INDEXER;
    if (token == "get") return Command::GET;
    if (token == "add") return Command::ADD;
    if (token == "push") return Command::PUSH;
    if (token == "clear") return Command::CLEAR;
    if (token == "search") return Command::SEARCH;
    return Command::UNKNOWN;
}
#include "../../includes/interface/ICommand.h"


QPair<Command, QStringList> ICommand::commandParse() {
    if (tokens.isEmpty()) {
        return {Command::UNKNOWN, QStringList()};
    }

    Command cmd = stringToCommand(tokens[0]);
    QStringList args = tokens.mid(1);
    return {cmd, args};
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

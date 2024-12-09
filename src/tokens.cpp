#include "../includes/tokens.h"


Tokens* Tokens::instance = nullptr;

Tokens::Tokens() {
    tokens = QStringList();
}

Tokens::~Tokens() {
    delete instance;
}

void Tokens::setTokens(QStringList _tokens) {
    tokens = _tokens;
}

Tokens* Tokens::getInstance() {
    if (instance == nullptr) {
        instance = new Tokens();
    }
    return instance;
}

QStringList Tokens::getTokens() {
    return tokens;
}

QPair<Command, QStringList> Tokens::commandParse() {
    if (tokens.isEmpty()) {
        return {Command::UNKNOWN, QStringList()};
    }

    Command cmd = stringToCommand(tokens[0]);
    QStringList args = tokens.mid(1);
    return {cmd, args};
}

Command Tokens::stringToCommand(const QString& token) {
    if (token == "INDEXER") return Command::INDEXER;
    if (token == "GET") return Command::GET;
    if (token == "ADD") return Command::ADD;
    if (token == "PUSH") return Command::PUSH;
    if (token == "CLEAR") return Command::CLEAR;
    if (token == "SEARCH") return Command::SEARCH;
    return Command::UNKNOWN;
}
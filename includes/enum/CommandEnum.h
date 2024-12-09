#ifndef COMMANDENUM_H
#define COMMANDENUM_H
#include <QDebug>

enum class Command {
    INDEXER,
    GET,
    ADD,
    PUSH,
    CLEAR,
    SEARCH,
    UNKNOWN,
};

inline QDebug operator<<(QDebug debug, const Command& cmd) {
    switch (cmd) {
        case Command::INDEXER:
            debug << "INDEXER";
        break;
        case Command::GET:
            debug << "GET";
        break;
        case Command::ADD:
            debug << "ADD";
        break;
        case Command::PUSH:
            debug << "PUSH";
        break;
        case Command::CLEAR:
            debug << "CLEAR";
        break;
        case Command::SEARCH:
            debug << "SEARCH";
        break;
        case Command::UNKNOWN:
            debug << "UNKNOWN";
        break;
    }
    return debug;
}

#endif //COMMANDENUM_H

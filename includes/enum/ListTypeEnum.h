#ifndef LISTTYPEENUM_H
#define LISTTYPEENUM_H
#include <QDebug>

enum class ListType {
    BLACKLIST,
    WHITELIST,
    FILTERS,
    SKIPPED_FILTER
};

inline QDebug operator<<(QDebug debug, const ListType& listType) {
    switch (listType) {
        case ListType::BLACKLIST:
            debug << "BLACKLIST";
        break;
        case ListType::WHITELIST:
            debug << "WHITELIST";
        break;
        case ListType::FILTERS:
            debug << "FILTERS";
        break;
        case ListType::SKIPPED_FILTER:
            debug << "SKIPPED_FILTER";
        break;
    }
    return debug;
}

#endif //LISTTYPEENUM_H

#include "../../includes/command/Clear.h"

void Clear::execute(const QList<Token> & tokens) {
    qDebug() << "Executing CLEAR command with tokens:" << tokens;
    if (tokens.size() < 2) {
        qDebug() << "Not enough arguments!";
        return;
    }
    const QString listType = tokens[1].getValue();
    QString commandSql = "DELETE FROM ";

    qDebug() << "Flag" << listType;
    if (listType == "WHITELIST") {
        std::cout << "Clearing whitelist\n";
        bdd->clearWhitelist();
    } else if (listType == "BLACKLIST") {
        std::cout << "Clearing blacklist\n";
        bdd->clearBlacklist();
    } else if (listType == "FILTERS") {
        std::cout << "Clearing filters\n";
        bdd->clearFilters();
    } else if (listType == "SKIPPED_FILTER") {
        std::cout << "Clearing skipped filters\n";
        bdd->clearSkippedFilters();
    } else {
        std::cout << "Unknown flag\n";
        return;
    }
}
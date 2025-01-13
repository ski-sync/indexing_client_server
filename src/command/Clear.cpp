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
        qDebug() << "Clearing whitelist";
        bdd->clearWhitelist();
    } else if (listType == "BLACKLIST") {
        qDebug() << "Clearing blacklist";
        bdd->clearBlacklist();
    } else if (listType == "FILTERS") {
        qDebug() << "Clearing filters";
        bdd->clearFilters();
    } else if (listType == "SKIPPED_FILTER") {
        qDebug() << "Clearing skipped filters";
        bdd->clearSkippedFilters();
    } else {
        qDebug() << "Unknown flag";
        return;
    }
}
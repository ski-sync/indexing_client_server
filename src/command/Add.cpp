#include "../../includes/command/Add.h"

void Add::execute(const QList<Token> &tokens) {
    qDebug() << "Executing ADD command with tokens:" << tokens;
    if (tokens.size() < 3) {
        qDebug() << "Not enough arguments!";
        return;
    }
    const QString listType = tokens[1].getValue();
    const QString value = tokens[2].getValue();
    QString commandSql = "INSERT INTO ";

    qDebug() << "Flag" << listType;
    switch (listType) {
        case "WHITELIST":
            qDebug() << "Adding to whitelist";
            commandSql += "whitelist (value) VALUES ('" + value + "')";
            break;
        case "BLACKLIST":
            qDebug() << "Adding to blacklist";
            commandSql += "blacklist (value) VALUES ('" + value + "')";
            break;
        case "FILTERS":
            qDebug() << "Adding to filters";
            commandSql += "filters (value) VALUES ('" + value + "')";
            break;
        case "SKIPPED_FILTER":
            qDebug() << "Adding to skipped filters";
            commandSql += "skipped_filters (value) VALUES ('" + value + "')";
            break;
        default:
            qDebug() << "Unknown flag";
            break;
    }

}


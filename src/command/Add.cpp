#include "../../includes/command/Add.h"

void Add::execute(const QList<Token> &tokens) {
    qDebug() << "Executing ADD command with tokens:" << tokens;
    if (tokens.size() < 3) {
        qDebug() << "Not enough arguments!";
        return;
    }
    const QString listType = tokens[1].getValue();
    QString value = tokens[2].getValue();

    QStringList extensionList = value.split(',');

    for (QString& ext : extensionList) {
        ext = '\'' + ext + '\'';
    }

    value = extensionList.join(",");

    qDebug() << "Flag" << listType;
    if (listType == "WHITELIST") {
        qDebug() << "Adding to whitelist";
        bdd->add("whitelist", value);
    } else if (listType == "BLACKLIST") {
        qDebug() << "Adding to blacklist";
        bdd->add("blacklist", value);
    } else if (listType == "FILTERS") {
        qDebug() << "Adding to filters";
        bdd->add("filters", value);
    } else if (listType == "SKIPPED_FILTER") {
        qDebug() << "Adding to skipped filters";
        bdd->add("skipped_filters", value);
    } else {
        qDebug() << "Unknown flag";
        return;
    }
}


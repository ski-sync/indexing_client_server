#include "../../includes/command/Push.h"

void Push::execute(const QList<Token>& tokens)
{
    qDebug() << "Executing ADD command with tokens:" << tokens;
    if (tokens.size() < 4) {
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

    if (tokens[3].getValue() != "DONE") {
        qDebug() << "Command not finished!";
        return;
    }

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

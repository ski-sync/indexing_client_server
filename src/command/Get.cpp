#include "../../includes/command/Get.h"

void Get::execute(const QList<Token> &tokens) {
    qDebug() << "Executing Get command with tokens:" << tokens;
    if (tokens.size() < 2) {
        qDebug() << "Not enough arguments!";
        return;
    }
    const QString listType = tokens[1].getValue();
    QString response;


    qDebug() << "Flag" << listType;
    if (listType == "WHITELIST") {
        qDebug() << bdd->get("whitelist");
    } else if (listType == "BLACKLIST") {
        qDebug() << bdd->get("blacklist");
    } else if (listType == "FILTERS") {
        qDebug() << bdd->get("filters");
    } else if (listType == "SKIPPED_FILTER") {
        qDebug() << bdd->get("skipped_filters");
    } else {
        qDebug() << "Unknown flag";
        return;
    }
}


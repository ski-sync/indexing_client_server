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
        const auto whitelist = bdd->get("whitelist");
        for (const auto &line : whitelist) {
            response += line + "\n";
        }
        std::cout << response.toStdString();
    } else if (listType == "BLACKLIST") {
        const auto blacklist = bdd->get("blacklist");
        for (const auto &line : blacklist) {
            response += line + "\n";
        }
        std::cout << response.toStdString();
    } else if (listType == "FILTERS") {
        const auto filters = bdd->get("filters");
        for (const auto &line : filters) {
            response += line + "\n";
        }
        std::cout << response.toStdString();
    } else if (listType == "SKIPPED_FILTER") {
        const auto skippedFilters = bdd->get("skipped_filters");
        for (const auto &line : skippedFilters) {
            response += line + "\n";
        }
        std::cout << response.toStdString();
    } else {
        qDebug() << "Unknown flag";
        return;
    }
}


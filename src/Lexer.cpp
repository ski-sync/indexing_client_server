#include "../includes/Lexer.h"
#include <QDebug>



struct TokenReplacement {
    QString from;
    QString to;
};

const QVector<TokenReplacement> replacements = {
    {"SINCE LAST", "SINCE_LAST"},
    {" OR ", ","},
    {":", " "},
};

QString Lexer::normalize(const QString &input) {
    QString result = input;
    for (const auto &replacement : replacements) {
        result.replace(replacement.from, replacement.to);
    }
    return result;
}


// Tokenize and classify the input
void Lexer::tokenize(const QString &input) {
    QString normalized = normalize(input);
    QStringList quoteSplit = normalized.split("\"");
    tokens.clear();

    for (int i = 0; i < quoteSplit.size(); i++) {
        QString segment = quoteSplit[i].trimmed();

        if (segment.isEmpty()) continue;

        if (i % 2 == 0) {
            QStringList spaceSplit = segment.split(" ", Qt::SkipEmptyParts);
            for (const QString &part : spaceSplit) {
                classifyAndAddToken(part);
            }
        } else {
            classifyAndAddToken("\"" + segment + "\"");
        }
    }

    index = 0;
}


void Lexer::classifyAndAddToken(const QString &tokenValue) {
    if (tokenValue.startsWith("\"") && tokenValue.endsWith("\"")) {
        tokens.append(Token("STRING", tokenValue));
    } else if (isLogicalOperator(tokenValue)) {
        tokens.append(Token("LOGICAL_OPERATOR", tokenValue));
    } else if (isKeyword(tokenValue)) {
        tokens.append(Token("OPTION", tokenValue));
    } else if (isCommand(tokenValue)) {
        tokens.append(Token("COMMAND", tokenValue));
    } else if (isFlag(tokenValue)) {
        tokens.append(Token("FLAG", tokenValue));
    } else if (isUnitType(tokenValue)) {
        tokens.append(Token("UNIT_TYPE", tokenValue));
    } else if (isIndexerSubcommand(tokenValue)) {
        tokens.append(Token("INDEXER_SUBCOMMAND", tokenValue));
    } else if (isSize(tokenValue)) {
        tokens.append(Token("SIZE", tokenValue));
    } else if (isListValue(tokenValue)) {
        tokens.append(Token("LIST_VALUE", tokenValue));
    } else if (isDate()) {
        tokens.append(Token("DATE", tokenValue));
    } else {
        tokens.append(Token("PARAM_VALUE", tokenValue));
    }
}

bool Lexer::isLogicalOperator(const QString &tokenValue) {
    return tokenValue == "AND" || tokenValue == "BETWEEN";
}

bool Lexer::isKeyword(const QString &tokenValue) {
    static QStringList keywords = {"LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    return keywords.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isCommand(const QString &tokenValue) {
    static QStringList commands = {"SEARCH", "CLEAR", "GET", "ADD", "PUSH", "INDEXER"};
    return commands.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isUnitType(const QString &tokenValue) {
    static QStringList unitTypes = {"DAYS", "HOURS", "MINUTES", "MONTHS", "YEARS"};
    return unitTypes.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isFlag(const QString &tokenValue) {
    static QStringList flags = {"WHITELIST", "BLACKLIST", "FILTERS", "SKIPPED_FILTERS"};
    return flags.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isIndexerSubcommand(const QString &tokenValue) {
    static QStringList subcommands = {"STATUS", "START", "STOP", "PAUSE", "RESUME"};
    return subcommands.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isSize(const QString &tokenValue) {
    return tokenValue.contains("M") || tokenValue.contains("G") || tokenValue.contains("K");
}

bool Lexer::isListValue(const QString &tokenValue) {
    return tokenValue.contains(",");
}

bool Lexer::isDate() {
    QRegularExpression dateRegex(
        // Full date dd/mm/yyyy
        "^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([12][0-9]{3})$|"
        // Month and year mm/yyyy
        "^(0[1-9]|1[0-2])/([12][0-9]{3})$|"
        // Full year yyyy
        "^[12][0-9]{3}$|"
        // Short year yy
        "^[0-9]{2}$"
    );

    return dateRegex.match(value).hasMatch();
}

QVector<Token> Lexer::getTokens() {
    return tokens;
}

void Lexer::printTokens() {
    for (Token &token : tokens) {
        qDebug() << token.getType() << " " << token.getValue();
    }
}

#ifndef LEXER_H
#define LEXER_H
#include <qlist.h>
#include "token.h"

class Lexer {
    QList<Token> tokens;
    int64_t index = 0;
public:
    QString normalize(const QString &input);
    void tokenize(const QString &input);
    void printTokens();
    void classifyAndAddToken(const QString &tokenValue);

    static bool isLogicalOperator(const QString &tokenValue);
    static bool isKeyword(const QString &tokenValue);
    static bool isCommand(const QString &tokenValue);
    static bool isUnitType(const QString &tokenValue);
    static bool isFlag(const QString &tokenValue);
    static bool isIndexerSubcommand(const QString &tokenValue);
    static bool isSize(const QString &tokenValue);
    static bool isListValue(const QString &tokenValue);
    static bool isDate(const QString &tokenValue);

    QVector<Token> getTokens();


};

#endif //LEXER_H

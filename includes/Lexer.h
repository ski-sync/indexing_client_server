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

    bool isLogicalOperator(const QString &tokenValue);
    bool isKeyword(const QString &tokenValue);
    bool isCommand(const QString &tokenValue);
    bool isUnitType(const QString &tokenValue);
    bool isFlag(const QString &tokenValue);
    bool isIndexerSubcommand(const QString &tokenValue);

    bool isSize(const QString &tokenValue);

    bool isListValue(const QString &tokenValue);

    bool isDate();

    QVector<Token> getTokens();


};

#endif //LEXER_H

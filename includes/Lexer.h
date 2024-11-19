#ifndef LEXER_H
#define LEXER_H
#include <qlist.h>
#include "enum/CommandEnum.h"


class Lexer {
    QStringList tokens;
    int64_t index = 0;
public:
    void tokenize(const QString &input);
    void printTokens();
    QString getNextToken();
    QString currentToken();


};

#endif //LEXER_H

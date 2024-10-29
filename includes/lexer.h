#ifndef LEXER_H
#define LEXER_H
#include <qlist.h>


class Lexer {
    QStringList tokens;
    int64_t index = 0;
public:
    void tokenize(QString input);
    void printTokens();
    QString getNextToken();
    QString currentToken();

};

#endif //LEXER_H

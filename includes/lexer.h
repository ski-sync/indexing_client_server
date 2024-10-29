#ifndef LEXER_H
#define LEXER_H


class Lexer {
    QStringList tokens;
    int64_t index = 0;
public:
    QStringList tokenize(QString input);
    void printTokens();
};

#endif //LEXER_H

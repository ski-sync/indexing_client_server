#include "../includes/lexer.h"


QStringList Lexer::tokenize(QString input)
{
    // input = input.trimmed();
    QStringList tokens = input.split(" ");
    return tokens;
}

void Lexer::printTokens()
{

    for (int i = 0; i < tokens.size(); i++)
    {
        qDebug() << tokens[i];
        qDebug() << "";
        // qDebug(tokens[i].toLatin1());
    }
}

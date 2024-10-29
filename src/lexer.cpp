#include "../includes/lexer.h"
#include <QDebug>



void Lexer::tokenize(QString input)
{
    // input = input.trimmed();
    const QStringList token = input.split(" ");
    this->tokens = token;

}

void Lexer::printTokens()
{
    for (auto & token : this->tokens)
    {
        qDebug() << token;
    }
}

QString Lexer::currentToken()
{
    return this->tokens[this->index];
}

QString Lexer::getNextToken()
{
    return this->tokens[this->index++];
}

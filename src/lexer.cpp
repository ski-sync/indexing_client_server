#include "../includes/lexer.h"
#include <QDebug>



void Lexer::tokenize(QString input)
{
    QStringList result;
    QStringList quoteSplit = input.split("\"");

    for (int i = 0; i < quoteSplit.size(); i++)
    {
        QString segment = quoteSplit[i].trimmed();

        if (segment.isEmpty())
            continue;

        if (i % 2 == 0)
        {
            QStringList spaceSplit = segment.split(" ", Qt::SkipEmptyParts);
            result.append(spaceSplit);
        }
        else
        {
            result.append(segment);
        }
    }

    this->tokens = result;
    this->index = 0;
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

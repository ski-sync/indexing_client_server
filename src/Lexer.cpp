#include "../includes/Lexer.h"
#include <QDebug>



void Lexer::tokenize(const QString &input)
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

QMap<Command, QStringList> Lexer::commandParse() {
    QMap<Command, QStringList> commandMap;
    for (int i = 0; i < tokens.size(); i++) {
        QString token = tokens[i];
        switch (stringToCommand(token)) {
            case Command::UNKNOWN:
                continue;
            default:
                commandMap[stringToCommand(token)] = QStringList();
                while (i + 1 < tokens.size() && stringToCommand(tokens[i + 1]) == Command::UNKNOWN) {
                    commandMap[stringToCommand(token)].append(tokens[++i]);
                }
            return commandMap;
        }
    }
    return commandMap;
}


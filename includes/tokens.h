#ifndef TOKENS_H
#define TOKENS_H
#include <qcontainerfwd.h>
#include <qlist.h>

#include "enum/CommandEnum.h"

class Tokens {
private:
    QStringList tokens;
    static Tokens* instance;
    Tokens();
    ~Tokens();


public:
    static Tokens* getInstance();
    void setTokens(QStringList _tokens);
    QStringList getTokens();
    QPair<Command, QStringList> commandParse();
    static Command stringToCommand(const QString& token);
};
#endif //TOKENS_H

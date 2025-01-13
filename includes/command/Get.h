#ifndef GET_H
#define GET_H

#include <QDebug>
#include "../interface/ICommand.h"
#include <qstring.h>
#include <iostream>

class Get : public ICommand {
    Bdd *bdd = Bdd::getInstance();
public:
    void execute(const QList<Token> &tokens) override;
};
#endif //GET_H

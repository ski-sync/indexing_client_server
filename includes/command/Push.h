#ifndef PUSH_H
#define PUSH_H

#include <QDebug>
#include "../interface/ICommand.h"

class Push : public ICommand {
    Bdd *bdd = Bdd::getInstance();
public:
    void execute(const QList<Token> &tokens) override;
};

#endif //PUSH_H

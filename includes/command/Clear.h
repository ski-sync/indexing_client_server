#ifndef CLEAR_H
#define CLEAR_H

#include <QDebug>
#include "../interface/ICommand.h"

class Clear : public ICommand {
    Bdd *bdd = Bdd::getInstance();
public:
    void execute(const QList<Token> &tokens) override;
};
#endif //CLEAR_H

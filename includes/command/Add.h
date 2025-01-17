#ifndef ADD_H
#define ADD_H

#include <QDebug>
#include "../interface/ICommand.h"

class Add : public ICommand {
    Bdd *bdd = Bdd::getInstance();
public:
    void execute(const QList<Token> &tokens) override;
};
#endif //ADD_H

#ifndef GET_H
#define GET_H

#include <QDebug>
#include "../interface/ICommand.h"

class Get : public ICommand {
public:
    void execute(const QList<Token> &tokens) override;
};
#endif //GET_H

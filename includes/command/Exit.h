#ifndef EXIT_H
#define EXIT_H

#include "../interface/ICommand.h"

class Exit : public ICommand {
public:
    void execute(const QList<Token> &tokens) override;
};

#endif //EXIT_H

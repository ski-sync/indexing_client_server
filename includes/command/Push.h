#ifndef PUSH_H
#define PUSH_H

#include "../interface/ICommand.h"
#include "qdebug.h"

class Push : public ICommand
{
    void execute() override;
    public:
        Push();
};

#endif //PUSH_H

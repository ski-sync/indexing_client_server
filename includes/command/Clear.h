#ifndef CLEAR_H
#define CLEAR_H

#include "../interface/ICommand.h"

class Clear : public ICommand
{
    void execute() override;
    public:
        Clear();
};
#endif //CLEAR_H

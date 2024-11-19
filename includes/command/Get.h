#ifndef GET_H
#define GET_H

#include "../interface/ICommand.h"

class Get : public ICommand
{
    void execute() override;
    public:
        Get();
};

#endif //GET_H

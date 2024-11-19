#ifndef ADD_H
#define ADD_H

#include "../interface/ICommand.h"

class Add : public ICommand{

    void execute() override;
    public:
        Add();
};
#endif //ADD_H

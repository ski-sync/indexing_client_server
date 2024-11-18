#ifndef ADD_H
#define ADD_H

#include "../interface/ICommand.h"

class Add : public ICommand{

    void execute() override;
    public:
        Add();
        ~Add() override;
};
#endif //ADD_H



#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include "interface/IState.h"

class AddCommand: public IState {
public:
    void execute() override;
    AddCommand();
    ~AddCommand() override;
};
#endif //ADDCOMMAND_H

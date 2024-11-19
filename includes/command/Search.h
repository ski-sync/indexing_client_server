#ifndef SEARCH_H
#define SEARCH_H

#include "../interface/ICommand.h"
#include "qdebug.h"

class Search : public ICommand
{
    void execute() override;
    public:
        Search();
};

#endif //SEARCH_H

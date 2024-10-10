#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H

#include "interfaces/ICommand.h"
#include "interfaces/ISearchCommandOption.h"

class SearchCommand : public ICommand, public ISearchCommandOption{};

#endif //SEARCHCOMMAND_H

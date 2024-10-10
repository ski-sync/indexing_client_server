#ifndef INDEXERCOMMAND_H
#define INDEXERCOMMAND_H

#include "interfaces/ICommand.h"
#include "IndexerCommandOption.h"

class IndexerCommand : public ICommand, public IndexerCommandOption {};

#endif //INDEXERCOMMAND_H

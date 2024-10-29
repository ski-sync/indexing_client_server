#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H
#include <qlist.h>
#include "interface/IState.h"

class SearchCommand: public IState {
    QStringList args;
public:
    void execute() override;
    SearchCommand();
    ~SearchCommand() override;
};
#endif //SEARCHCOMMAND_H

#ifndef SEARCH_H
#define SEARCH_H

#include "../Bdd.h"
#include "../Fsm.h"
#include "../interface/ICommand.h"


class Search : public ICommand {
    Fsm *fsm = nullptr;
    QList<Token> tokens;
    QString commandSql;

public:
    void execute(const QList<Token> &tokens) override;
    void initStateMachine();
};
#endif //SEARCH_H

#ifndef FSM_H
#define FSM_H
#include <qlist.h>

#include "interface/IState.h"

class Fsm {
    IState *current_state;
    QStringList tokens;
    int index = 1;

public:
    Fsm(QStringList tokens);
    void run();
    void printState();
};

#endif //FSM_H

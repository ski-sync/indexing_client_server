#ifndef TRANSITION_H
#define TRANSITION_H
#include "typedef.h"

class State;
class Fsm;

class Transition {
    State *start = nullptr;
    State *end = nullptr;
    ConditionPtrFunc condition_func = nullptr;
    Fsm *fsm = nullptr;

public:
    Transition(State *start, State *end, ConditionPtrFunc condition, Fsm *fsm): start(start), end(end), condition_func(condition), fsm(fsm) {};
    bool run();
    void setCondition(ConditionPtrFunc condition);

    State *getStart();
    State *getEnd();
};


#endif //TRANSITION_H

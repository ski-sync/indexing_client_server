#ifndef FSM_H
#define FSM_H
#include <qlist.h>
#include "Transition.h"
#include "State.h"
#include "typedef.h"

class Fsm {
private:
    State *initialState = nullptr;
    State *currentState = nullptr;
    QList<State*> finalStates;
    QList<State*> states;
    QList<Transition*> transitions;

public:
    void run();

    void setInitialState( State* state );
    void setCurrentState( State* state );

    void addState( State* state );
    void addTransition( State* from, State* to, ConditionPtrFunc condition );
};

#endif //FSM_H

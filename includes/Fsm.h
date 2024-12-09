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
    QStringList tokens;
    int index = 0;


public:
    void run();

    void setInitialState( State* state );
    void setCurrentState( State* state );
    void setTokens( QStringList tokens );

    void addState( State* state );
    void addTransition( State* from, State* to, ConditionPtrFunc condition );
    void addFinalState( State* state );

    QString currentToken();

    void getNextToken();
    QStringList getNTokens(int size);
};

#endif //FSM_H

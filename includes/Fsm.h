#ifndef FSM_H
#define FSM_H
#include <qlist.h>
#include "Transition.h"
#include "State.h"
#include "token.h"
#include "typedef.h"

class Fsm {
private:
    State *initialState = nullptr;
    State *currentState = nullptr;
    QList<Token> tokens;
    QList<State*> finalStates;
    std::vector<std::unique_ptr<State>> states;
    std::vector<std::unique_ptr<Transition>> transitions;
    int index = 0;

public:
    void run();

    void setInitialState( State* state );
    void setCurrentState( State* state );
    void setTokens(const QList<Token> &tokens );

    void addState( State* state );
    void addTransition( State* from, State* to, ConditionPtrFunc condition );
    void addFinalState( State* state );

    Token currentToken();

    void getNextToken();
    QList<Token> getNTokens(int size);
};

#endif //FSM_H

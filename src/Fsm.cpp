#include "../includes/Fsm.h"


void Fsm::run() {
    currentState = initialState;
    while (true) {
        for (const auto transition : transitions) {
            if (transition->getStart() == currentState) {
                if (transition->run()) {
                    setCurrentState(transition->getEnd());
                    currentState->run();
                    for (const auto finalState : finalStates) {
                        if (currentState == finalState) {
                            return;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void Fsm::setInitialState(State *state) {
    initialState = state;
    addState(state);
}

void Fsm::setCurrentState(State *state) {
    currentState = state;
}

void Fsm::addState(State *state) {
    state->setFsm(this);
    states.append(state);
}

void Fsm::addTransition(State *from, State *to, ConditionPtrFunc condition) {
    auto *transition = new Transition(from, to, condition, this );
    transitions.append(transition);
}

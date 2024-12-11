#include "../includes/Fsm.h"


void Fsm::run() {
    currentState = initialState;
    while (true) {
        bool transitioned = false;
        for (const auto& transition : transitions) { // Use const reference
            if (transition->getStart() == currentState) {
                if (transition->run()) {
                    setCurrentState(transition->getEnd());
                    currentState->run();
                    if (finalStates.contains(currentState)) {
                        return; // Exit if the final state is reached
                    }
                    transitioned = true;
                    break;
                }
            }
        }

        if (!transitioned) {
            qDebug() << "FSM deadlock: No valid transitions from state:" << currentState->getName();
            return;
        }
    }
}

void Fsm::setInitialState(State *state) {
    initialState = state;
    addState(state);
}

void Fsm::setCurrentState(State *state) {
    qDebug() << "Transitioning to state:" << state->getName();
    currentState = state;
}

void Fsm::setTokens(const QList<Token> &tokens) {
    this->tokens = tokens;
    index = 0;
}

void Fsm::addState(State* state) {
    states.push_back(std::unique_ptr<State>(state)); // Use push_back for std::vector
}

void Fsm::addTransition(State* from, State* to, ConditionPtrFunc condition) {
    transitions.push_back(std::make_unique<Transition>(from, to, condition, this));
}

void Fsm::addFinalState(State *state) {
    finalStates.append(state);
}

Token Fsm::currentToken() {
    if (index < tokens.size()) {
        qDebug() << "currentToken: " << tokens[index];
        return tokens[index];
    } else {
        qDebug() << "Error: Token index out of bounds!";
        return Token(); // Return an empty token or handle the error
    }
}

void Fsm::getNextToken() {
    if (index < tokens.size() - 1) {
        index++;
    } else {
        qDebug() << "Error: No more tokens available!";
    }
}

QList<Token> Fsm::getNTokens(int size) {
    QList<Token> result;
    for (int i = index; i < qMin(index + size, tokens.size()); i++) {
        result.append(tokens[i]);
    }
    return result;
}

#include "../includes/Transition.h"


void Transition::setCondition(const ConditionPtrFunc condition) {
    condition_func = condition;
}

bool Transition::run() {
    return condition_func();
}


State *Transition::getStart() {
    return start;
}

State *Transition::getEnd() {
    return end;
}

#include "../includes/State.h"


void State::run() {
    qDebug() << "Running state: " << name;
    func_ptr();
}

void State::setFunc(const ActionPtrFunc func) {
    func_ptr = func;
}

QString State::getName() {
    return name;
}

void State::setFsm(Fsm *fsm) {
    this->fsm = fsm;
}
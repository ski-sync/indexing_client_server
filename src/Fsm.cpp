#include "../includes/Fsm.h"
#include <QDebug>

Fsm::Fsm(QStringList tokens)
{
    this->tokens = tokens;
}

void Fsm::run() {
    qDebug() << "Running FSM";
}

void Fsm::printState() {
    qDebug() << "Current state: " << this->state;
}
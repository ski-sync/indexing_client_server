#ifndef STATE_H
#define STATE_H
#include <QString>
#include <QDebug>
#include "typedef.h"

class Fsm;
class State {
    QString name;
    ActionPtrFunc func_ptr = nullptr;
    Fsm *fsm = nullptr;
public:
    State(QString name, ActionPtrFunc _func) : name(name), func_ptr(_func) {};

    void setFunc(ActionPtrFunc func);
    QString getName();

    void run();

    void setFsm(Fsm * fsm);
};

#endif //STATE_H
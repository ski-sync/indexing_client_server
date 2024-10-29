#ifndef ISTATE_H
#define ISTATE_H
#include <QString>

class IState {
    QString name;
public:
    virtual void execute() = 0;
    virtual ~IState() = default;
    QString getName() const {
        return name;
    }
};

#endif //ISTATE_H

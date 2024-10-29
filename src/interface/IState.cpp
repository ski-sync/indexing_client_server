#include "../includes/interface/IState.h"
#include <QDebug>

QString IState::get_state_to_string() {
    switch (state) {
        case State::UNKNOWN:
            return "UNKNOWN";
        case State::LAST_MODIFIED:
            return "LAST_MODIFIED";
        case State::CREATED:
            return "CREATED";
        case State::MAX_SIZE:
            return "MAX_SIZE";
        case State::MIN_SIZE:
            return "MIN_SIZE";
        case State::SIZE:
            return "SIZE";
        case State::EXT:
            return "EXT";
        case State::TYPE:
            return "TYPE";
        case State::ERROR:
            return "ERROR";
    }
}

State IState::get_string_to_state(QString state) {
    if (state == "UNKNOWN") {
        return State::UNKNOWN;
    } else if (state == "LAST_MODIFIED") {
        return State::LAST_MODIFIED;
    } else if (state == "CREATED") {
        return State::CREATED;
    } else if (state == "MAX_SIZE") {
        return State::MAX_SIZE;
    } else if (state == "MIN_SIZE") {
        return State::MIN_SIZE;
    } else if (state == "SIZE") {
        return State::SIZE;
    } else if (state == "EXT") {
        return State::EXT;
    } else if (state == "TYPE") {
        return State::TYPE;
    } else if (state == "ERROR") {
        return State::ERROR;
    }
}

State IState::get_state() {
    return state;
}
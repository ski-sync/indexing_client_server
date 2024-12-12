#include "../../includes/command/Search.h"

void Search::execute(const QList<Token> &tokens) {

    qDebug() << "Executing SEARCH command with tokens:" << tokens;

    fsm = new Fsm();
    fsm->setTokens(tokens);
    this->initStateMachine();
    fsm->run();

}

void Search::initStateMachine() const {
    auto init = new State("INIT", []() {
        qDebug() << "Running INIT state";
    });

    auto get_file_name = new State("GET_FILE_NAME", []() {
        qDebug() << "Running GET_FILE_NAME state";
    });

    auto get_option = new State("GET_OPTION", []() {
        qDebug() << "Running GET_OPTION state";
    });

    auto get_last_modified = new State("GET_LAST_MODIFIED", []() {
        qDebug() << "Running GET_LAST_MODIFIED state";
    });

    auto get_created = new State("GET_CREATED", []() {
        qDebug() << "Running GET_CREATED state";
    });

    auto get_max_size = new State("GET_MAX_SIZE", []() {
        qDebug() << "Running GET_MAX_SIZE state";
    });

    auto get_min_size = new State("GET_MIN_SIZE", []() {
        qDebug() << "Running GET_MIN_SIZE state";
    });

    auto get_size = new State("GET_SIZE", []() {
        qDebug() << "Running GET_SIZE state";
    });

    auto get_ext = new State("GET_EXT", []() {
        qDebug() << "Running GET_EXT state";
    });

    auto get_type = new State("GET_TYPE", []() {
        qDebug() << "Running GET_TYPE state";
    });

    auto get_token_size_from_size_state = new State("GET_TOKEN_SIZE", []() {
        qDebug() << "Running GET_TOKEN_SIZE state";
    });

    auto get_token_between_from_size_state = new State("GET_TOKEN_BETWEEN", []() {
        qDebug() << "Running GET_TOKEN_BET";
    });

    auto get_token_and_from_size_state = new State("GET_TOKEN_AND", []() {
        qDebug() << "Running GET_TOKEN_AND";
    });

    auto get_list_type = new State("GET_LIST_TYPE", []() {
        qDebug() << "Running GET_LIST_TYPE";
    });

    auto get_value_type = new State("GET_VALUE_TYPE", []() {
        qDebug() << "Running GET_VALUE_TYPE";
    });

    auto get_list_ext = new State("GET_LIST_EXT", []() {
        qDebug() << "Running GET_LIST_EXT";
    });

    auto get_value_ext = new State("GET_VALUE_EXT", []() {
        qDebug() << "Running GET_VALUE_EXT";
    });

    auto get_token_between = new State("GET_TOKEN_BETWEEN", []() {
        qDebug() << "Running GET_TOKEN_BET";
    });

    auto get_value = new State("GET_VALUE", []() {
        qDebug() << "Running GET_VALUE";
    });

    auto get_token_and = new State("GET_TOKEN_AND", []() {
        qDebug() << "Running GET_TOKEN_AND";
    });

    auto get_unit = new State("GET_UNIT", []() {
        qDebug() << "Running GET_UNIT";
    });

    auto finish = new State("FINISH", []() {
        qDebug() << "Running FINISH";
    });

    auto error = new State("ERROR", []() {
        qDebug() << "Running ERROR";
    });

    fsm->setInitialState(init);
    fsm->addState(get_file_name);
    fsm->addState(get_option);
    fsm->addState(get_last_modified);
    fsm->addState(get_created);
    fsm->addState(get_max_size);
    fsm->addState(get_min_size);
    fsm->addState(get_size);
    fsm->addState(get_ext);
    fsm->addState(get_type);
    fsm->addState(get_token_size_from_size_state);
    fsm->addState(get_token_between_from_size_state);
    fsm->addState(get_token_and_from_size_state);
    fsm->addState(get_list_type);
    fsm->addState(get_value_type);
    fsm->addState(get_list_ext);
    fsm->addState(get_value_ext);
    fsm->addState(get_token_between);
    fsm->addState(get_value);
    fsm->addState(get_token_and);
    fsm->addState(get_unit);
    fsm->addState(finish);
    fsm->addState(error);

    fsm->addFinalState(finish);
    fsm->addFinalState(error);

    fsm->addTransition(init, get_file_name, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "COMMAND" && fsm->currentToken().getValue() == "SEARCH";
        fsm->getNextToken();
        return condition;
    });
    fsm->addTransition(get_file_name, get_option, [&, this]() {
        if (fsm->canGetNextToken()) {
            fsm->getNextToken();
            return true;
        }
        return false;
    });
    fsm->addTransition(get_file_name, get_option, [&, this]() {
        return !fsm->canGetNextToken();
    });
    fsm->addTransition(get_option, get_last_modified, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "LAST_MODIFIED";
        return condition;
    });
    fsm->addTransition(get_option, get_created, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "CREATED";
        return condition;
    });
    fsm->addTransition(get_option, get_max_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "MAX_SIZE";
        return condition;
    });
    fsm->addTransition(get_option, get_min_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "MIN_SIZE";
        return condition;
    });
    fsm->addTransition(get_option, get_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "SIZE";
        return condition;
    });
    fsm->addTransition(get_option, get_ext, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "EXT";
        return condition;
    });
    fsm->addTransition(get_option, get_type, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "TYPE";
        return condition;
    });
    fsm->addTransition(get_last_modified, get_token_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "COMMAND" && fsm->currentToken().getValue() == "BETWEEN";
        return condition;
    });


}

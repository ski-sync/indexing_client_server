#include "../../includes/command/Search.h"
#include "../../includes/enum/OptionEnum.h"

void Search::execute(const QList<Token> &tokens) {

    qDebug() << "Executing SEARCH command with tokens:" << tokens;

    fsm = new Fsm();
    fsm->setTokens(tokens);
    this->initStateMachine();
    fsm->run();
}

void Search::initStateMachine() {

    auto unknown = new State("UNKNOWN", [&, this]() {
        qDebug() << "Running UNKNOWN state";
    });

    auto init = new State("INIT", [&, this]() {
        qDebug() << "Running INIT state";
        this->commandSql = "SELECT * FROM files WHERE ";
    });

    auto get_filename = new State("GET_FILENAME", [&, this]() {
        qDebug() << "Running GET_FILENAME state";

        // get the filename
        const QString filename = fsm->currentToken().getValue();
        qDebug() << "Filename: " << filename;

        // add to sql
        this->commandSql += "filename LIKE '%" + filename + "%'";
    });

    auto get_option = new State("GET_OPTION", [&, this]() {
        qDebug() << "Running GET_OPTION state";

        // add to sql
        this->commandSql += " AND ";
        qDebug() << "Command SQL: " << this->commandSql;
    });

    auto finish = new State("FINISH", [&, this]() {
        qDebug() << "Running FINISH state";
    });

    auto error = new State("ERROR", [&, this]() {
        qDebug() << "Running ERROR state";
    });

    auto option_ext = new State("OPTION_EXT", [&, this]() {
        qDebug() << "Running GET_OPTION_EXT state";

    });

    auto option_last_modify = new State("OPTION_LAST_MODIFY", [&, this]() {
        qDebug() << "Running GET_OPTION_LAST_MODIFY state";
    });

    auto option_created = new State("OPTION_CREATED", [&, this]() {
        qDebug() << "Running GET_OPTION_CREATED state";
    });

    auto option_size = new State("OPTION_SIZE", [&, this]() {
        qDebug() << "Running GET_OPTION_SIZE state";
    });

    auto option_size_max = new State("OPTION_SIZE_MAX", [&, this]() {
        qDebug() << "Running GET_OPTION_SIZE_MAX state";
    });

    auto option_size_min = new State("OPTION_SIZE_MIN", [&, this]() {
        qDebug() << "Running GET_OPTION_SIZE_MIN state";
    });

    auto option_type = new State("OPTION_TYPE", [&, this]() {
        qDebug() << "Running GET_OPTION_TYPE state";
    });

    auto get_size = new State("GET_SIZE", [&, this]() {
        qDebug() << "Running GET_SIZE state";
    });

    auto get_between = new State("GET_BETWEEN", [&, this]() {
        qDebug() << "Running GET_BETWEEN state";
    });

    auto get_and = new State("GET_AND", [&, this]() {
        qDebug() << "Running GET_AND state";
    });

    auto get_list = new State("GET_LIST", [&, this]() {
        qDebug() << "Running GET_LIST state";
    });

    auto get_value = new State("GET_VALUE", [&, this]() {
        qDebug() << "Running GET_VALUE state";
    });

    auto get_date = new State("GET_DATE", [&, this]() {
        qDebug() << "Running GET_DATE state";
    });

    auto get_unit = new State("GET_UNIT", [&, this]() {
        qDebug() << "Running GET_UNIT state";
    });

    auto get_since_last = new State("GET_SINCE_LAST", [&, this]() {
        qDebug() << "Running GET_SINCE_LAST state";
    });

    auto get_param_value = new State("GET_PARAM_VALUE", [&, this]() {
        qDebug() << "Running GET_PARAM_VALUE state";
    });


    // add state
    fsm->addState(unknown);
    fsm->addState(init);
    fsm->addState(get_filename);
    fsm->addState(get_option);
    fsm->addState(finish);
    fsm->addState(error);
    fsm->addState(option_ext);
    fsm->addState(option_last_modify);
    fsm->addState(option_created);
    fsm->addState(option_size);
    fsm->addState(option_size_max);
    fsm->addState(option_size_min);
    fsm->addState(option_type);
    fsm->addState(get_size);
    fsm->addState(get_between);
    fsm->addState(get_and);
    fsm->addState(get_list);
    fsm->addState(get_value);
    fsm->addState(get_date);
    fsm->addState(get_unit);
    fsm->addState(get_since_last);
    fsm->addState(get_param_value);

    // final state
    fsm->addFinalState(finish);
    fsm->addFinalState(error);

    // add initial state
    fsm->setInitialState(unknown);

    // add transitions

    fsm->addTransition(unknown, init, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "COMMAND" && fsm->currentToken().getValue() == "SEARCH";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// INIT
    ////////////////////////////////

    // INIT -> GET_FILENAME
    fsm->addTransition(init, get_filename, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "STRING";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// OPTION
    ////////////////////////////////

    // GET_FILENAME -> GET_OPTION
    fsm->addTransition(get_filename, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        // for this i don't need to get next token because i need to check the next token
        return condition;
    });

    ////////////////////////////////
    /// OPTION
    ////////////////////////////////

    // GET_OPTION -> OPTION_EXT
    fsm->addTransition(get_option, option_ext, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "EXT";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_LAST_MODIFY
    fsm->addTransition(get_option, option_last_modify, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "LAST_MODIFIED";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_CREATED
    fsm->addTransition(get_option, option_created, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "CREATED";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_SIZE
    fsm->addTransition(get_option, option_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_TYPE
    fsm->addTransition(get_option, option_type, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "TYPE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_SIZE_MAX
    fsm->addTransition(get_option, option_size_max, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "MAX_SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_OPTION -> OPTION_SIZE_MIN
    fsm->addTransition(get_option, option_size_min, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION" && fsm->currentToken().getValue() == "MIN_SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// OPTION_MIN_SIZE
    ////////////////////////////////

    // OPTION_SIZE_MAX -> GET_SIZE
    fsm->addTransition(option_size_max, get_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// OPTION_MAX_SIZE
    ////////////////////////////////

    // OPTION_SIZE_MIN -> GET_SIZE
    fsm->addTransition(option_size_min, get_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// OPTION_SIZE
    ////////////////////////////////

    // GET_SIZE -> GET_BETWEEN
    fsm->addTransition(option_size, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_BETWEEN -> GET_SIZE
    fsm->addTransition(get_between, get_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_SIZE -> GET_AND
    fsm->addTransition(get_size, get_and, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_AND -> GET_SIZE
    fsm->addTransition(get_and, get_size, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "SIZE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_SIZE -> GET_OPTION
    fsm->addTransition(get_size, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        return condition;
    });

    ////////////////////////////////
    /// OPTION_EXT
    ////////////////////////////////

    // OPTION_EXT -> GET_VALUE
    fsm->addTransition(option_ext, get_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "STRING";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // OPTION_EXT -> GET_LIST
    fsm->addTransition(option_ext, get_list, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LIST_VALUE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_LIST -> GET_OPTION
    fsm->addTransition(get_list, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        return condition;
    });



    ////////////////////////////////
    /// OPTION_TYPE
    ////////////////////////////////

    // OPTION_TYPE -> GET_VALUE
    fsm->addTransition(option_type, get_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "FORMAT_FILE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // OPTION_TYPE -> GET_LIST
    fsm->addTransition(option_type, get_list, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LIST_VALUE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    ////////////////////////////////
    /// OPTION_LAST_MODIFY
    ////////////////////////////////

    // OPTION_LAST_MODIFY -> GET_SINCE_LAST
    fsm->addTransition(option_last_modify, get_since_last, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "SINCE_LAST";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_SINCE_LAST -> GET_VALUE
    fsm->addTransition(get_since_last, get_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "STRING";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_VALUE -> GET_UNIT
    fsm->addTransition(get_value, get_unit, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "UNIT_TYPE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });


    // OPTION_LAST_MODIFY -> GET_DATE
    fsm->addTransition(option_last_modify, get_date, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "DATE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // OPTION_LAST_MODIFY -> GET_BETWEEN
    fsm->addTransition(option_last_modify, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_BETWEEN -> GET_BETWEEN
    fsm->addTransition(get_between, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_BETWEEN -> GET_DATE
    fsm->addTransition(get_between, get_date, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "DATE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_BETWEEN -> GET_PARAM_VALUE
    fsm->addTransition(get_between, get_param_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "PARAM_VALUE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_PARAM_VALUE -> GET_UNIT
    fsm->addTransition(get_param_value, get_unit, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "UNIT_TYPE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_UNIT -> GET_AND
    fsm->addTransition(get_unit, get_and, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_AND -> GET_PARAM_VALUE
    fsm->addTransition(get_and, get_param_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "PARAM_VALUE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_PARAM_VALUE -> GET_UNIT
    fsm->addTransition(get_param_value, get_unit, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "UNIT_TYPE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_UNIT -> GET_OPTION
    fsm->addTransition(get_unit, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        return condition;
    });

    // GET_UNIT -> GET_BETWEEN
    fsm->addTransition(get_unit, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_BETWEEN -> GET_VALUE
    fsm->addTransition(get_between, get_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "STRING";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_DATE -> GET_AND
    fsm->addTransition(get_date, get_and, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_VALUE -> GET_AND
    fsm->addTransition(get_value, get_and, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_AND -> GET_DATE
    fsm->addTransition(get_and, get_date, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "DATE";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_AND -> GET_VALUE
    fsm->addTransition(get_and, get_value, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "STRING";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // GET_DATE -> GET_OPTION
    fsm->addTransition(get_date, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        return condition;
    });

    // GET_VALUE -> GET_OPTION
    fsm->addTransition(get_value, get_option, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "OPTION";
        return condition;
    });

    // GET_AND -> GET_BETWEEN
    fsm->addTransition(get_and, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });


    ////////////////////////////////
    /// OPTION_LAST_MODIFY
    ////////////////////////////////


    // OPTION_CREATED -> GET_SINCE_LAST
    fsm->addTransition(option_created, get_since_last, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "SINCE_LAST";
        if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // existing but implemented in OPTION_LAST_MODIFY
    // // GET_SINCE_LAST -> GET_VALUE
    // fsm->addTransition(get_since_last, get_value, [&, this]() {
    //     const bool condition = fsm->currentToken().getType() == "STRING";
    //     fsm->getNextToken();
    //     return condition;
    // });
    //
    // // GET_VALUE -> GET_UNIT
    // fsm->addTransition(get_value, get_unit, [&, this]() {
    //     const bool condition = fsm->currentToken().getType() == "UNIT_TYPE";
    //     fsm->getNextToken();
    //     return condition;
    // });


    // OPTION_CREATED -> GET_DATE
    fsm->addTransition(option_created, get_date, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "DATE";
                if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // OPTION_CREATED -> GET_BETWEEN
    fsm->addTransition(option_created, get_between, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
                if (condition) {
            fsm->getNextToken();
        }
        return condition;
    });

    // existing but implemented in OPTION_LAST_MODIFY
    // // GET_BETWEEN -> GET_DATE
    //  fsm->addTransition(get_between, get_date, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "DATE";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_BETWEEN -> GET_VALUE
    //  fsm->addTransition(get_between, get_value, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "STRING";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_DATE -> GET_AND
    //  fsm->addTransition(get_date, get_and, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_VALUE -> GET_AND
    //  fsm->addTransition(get_value, get_and, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "AND";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_AND -> GET_DATE
    //  fsm->addTransition(get_and, get_date, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "DATE";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_AND -> GET_VALUE
    //  fsm->addTransition(get_and, get_value, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "STRING";
    //      fsm->getNextToken();
    //      return condition;
    //  });
    //
    //  // GET_DATE -> GET_OPTION
    //  fsm->addTransition(get_date, get_option, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "OPTION";
    //      return condition;
    //  });
    //
    //  // GET_VALUE -> GET_OPTION
    //  fsm->addTransition(get_value, get_option, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "OPTION";
    //      return condition;
    //  });
    //
    //  // GET_AND -> GET_BETWEEN
    //  fsm->addTransition(get_and, get_between, [&, this]() {
    //      const bool condition = fsm->currentToken().getType() == "LOGICAL_OPERATOR" && fsm->currentToken().getValue() == "BETWEEN";
    //      fsm->getNextToken();
    //      return condition;
    //  });

    ////////////////////////////////
    /// FINISH
    ////////////////////////////////

    // GET_OPTION -> FINISH
    fsm->addTransition(get_option, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

    // GET_FILENAME -> FINISH
    fsm->addTransition(get_filename, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

    // GET_VALUE -> FINISH
    fsm->addTransition(get_value, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

    // GET_DATE -> FINISH
    fsm->addTransition(get_date, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

    // GET_UNIT -> FINISH
    fsm->addTransition(get_unit, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

    // GET_PARAM_VALUE -> FINISH
    fsm->addTransition(get_param_value, finish, [&, this]() {
        const bool condition = fsm->currentToken().getType() == "EOF";
        return condition;
    });

}

#include <QCoreApplication>
#include "includes/IndexerThread.h"
#include "includes/Lexer.h"
#include "includes/Bdd.h"
#include "includes/Fsm.h"
#include "includes/State.h"
#include "includes/tokens.h"
// #include "includes/Debugging.h"


// const QList<State*> LIST_STATE = {
//     new State("INIT", [](){ qDebug() << "INIT"; }),
//     new State("GET_FILE_NAME", [](){ qDebug() << "GET_FILE_NAME"; }),
//     new State("GET_OPTION", [](){ qDebug() << "GET_OPTION"; }),
//     new State("FM", [](){ qDebug() << "FM"; }),
//     new State("CR", [](){ qDebug() << "CR"; }),
//     new State("MAX_SIZE", [](){ qDebug() << "MAX_SIZE"; }),
//     new State("MIN_SIZE", [](){ qDebug() << "MIN_SIZE"; }),
//     new State("SIZE_EXP", [](){ qDebug() << "SIZE_EXP"; }),
//     new State("EXT", [](){ qDebug() << "EXT"; }),
//     new State("TYPE", [](){ qDebug() << "TYPE"; }),
//     new State("DATE_SPEC", [](){ qDebug() << "DATE_SPEC"; }),
//     new State("SIZE_SPEC", [](){ qDebug() << "SIZE_SPEC"; }),
//     new State("SIZE_SPEC_EXP", [](){ qDebug() << "SIZE_SPEC_EXP"; }),
//     new State("EXT_SPEC", [](){ qDebug() << "EXT_SPEC"; }),
//     new State("TYPE_LIST_SPEC", [](){ qDebug() << "TYPE_LIST_SPEC"; }),
//     new State("FINISH", [](){ qDebug() << "FINISH"; }),
//     new State("ERROR", [](){ qDebug() << "ERROR"; })
// };



int main(int argc, char *argv[])
{
    QCoreApplication a (argc, argv);
    Lexer* lexer = new Lexer();
    // auto* thread(new IndexerThread());
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);


    //
    // qDebug() << "Hello, World!";
    // thread->start();
    // qDebug() << "after thread";
    Bdd *bdd = Bdd::getInstance();
    lexer->tokenize("SEARCH \"testme please\" LAST_MODIFIED BETWEEN 2 days and 3 days CREATED 31/12/2020 MAX_SIZE 10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT txt,doc,xlsx TYPE image OR text");
    lexer->printTokens();
    Tokens::getInstance()->setTokens(lexer->getTokens());
    auto [cmd, args] = Tokens::getInstance()->commandParse();

    Fsm* fsm = new Fsm();
    fsm->setTokens(args);

    State *Init = new State("INIT", [](){});
    //
    State *getFileName = new State("GET_FILE_NAME", [&, fsm, bdd]() {
        QString token = fsm->currentToken();
        bdd->searchFileName(token);
        qDebug() << "GET_FILE_NAME: " << token << " Request: " << bdd->getRequest();
        fsm->getNextToken();
    });
    //
    State *lm = new State("LM", [&, fsm]() {
        fsm->getNextToken();
        // todo
    });
    State *cr = new State("CR", [](){});
    State *maxS = new State("MAX_SIZE", [](){});
    State *minS = new State("MIN_SIZE", [](){});
    State *ext = new State("EXT", [](){});
    State *type = new State("TYPE", [](){});
    //

    //dateSpec
    State *dateSpecBetween = new State("DATE_SPEC_BETWEEN", []() {
        // todo
    });
    State *SINCE_LAST = new State("SINCE_LAST", []() {
        // todo
    });



    State *DateSpec = new State("DATE_SPEC", [](){});
    State *SizeSpec = new State("SIZE_SPEC", [](){});
    State *SizeSpecExp = new State("SIZE_SPEC_EXP", [](){});
    State *ExtSpec = new State("EXT_SPEC", [](){});
    State *sizeExp = new State("SIZE_EXP", [](){});
    State *TypeListSpec = new State("TYPE_LIST_SPEC", [](){});
    //
    State *Finish = new State("FINISH", [](){});
    State *Error = new State("ERROR", [](){});

    fsm->setInitialState(Init);
    fsm->addState(Init);
    fsm->addState(getFileName);
    fsm->addState(lm);
    fsm->addState(cr);
    fsm->addState(maxS);
    fsm->addState(minS);
    fsm->addState(sizeExp);
    fsm->addState(ext);
    fsm->addState(type);
    fsm->addState(DateSpec);
    fsm->addState(SizeSpec);
    fsm->addState(SizeSpecExp);
    fsm->addState(ExtSpec);
    fsm->addState(TypeListSpec);
    fsm->addState(Finish);
    fsm->addState(Error);


    fsm->addTransition(Init, getFileName, [&, fsm]() {
        return true;
    });
    fsm->addTransition(getFileName, lm, [&, fsm]() {
        QString token = fsm->currentToken();
        return  (token == "LAST_MODIFIED");

    });
    fsm->addTransition(lm, dateSpecBetween, [&, fsm]() {
        QString token = fsm->currentToken();
        return  (token == "BETWEEN");
    });
    fsm->addTransition(lm, SINCE_LAST, [&, fsm]() {
        QStringList token = fsm->getNTokens(2);
        return  (token[0] == "SINCE_LAST", token[1] == "LAST");
    });
    fsm->addTransition(getFileName, Error, []() {
        return true;
    });
    fsm->addTransition(Init, Error, [](){ return true; });


    fsm->addFinalState(Finish);
    fsm->addFinalState(Error);

    fsm->run();
    return a.exec();
}

#include <QCoreApplication>
#include "includes/IndexerThread.h"
#include "includes/Lexer.h"
#include "includes/Bdd.h"
// #include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    QCoreApplication a (argc, argv);
    Lexer* lexer = new Lexer();
    auto* thread(new IndexerThread());
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);


    qDebug() << "Hello, World!";
    thread->start();
    qDebug() << "after thread";
    lexer->tokenize("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:31/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx TYPE:image OR text");
    lexer->printTokens();


    return a.exec();
}

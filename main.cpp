#include <QCoreApplication>

#include "includes/Lexer.h"
// #include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);
    // qDebug() << "Hello, World!";
    Lexer* lexer = new Lexer();
    lexer->tokenize("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:31/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx TYPE:image OR text");
    lexer->printTokens();


    return 0;
}

#include <QCoreApplication>

#include "includes/lexer.h"
// #include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);
    // qDebug() << "Hello, World!";
    Lexer* lexer = new Lexer();
    lexer->tokenize("Hello World!");
    lexer->printTokens();


    return 0;
}

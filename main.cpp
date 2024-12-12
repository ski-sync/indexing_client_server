#include <QCoreApplication>
#include "includes/Lexer.h"
#include "includes/Bdd.h"
#include "includes/CommandFactory.h"
#include "includes/interface/ICommand.h"


int main(int argc, char *argv[])
{
    QCoreApplication a (argc, argv);
    Lexer* lexer = new Lexer();
    // auto* thread(new IndexerThread());
    // const Debugging *debugging = Debugging::getInstance();
    // qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);

    // thread->start();
    // Bdd *bdd = Bdd::getInstance();
    lexer->tokenize("SEARCH \"testme please\" LAST_MODIFIED BETWEEN 2 DAYS AND 3 DAYS CREATED 31/12/2020 MAX_SIZE 10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT txt,doc,xlsx TYPE image");
    lexer->printTokens();
    QList<Token> tokens = lexer->getTokens();

    if (tokens.isEmpty()) {
        qDebug() << "No tokens found!";
        return -1;
    }

    const QString commandType = tokens[0].getValue();
    qDebug() << "Command: " << commandType << " type " << tokens[0].getType();

    if (const std::unique_ptr<ICommand> command = CommandFactory::createCommand(commandType)) {
        command->execute(tokens);
    } else {
        qDebug() << "Command not found!";
    }

    return a.exec();
}

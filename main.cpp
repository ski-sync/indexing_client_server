#include <QCoreApplication>
#include "includes/Lexer.h"
#include "includes/Bdd.h"
#include "includes/CommandFactory.h"
#include "includes/interface/ICommand.h"
#include <iostream>
#include "includes/Debugging.h"


int main(int argc, char *argv[])
{
    QCoreApplication a (argc, argv);
    Lexer* lexer = new Lexer();
    // auto* thread(new IndexerThread());
    const Debugging *debugging = Debugging::getInstance();
    qInstallMessageHandler(Debugging::GetCustomHandlerQDebug);

    // thread->start();
    // Bdd *bdd = Bdd::getInstance();
    // lexer->tokenize("ADD WHITELIST add,test/add");
    while (true) {
        std::cout << "Entrez une commande : ";
        std::string input;
        std::getline(std::cin, input);
        lexer->tokenize(QString::fromStdString(input));
        // lexer->tokenize("ADD WHITELIST toto");
        // lexer->tokenize("PUSH WHITELIST C:/ d:/user/toto /lksdjflkj/sdlkfj  DONE");
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
    }

    return a.exec();
}

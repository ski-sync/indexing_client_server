#include "../../includes/command/IndexerCommand.h"

void IndexerCommand::execute(const QList<Token> &tokens) {
    qDebug() << "Executing Get command with tokens:" << tokens;
    if (tokens.size() < 2) {
        qDebug() << "Not enough arguments!";
        return;
    }
    auto* thread(new IndexerThread());
    thread->start();

}


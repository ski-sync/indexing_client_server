#include "../../includes/command/Exit.h"
#include <QCoreApplication>

void Exit::execute(const QList<Token> &tokens) {
    qDebug() << "Executing EXIT command with tokens:" << tokens;
    exit(EXIT_SUCCESS);
}

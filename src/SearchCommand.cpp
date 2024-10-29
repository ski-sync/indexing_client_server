#include "../includes/SearchCommand.h"
#include <QDebug>

SearchCommand::SearchCommand() {
    // Constructor
}

SearchCommand::~SearchCommand() {
    // Destructor
}

void SearchCommand::execute() {
    // Implementation of the execute method
    qDebug() << "SearchCommand::execute()" << args;
}
#include "../includes/AddCommand.h"

#include <QDebug>

AddCommand::AddCommand() {
    // Constructor
}

AddCommand::~AddCommand() {
    // Destructor
}

void AddCommand::execute() {
    // Implementation of the execute method
    qDebug() << "AddCommand::execute()";
}
#include "../includes/Debugging.h"
#include <QDebug>

Debugging *Debugging::instance = nullptr;
QFile *Debugging::logFile = nullptr;
QTextStream Debugging::out;
bool Debugging::isEnabled = false;

Debugging::Debugging(bool _log, const QString& _path) : log(_log) {
    logFile = new QFile(_path);
    if (logFile->open(QIODevice::WriteOnly | QIODevice::Append)) {
        isEnabled = true;
        out.setDevice(logFile);
    }
}

Debugging* Debugging::getInstance() {
    if (instance == nullptr) {
        instance = new Debugging(true, "log.txt");
    }
    return instance;
}

QString Debugging::GetIndexerStatus() {
    return "Indexer status";
}

Debugging::~Debugging() {
    if (isEnabled && logFile->isOpen()) {
        logFile->close();
    }
    delete logFile;
}

void Debugging::GetCustomHandlerQDebug(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    if (!isEnabled || !logFile->isOpen()) return;

    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

    switch (type) {
        case QtDebugMsg: out << "DEBUG:"; break;
        case QtInfoMsg: out << "INFO:"; break;
        case QtWarningMsg: out << "WARNING:"; break;
        case QtCriticalMsg: out << "CRITICAL:"; break;
        case QtFatalMsg: out << "FATAL:"; break;
        default: break;
    }

    out << " " << msg << " (" << context.file << ":" << context.line << ", " << context.function << ")\n";
    out.flush();
}

bool Debugging::IsLoggerActive() const {
    return this->log;
}

void Debugging::SetLoggerLevel(bool _log) {
    this->log = _log;
}
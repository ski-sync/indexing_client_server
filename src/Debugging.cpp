#include "../includes/Debugging.h"
// #include '../includes/Indexer.h'
#include <QDebug>

Debugging *Debugging::instance = nullptr;
QFile *Debugging::logFile = nullptr;
bool Debugging::isEnabled = false;



Debugging::Debugging(bool _log, const QString _path): log(_log) {
    Debugging::logFile = new QFile(_path);
    if (Debugging::logFile->open(QIODevice::WriteOnly | QIODevice::Append )) {
        isEnabled = true;
        qDebug() << "Log file opened successfully" << _path << isEnabled;
    }
}

Debugging *Debugging::getInstance() {
    if (instance == nullptr) {
        instance = new Debugging(true, "log.txt");
    }
    return instance;
}

QString Debugging::GetIndexerStatus() {
    return "Indexer status";
}

void Debugging::LogImpl(const QString& message) const {
    if (this->log) {
        qDebug() << message;
    }
}

Debugging::~Debugging() {
    if (isEnabled && logFile->isOpen()) {
        logFile->close();
    }
}

void Debugging::GetCustomHandlerQDebug(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    if (!isEnabled || !logFile->isOpen()) return;

    QTextStream out(logFile);
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

bool Debugging::IsLoggerActive() {
    return this->log;
}

void Debugging::SetLoggerLevel(bool _log) {
    this->log = _log;
}


#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <QString>
#include <QFile>
#include <QDateTime>

class Debugging {
private:
    bool log;
    static bool isEnabled;
    static QFile *logFile;
    static QTextStream out;
    static Debugging *instance;
    explicit Debugging(bool _log, const QString& _path = "log.txt");

public:
    static Debugging* getInstance();
    static void GetCustomHandlerQDebug(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    bool IsLoggerActive() const;
    void SetLoggerLevel(bool _log);
    static QString GetIndexerStatus();
    ~Debugging();

    // Delete copy constructor and assignment operator
    Debugging(const Debugging&) = delete;
    Debugging& operator=(const Debugging&) = delete;
};

#endif //DEBUGGING_H
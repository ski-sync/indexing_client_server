#ifndef DEBUGGING_H
#define DEBUGGING_H
#define Log(message) LogImpl(message, __FUNCTION__)

#include <QString>
#include <QFile>
#include <QDateTime>


class Debugging {
private:
    bool log;
    static bool isEnabled;
    static QFile *logFile;
    static Debugging *instance;
    explicit Debugging(bool _log, QString _path = "log.txt");

public:
    static Debugging *getInstance();
    void LogImpl(const QString& message) const;
    static void GetCustomHandlerQDebug(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    bool IsLoggerActive();
    void SetLoggerLevel(bool _log);
    static QString GetIndexerStatus();
    ~Debugging();
};

#endif //DEBUGGING_H

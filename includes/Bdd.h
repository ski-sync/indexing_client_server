
#ifndef BDD_H
#define BDD_H

#include <QDateTime>
#include <QMutex>
#include <QString>
#include <qsqldatabase.h>
#include "../includes/Line.h"

class Bdd
{
    static Bdd* bddIntance;
    QSqlDatabase m_database;
    QMutex m_mutex;
    QString request;

    int initDatabase();
    Bdd();
public:
    static Bdd* getInstance();
    bool insertdb(Line line);
    QVector<Line> select(QString req);
    bool update(Line line);
    void cleardb();
    void push(QString table,QVector<QString> list);
    void add(QString table, QString toadd);
    QString getWhitelist();
    void clearWhitelist();
    void clearBlacklist();
    void clearFilters();
    void clearSkippedFilters();
    QVector<QString> get(QString table);
    QString getRequest();


    void searchFileName(QString filename);
    void searchLastModified(QString date);
};


#endif //BDD_H

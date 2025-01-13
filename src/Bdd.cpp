#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include "../includes/Bdd.h"

Bdd *Bdd::bddIntance= nullptr;

Bdd::Bdd()
{

    this->initDatabase();
}

int Bdd::initDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataLocation);
    qDebug() << dir;
    if (!dir.exists()) {
        dir.mkdir(appDataLocation);
        qDebug() << "mkdir" << appDataLocation;
    }
    QString dbPath = appDataLocation + "/files.bin";
    db.setDatabaseName(dbPath);
    // todo:
    if (!db.open()) {
        qCritical() << "Unable to open db" << db.lastError() << dbPath;
        return -1;
    }
    //
    QStringList queryTblCreate = {
        "CREATE TABLE IF NOT EXISTS files ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "filePath TEXT,"
            "fileSize BIGINT,"
            "fileMTime DATETIME,"
            "fileLastModified DATETIME,"
            "extension TEXT"
        ");",
        "CREATE TABLE IF NOT EXISTS whitelist ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "filePath TEXT"
        ");",
        "CREATE TABLE IF NOT EXISTS blacklist ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "filePath TEXT"
        ");",
        "CREATE TABLE IF NOT EXISTS skipped_filters ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "filePath TEXT"
        ");",
        "CREATE TABLE IF NOT EXISTS filters ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "filePath TEXT"
        ");"
    };



    QSqlQuery query;
    for (const QString& req : queryTblCreate) {
        if (!query.exec(req)) {
                qDebug() << "Error executing statement:" << query.lastError().text();
            }
    }
//    query.exec(queryTblCerate);

    if (query.lastError().isValid()) {
        qWarning() << "Creation Table Problem" << query.lastError().text();
        return -1;
    }

    return 0;
}



Bdd *Bdd::getInstance()
{
    if (!bddIntance) {
        bddIntance = new Bdd();
    }
    return bddIntance;
}

bool Bdd::insertdb(Line line/*, QSqlDatabase db*/)
{
    QSqlQuery query;
    query.prepare("INSERT INTO files (filePath, fileSize, fileMTime, fileLastModified, extension)"
                  "VALUES(:filePath, :fileSize, :fileMTime, :fileLastModified, :extension)");
    query.bindValue(":filePath", line.path());
    query.bindValue(":fileSize", line.size());
    query.bindValue(":fileMTime", line.creationDate());
    query.bindValue(":fileLastModified", line.lastModified());
    query.bindValue(":extension", line.extension());
    return query.exec();
}

QVector<Line> Bdd::select(QString req)
{
    QSqlQuery query;
    query.prepare(req);
    const auto error = query.exec();
    if (!error) {
        qWarning() << "Error executing statement:" << query.lastError().text();
        return QVector<Line>();
    }
    QVector<Line> result;

    while(query.next()) {
        Line l = Line(query.value(4).toDateTime(), query.value(3).toDateTime(), query.value(2).toInt() , query.value(5).toString(), query.value(1).toString());
        result.append(l);
    }
    return result;
}

bool Bdd::update(Line line)
{
    QSqlQuery query;
    query.prepare("UPDATE files SET filePath = :filePath, fileSize = :fileSize, fileMTime = :fileMTime, fileLastModified = :fileLastModified, extension = :extension WHERE id = :id");
    query.bindValue(":filePath", line.path());
    query.bindValue(":fileSize", line.size());
    query.bindValue(":fileMTime", line.creationDate());
    query.bindValue(":fileLastModified", line.lastModified());
    query.bindValue(":extension", line.extension());
    return query.exec();
}

void Bdd::cleardb()
{
    QSqlQuery query;
    query.exec("DELETE FROM files");
}

void Bdd::push(QString table, QVector<QString> list)
{
    for (int i = 0; i < list.size(); ++i) {
        QSqlQuery query;
        query.prepare("INSERT INTO "+ table + " (filePath) VALUES(:filePath)");
        query.bindValue(":filePath", list.at(i));
        query.exec();
    }
}


void Bdd::add(QString table, QString toadd)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " + table + " (filePath) VALUES(:filePath)");
    query.bindValue(":filePath", toadd);
    query.exec();
}

void Bdd::clearWhitelist()
{
    QSqlQuery query;
    query.exec("DELETE FROM whitelist");
}

void Bdd::clearBlacklist()
{
    QSqlQuery query;
    query.exec("DELETE FROM blacklist");
}

void Bdd::clearFilters()
{
    QSqlQuery query;
    query.exec("DELETE FROM filters");
}

void Bdd::clearSkippedFilters()
{
    QSqlQuery query;
    query.exec("DELETE FROM skipped_filters");
}

QVector<QString> Bdd::get(QString table)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM "+ table);
    query.exec();
    QVector<QString> result;

    while(query.next()) {
        result.append(query.value(1).toString());
    }
    return result;
}

void Bdd::searchFileName(QString filename) {
    request = "SELECT * FROM files WHERE filePath LIKE '%" + filename + "%'";
}

QString Bdd::getRequest() {
    return request;
}



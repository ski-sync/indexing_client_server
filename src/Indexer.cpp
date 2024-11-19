#include "../includes/Indexer.h"
#include "../includes/Line.h"
#include "../includes/Bdd.h"
#include <QDirIterator>
#include <QElapsedTimer>


Indexer::Indexer(QObject *parent)
    : QObject{parent}
{

}

void Indexer::showIndex(QString path) {
    Bdd * db = Bdd::getInstance();
    QElapsedTimer timer;
    timer.start();
    QDirIterator it(path, QDirIterator::Subdirectories);
    int nbrFiles = 0;
    while (it.hasNext()) {
        QString dir = it.next();
        QFileInfo info(dir);
        Line l = Line(info.lastModified(), info.birthTime(), info.size(), info.suffix(), info.path() );
        db->getInstance()->insertdb(l);
        // qDebug() << dir;
        nbrFiles++;
    }
    qDebug() << "finish " << nbrFiles << " files";
    qint64 elapsed = timer.elapsed();
    qDebug() << "Time :" << elapsed/1000 << "s";
}

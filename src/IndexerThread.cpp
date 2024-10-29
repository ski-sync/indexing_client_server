#include "../includes/Indexer.h"
#include "../includes/IndexerThread.h"

#include <QStandardPaths>
#include <QStorageInfo>

IndexerThread::IndexerThread()
{
}

void IndexerThread::run() {
    qDebug() << "Thread Start";
    while(1) {
        // QStorageInfo storage = QStorageInfo::root();
        // QString name = storage.rootPath();
        // get default user directory
        QString name = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        Indexer index;
        index.showIndex(name);
        break;
    }
    qDebug() << "Thread Finish";
}

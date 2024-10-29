#include "../includes/Indexer.h"
#include "../includes/IndexerThread.h"

#include <QStorageInfo>

IndexerThread::IndexerThread()
{
}

void IndexerThread::run() {
    qDebug() << "Thread Start";
    while(1) {
        //        QStorageInfo storage = QStorageInfo::root();
        //        QString name = storage.rootPath();
        QString name = "/Users/enzoparriel";
        Indexer index;
        index.showIndex(name);
        break;
    }
    qDebug() << "Thread Finish";
}

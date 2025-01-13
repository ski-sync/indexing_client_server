#include "../includes/Indexer.h"
#include "../includes/IndexerThread.h"

#include <QStandardPaths>
#include <QStorageInfo>
#include <iostream>

IndexerThread::IndexerThread()
{
}

void IndexerThread::run() {
    std::cout << "Thread Start";
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
    std::cout << "Thread Finish";
    qDebug() << "Thread Finish";
}

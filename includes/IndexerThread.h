#ifndef INDEXERTHREAD_H
#define INDEXERTHREAD_H

#include <QThread>

class IndexerThread : public QThread
{
    Q_OBJECT
public:
    IndexerThread();
    virtual void run() override;
};


#endif //INDEXERTHREAD_H

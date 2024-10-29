
#ifndef INDEXER_H
#define INDEXER_H

#include <QObject>

class Indexer : public QObject
{
public:
    explicit Indexer(QObject *parent = nullptr);
    void showIndex(QString path);
    signals:

    };


#endif //INDEXER_H

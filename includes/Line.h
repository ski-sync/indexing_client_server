#ifndef LINE_H
#define LINE_H

#include <QDateTime>

class Line
{
    QDateTime m_lastModified;
    QDateTime m_creationDate;
    quint64 m_size;
    QString m_extension;
    QString m_path;
public:
    Line(QDateTime lastModified, QDateTime creationDate, quint64 size, QString extension, QString path);

    QDateTime lastModified() const;
    QDateTime creationDate() const;
    quint64 size() const;
    QString extension() const;
    QString path() const;
    void display();
};


#endif //LINE_H

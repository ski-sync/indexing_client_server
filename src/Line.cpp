#include <QDateTime>

#include "../includes/line.h"

Line::Line(QDateTime lastModified, QDateTime creationDate, quint64 size, QString extension, QString path)
    : m_lastModified(lastModified), m_creationDate(creationDate), m_size(size), m_extension(extension), m_path(path)
{

}

QDateTime Line::lastModified() const
{
    return m_lastModified;
}

QDateTime Line::creationDate() const
{
    return m_creationDate;
}

quint64 Line::size() const
{
    return m_size;
}

QString Line::extension() const
{
    return m_extension;
}

QString Line::path() const
{
    return m_path;
}

void Line::display()
{
    qDebug() << this->path() << this->extension();
}

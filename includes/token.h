#ifndef TOKEN_H
#define TOKEN_H
#include <QString>
#include <qlist.h>
#include <QRegularExpression>


class Token {
    QString value;
    QString type;
public:
    Token() : type(""), value("") {} // Default constructor
    Token( QString _type, QString _value) : value(_value), type(_type) {}
    QString getValue() { return value; }
    QString getType() { return type; }
    friend QDebug operator<<(QDebug debug, const Token &token);
};


#endif //TOKEN_H

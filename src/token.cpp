#include "../includes/token.h"

QDebug operator<<(QDebug debug, const Token &token) {
    debug.nospace() << "Token(type: " << token.type << ", value: " << token.value << ")";
    return debug.space();
}

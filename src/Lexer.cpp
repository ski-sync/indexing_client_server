#include "../includes/Lexer.h"
#include <QDebug>



struct TokenReplacement {
    QString from;
    QString to;
};

const QVector<TokenReplacement> replacements = {
    {"SINCE LAST", "SINCE_LAST"},
    {" OR ", ","},
    {":", " "},
    {"DAYS", "DAY"},

};

QString Lexer::normalize(const QString &input) {
    QString result = input;
    for (const auto &replacement : replacements) {
        result.replace(replacement.from, replacement.to);
    }
    return result;
}


// Tokenize and classify the input
void Lexer::tokenize(const QString &input) {
    QString normalized = normalize(input);
    QStringList quoteSplit = normalized.split("\"");
    tokens.clear();

    for (int i = 0; i < quoteSplit.size(); i++) {
        QString segment = quoteSplit[i].trimmed();

        if (segment.isEmpty()) continue;

        if (i % 2 == 0) {
            QStringList spaceSplit = segment.split(" ", Qt::SkipEmptyParts);
            for (const QString &part : spaceSplit) {
                classifyAndAddToken(part);
            }
        } else {
            classifyAndAddToken("\"" + segment + "\"");
        }
    }

    classifyAndAddToken("EOF");

    index = 0;
}


void Lexer::classifyAndAddToken(const QString &tokenValue) {
    if (tokenValue.startsWith("\"") && tokenValue.endsWith("\"")) {
        tokens.append(Token("STRING", tokenValue));
    } else if (isLogicalOperator(tokenValue)) {
        tokens.append(Token("LOGICAL_OPERATOR", tokenValue));
    } else if (isKeyword(tokenValue)) {
        tokens.append(Token("OPTION", tokenValue));
    } else if (isCommand(tokenValue)) {
        tokens.append(Token("COMMAND", tokenValue));
    } else if (isFlag(tokenValue)) {
        tokens.append(Token("FLAG", tokenValue));
    } else if (isUnitType(tokenValue)) {
        tokens.append(Token("UNIT_TYPE", tokenValue));
    } else if (isIndexerSubcommand(tokenValue)) {
        tokens.append(Token("INDEXER_SUBCOMMAND", tokenValue));
    } else if (isSize(tokenValue)) {
        tokens.append(Token("SIZE", formatSize(tokenValue)));
    } else if (isListValue(tokenValue)) {
        tokens.append(Token("LIST_VALUE", tokenValue));
    } else if (isDate(tokenValue)) {
        tokens.append(Token("DATE", tokenValue));
    } else if (isFormatFile(tokenValue)) {
        tokens.append(Token("LIST_VALUE", formatFileToExtension(tokenValue)));
    } else if (tokenValue == "EOF") {
        tokens.append(Token("EOF", tokenValue));
    } else {
        tokens.append(Token("PARAM_VALUE", tokenValue));
    }
}

bool Lexer::isLogicalOperator(const QString &tokenValue) {
    return tokenValue == "AND" || tokenValue == "BETWEEN" || tokenValue == "SINCE_LAST";
}

bool Lexer::isKeyword(const QString &tokenValue) {
    static QStringList keywords = {"LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    return keywords.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isCommand(const QString &tokenValue) {
    static QStringList commands = {"SEARCH", "CLEAR", "GET", "ADD", "PUSH", "INDEXER", "EXIT"};
    return commands.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isUnitType(const QString &tokenValue) {
    static QStringList unitTypes = {"DAY", "HOURS", "MINUTES", "MONTHS", "YEARS"};
    return unitTypes.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isFlag(const QString &tokenValue) {
    static QStringList flags = {"WHITELIST", "BLACKLIST", "FILTERS", "SKIPPED_FILTERS"};
    return flags.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isIndexerSubcommand(const QString &tokenValue) {
    static QStringList subcommands = {"STATUS", "START", "STOP", "PAUSE", "RESUME"};
    return subcommands.contains(tokenValue, Qt::CaseInsensitive);
}

bool Lexer::isSize(const QString &tokenValue) {
    return tokenValue.contains("M") || tokenValue.contains("G") || tokenValue.contains("K");
}

bool Lexer::isListValue(const QString &tokenValue) {
    return tokenValue.contains(",");
}

bool Lexer::isDate(const QString &tokenValue) {
    const QRegularExpression dateRegex(
        // Full date dd/mm/yyyy
        "^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([12][0-9]{3})$|"
        // Month and year mm/yyyy
        "^(0[1-9]|1[0-2])/([12][0-9]{3})$|"
        // Full year yyyy
        "^[12][0-9]{3}$|"
        // Short year yy
        "^[0-9]{2}$"
    );

    return dateRegex.match(tokenValue).hasMatch();
}

// make a method for all groups of form files like images, videos, documents, etc
bool Lexer::isFormatFile(const QString &tokenValue) {
    static QStringList formatFiles = {"image", "video", "audio", "document", "archive", "executable", "code"};
    return formatFiles.contains(tokenValue, Qt::CaseInsensitive);
}

// this method convert type Of format file into list of extension
QString Lexer::formatFileToExtension(const QString &formatFile) {
    static QMap<QString, QStringList> formatFiles = {
        {"image", {"jpg", "jpeg", "png", "gif", "bmp", "svg", "webp", "ico", "tiff", "psd", "ai", "eps", "indd", "raw"}},
        {"video", {"mp4", "avi", "mkv", "mov", "wmv", "flv", "webm", "vob", "3gp", "3g2", "m4v", "mpg", "mpeg", "m2v", "m4v", "ts", "m2ts", "mts", "asf", "rm", "rmvb", "ogv", "ogg", "drc", "dat", "swf", "nut", "h264", "h265", "hevc", "av1", "vp8", "vp9", "avi", "flv", "f4v", "f4p", "f4a", "f4b"}},
        {"audio", {"mp3", "wav", "flac", "aac", "ogg", "wma", "m4a", "m4r", "m4p", "m4b", "m4v", "3gp", "3ga", "3g2", "amr", "awb", "aiff", "aif", "aifc", "caf", "dts", "alac", "ape", "ac3", "eac3", "ec3", "dolby", "dolby digital", "dolby digital plus", "dolby atmos", "dolby truehd", "dts"}},
        {"document", {"pdf", "doc", "docx", "xls", "xlsx", "ppt", "pptx", "odt", "ods", "odp", "txt", "rtf", "csv", "xml", "html"}},
        {"archive", {"zip", "rar", "7z", "tar", "gz", "bz2", "xz", "z", "arj", "lzh", "ace", "uue", "bz", "cab", "jar", "iso", "dmg", "vhd", "vmdk", "vdi", "hfs", "wim", "swm", "esd", "qcow2", "vdi", "vmdk", "vhdx", "vhd", "vfd", "vfdx", "vfd", "vff", "vffx"}},
        {"executable", {"exe", "msi", "apk", "app", "bat", "bin", "cgi", "com", "gadget", "jar", "wsf", "app", "appx", "ipa", "isp", "jar", "js", "jse", "msc", "msu", "msh", "msh1", "msh2", "mshxml", "msh1xml", "msh2xml", "ps1", "ps1xml"}},
        {"code", {"c", "cpp", "h", "hpp", "java", "py", "js", "ts", "html", "css", "scss", "sass", "less", "php", "go", "rb", "swift"}},
    };

    return formatFiles[formatFile].join(",");
}

QVector<Token> Lexer::getTokens() {
    return tokens;
}

void Lexer::printTokens() {
    for (Token &token : tokens) {
        qDebug() << token.getType() << " " << token.getValue();
    }
}

QString Lexer::formatSize(const QString &tokenValue) {
    const QString unit = tokenValue.right(1);
    int multiplier = unit == "K" ? 1000 : unit == "M" ? 1000000 : 1000000000;
    const QString size = QString::number(tokenValue.left(tokenValue.size() - 1).toInt() * multiplier);

    return size;
}

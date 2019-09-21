#include "Util.h"
#include <sstream>
#include <cctype>

std::string toLower(std::string str)
{
    for (char& ch : str)
        ch = tolower(ch);
    return str;
}

std::string identifierFromString(const QString& str)
{
    if (str.length() == 0)
        return std::string("_", 1);

    std::stringstream ss;

    if (str[0] >= '0' && str[0] <= '9')
        ss << '_';

    for (const QChar& ch : str) {
        if (ch >= 'a' && ch <= 'z')
            ss << ch.toLatin1();
        else if (ch >= 'A' && ch <= 'Z')
            ss << ch.toLatin1();
        else if (ch >= '0' && ch <= '9')
            ss << ch.toLatin1();
        else
            ss << '_';
    }

    return ss.str();
}

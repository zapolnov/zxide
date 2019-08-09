#include "Util.h"
#include <cctype>

std::string toLower(std::string str)
{
    for (char& ch : str)
        ch = tolower(ch);
    return str;
}

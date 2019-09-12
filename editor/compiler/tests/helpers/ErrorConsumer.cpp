#include "ErrorConsumer.h"

ErrorConsumer::ErrorConsumer()
    : mLine(0)
    , mCount(0)
{
}

ErrorConsumer::~ErrorConsumer()
{
}

void ErrorConsumer::error(const QString& file, int line, const QString& message)
{
    mFile = file;
    mLine = line;
    mMessage = message;
    mCount++;
}

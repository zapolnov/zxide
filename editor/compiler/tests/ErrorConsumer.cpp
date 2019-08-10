#include "ErrorConsumer.h"

ErrorConsumer::ErrorConsumer()
    : mFile(nullptr)
    , mLine(0)
    , mCount(0)
{
}

ErrorConsumer::~ErrorConsumer()
{
}

void ErrorConsumer::error(File* file, int line, const QString& message)
{
    mFile = file;
    mLine = line;
    mMessage = message;
    mCount++;
}

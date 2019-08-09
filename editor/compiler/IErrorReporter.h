#ifndef COMPILER_IERRORREPORTER_H
#define COMPILER_IERRORREPORTER_H

#include <QString>

class File;

class IErrorReporter
{
public:
    virtual ~IErrorReporter() = default;
    virtual void error(File* file, int line, const QString& message) = 0;
};

#endif

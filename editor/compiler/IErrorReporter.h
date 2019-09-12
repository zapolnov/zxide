#ifndef COMPILER_IERRORREPORTER_H
#define COMPILER_IERRORREPORTER_H

#include <QString>

class IErrorReporter
{
public:
    virtual ~IErrorReporter() = default;
    virtual void error(const QString& file, int line, const QString& message) = 0;
};

#endif

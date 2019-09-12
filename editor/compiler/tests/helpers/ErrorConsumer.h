#ifndef COMPILER_TESTS_HELPERS_ERRORCONSUMER_H
#define COMPILER_TESTS_HELPERS_ERRORCONSUMER_H

#include "IErrorReporter.h"

class ErrorConsumer : public IErrorReporter
{
public:
    ErrorConsumer();
    ~ErrorConsumer();

    void error(const QString& file, int line, const QString& message) override;

    bool wasError() const { return mCount > 0; }
    int errorCount() const { return mCount; }

    const QString& lastErrorFile() const { return mFile; }
    int lastErrorLine() const { return mLine; }
    std::string lastErrorMessage() const { return mMessage.toStdString(); }

private:
    QString mFile;
    int mLine;
    QString mMessage;
    int mCount;
};

#endif

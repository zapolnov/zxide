#ifndef COMPILER_TESTS_ERRORCONSUMER_H
#define COMPILER_TESTS_ERRORCONSUMER_H

#include "IErrorReporter.h"

class ErrorConsumer : public IErrorReporter
{
public:
    ErrorConsumer();
    ~ErrorConsumer();

    void error(File* file, int line, const QString& message) override;

    bool wasError() const { return mCount > 0; }
    int errorCount() const { return mCount; }

    File* lastErrorFile() const { return mFile; }
    int lastErrorLine() const { return mLine; }
    std::string lastErrorMessage() const { return mMessage.toStdString(); }

private:
    File* mFile;
    int mLine;
    QString mMessage;
    int mCount;
};

#endif

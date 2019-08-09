#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include "IErrorReporter.h"
#include <vector>
#include <memory>
#include <QObject>
#include <QMutex>

class Program;

class Compiler : public QObject, public IErrorReporter
{
    Q_OBJECT

public:
    explicit Compiler(QObject* parent = nullptr);
    ~Compiler();

    bool wasError() const { QMutexLocker lock(&mMutex); return mWasError; }
    QString errorMessage() const { QMutexLocker lock(&mMutex); return mErrorMessage; }
    File* errorFile() const { QMutexLocker lock(&mMutex); return mErrorFile; }
    int errorLine() const { QMutexLocker lock(&mMutex); return mErrorLine; }

    QString statusText() const { QMutexLocker lock(&mMutex); return mStatusText; }

    void addSourceFile(File* file);

    void compile();

signals:
    void compilationEnded();

private:
    struct SourceFile
    {
        File* file;
        QString path;
    };

    mutable QMutex mMutex;
    std::unique_ptr<Program> mProgram;
    QString mStatusText;
    QString mErrorMessage;
    std::vector<SourceFile> mSources;
    File* mErrorFile;
    int mErrorLine;
    bool mWasError;

    void error(File* file, int line, const QString& message) override;
    void setStatusText(const QString& text);

    Q_DISABLE_COPY(Compiler)
};

#endif

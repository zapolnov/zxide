#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include "IErrorReporter.h"
#include <vector>
#include <memory>
#include <QObject>
#include <QMutex>

class Program;
class ProgramBinary;
struct lua_State;

class Compiler : public QObject, public IErrorReporter
{
    Q_OBJECT

public:
    explicit Compiler(QObject* parent = nullptr);
    ~Compiler() override;

    bool wasError() const { QMutexLocker lock(&mMutex); return mWasError; }
    QString errorMessage() const { QMutexLocker lock(&mMutex); return mErrorMessage; }
    File* errorFile() const { QMutexLocker lock(&mMutex); return mErrorFile; }
    int errorLine() const { QMutexLocker lock(&mMutex); return mErrorLine; }

    std::unique_ptr<Program> takeProgram();
    std::unique_ptr<ProgramBinary> takeProgramBinary();

    QString statusText() const { QMutexLocker lock(&mMutex); return mStatusText; }

    void addSourceFile(File* file, const QString& path);
    void setOutputFile(const QString& file) { mOutputFile = file; }

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
    std::unique_ptr<ProgramBinary> mProgramBinary;
    lua_State* mLua;
    QString mStatusText;
    QString mErrorMessage;
    QString mOutputFile;
    std::vector<SourceFile> mSources;
    std::vector<SourceFile> mBuildScripts;
    File* mErrorFile;
    int mErrorLine;
    bool mWasError;

    void error(File* file, int line, const QString& message) override;
    void setStatusText(const QString& text);

    bool runBuildScripts();
    void destroyLuaVM();

    Q_DISABLE_COPY(Compiler)
};

#endif

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include "IErrorReporter.h"
#include "CompileSettings.h"
#include <vector>
#include <memory>
#include <QObject>
#include <QDir>
#include <QMutex>

class Program;
class ProgramBinary;

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
    void setSettings(CompileSettings settings);
    void setOutputTapeFile(const QString& file) { mOutputTapeFile = file; }
    void setOutputWavFile(const QString& file) { mOutputWavFile = file; }
    void setGeneratedFilesDirectory(const QDir& dir) { mGeneratedFilesDirectory = dir; }
    void setProjectDirectory(const QDir& dir) { mProjectDirectory = dir; }

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
    QString mStatusText;
    QString mErrorMessage;
    QString mOutputTapeFile;
    QString mOutputWavFile;
    QDir mGeneratedFilesDirectory;
    QDir mProjectDirectory;
    QByteArray mCompiledBasicCode;
    std::vector<SourceFile> mSources;
    std::vector<SourceFile> mBasicSources;
    std::vector<SourceFile> mBuildScripts;
    CompileSettings mCompileSettings;
    File* mErrorFile;
    int mErrorLine;
    bool mWasError;

    void error(File* file, int line, const QString& message) override;
    void setStatusText(const QString& text);

    bool runBuildScripts();

    bool compileBasicCode();
    static void bas2tapError(int line, int stmt, const char* fmt, ...);
    static int bas2tapFGets(char** basicIndex, int* basicLineNo);
    static void bas2tapOutput(const void* dst, size_t length);

    Q_DISABLE_COPY(Compiler)
};

#endif

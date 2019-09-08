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
    struct SourceFile
    {
        File* file; // should not be accessed by the compiler code as it is run from another thread
        QString name;
        QString path;
    };

    explicit Compiler(QObject* parent = nullptr);
    ~Compiler() override;

    bool wasError() const { QMutexLocker lock(&mMutex); return mWasError; }
    QString errorMessage() const { QMutexLocker lock(&mMutex); return mErrorMessage; }
    File* errorFile() const { QMutexLocker lock(&mMutex); return mErrorFile; }
    int errorLine() const { QMutexLocker lock(&mMutex); return mErrorLine; }

    std::unique_ptr<Program> takeProgram();
    std::unique_ptr<ProgramBinary> takeProgramBinary();

    QString statusText() const { QMutexLocker lock(&mMutex); return mStatusText; }

    void addSourceFile(File* file, const QString& fullName, const QString& path);
    void setSettings(CompileSettings settings);
    void setOutputTapeFile(const QString& file) { mOutputTapeFile = file; }
    void setOutputWavFile(const QString& file) { mOutputWavFile = file; }
    void setGeneratedFilesDirectory(const QDir& dir) { mGeneratedFilesDirectory = dir; }
    void setProjectDirectory(const QDir& dir) { mProjectDirectory = dir; }

    const std::vector<SourceFile>& basicSources() const { return mBasicSources; }
    const std::vector<SourceFile>& assemblerSources() const { return mAssemblerSources; }
    const std::vector<SourceFile>& maps() const { return mMaps; }
    const std::vector<SourceFile>& buildScripts() const { return mBuildScripts; }

    void compile();

signals:
    void diagnosticMessage(const QString& message);
    void compilationEnded();

private:
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
    std::vector<SourceFile> mBasicSources;
    std::vector<SourceFile> mAssemblerSources;
    std::vector<SourceFile> mMaps;
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

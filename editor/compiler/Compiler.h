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

struct SourceFile
{
    QString name;
    QString path;
};

class Compiler : public QObject, public IErrorReporter
{
    Q_OBJECT

public:
    explicit Compiler(QObject* parent = nullptr);
    ~Compiler() override;

    bool wasError() const { QMutexLocker lock(&mMutex); return mWasError; }
    QString errorMessage() const { QMutexLocker lock(&mMutex); return mErrorMessage; }
    QString errorFile() const { QMutexLocker lock(&mMutex); return mErrorFile; }
    int errorLine() const { QMutexLocker lock(&mMutex); return mErrorLine; }

    std::unique_ptr<Program> takeProgram();
    std::unique_ptr<ProgramBinary> takeProgramBinary();

    QString statusText() const { QMutexLocker lock(&mMutex); return mStatusText; }

    void addSourceFile(const QString& fullName, const QString& path);
    void setSettings(CompileSettings settings);
    void setOutputTapeFile(const QString& file) { mOutputTapeFile = file; }
    void setOutputWavFile(const QString& file) { mOutputWavFile = file; }
    void setGeneratedFilesDirectory(const QDir& dir) { mGeneratedFilesDirectory = dir; }
    void setProjectDirectory(const QDir& dir) { mProjectDirectory = dir; }

    const std::vector<std::unique_ptr<SourceFile>>& basicSources() const { return mBasicSources; }
    const std::vector<std::unique_ptr<SourceFile>>& assemblerSources() const { return mAssemblerSources; }
    const std::vector<std::unique_ptr<SourceFile>>& maps() const { return mMaps; }
    const std::vector<std::unique_ptr<SourceFile>>& buildScripts() const { return mBuildScripts; }

    void compile();

signals:
    void diagnosticMessage(const QString& message);
    void compilationEnded();

private:
    mutable QMutex mMutex;
    std::unique_ptr<Program> mProgram;
    std::unique_ptr<ProgramBinary> mProgramBinary;
    QString mStatusText;
    QString mErrorFile;
    QString mErrorMessage;
    QString mOutputTapeFile;
    QString mOutputWavFile;
    QDir mGeneratedFilesDirectory;
    QDir mProjectDirectory;
    QByteArray mCompiledBasicCode;
    std::vector<std::unique_ptr<SourceFile>> mBasicSources;
    std::vector<std::unique_ptr<SourceFile>> mAssemblerSources;
    std::vector<std::unique_ptr<SourceFile>> mGraphics;
    std::vector<std::unique_ptr<SourceFile>> mMaps;
    std::vector<std::unique_ptr<SourceFile>> mBuildScripts;
    CompileSettings mCompileSettings;
    int mErrorLine;
    bool mWasError;

    void error(const QString& file, int line, const QString& message) override;
    void setStatusText(const QString& text);

    bool runBuildScripts();

    void includeBinaryFile(const SourceFile* source, const QFileInfo& inputFile, const QByteArray& data);

    bool compileBasicCode();
    static void bas2tapError(int line, int stmt, const char* fmt, ...);
    static int bas2tapFGets(char** basicIndex, int* basicLineNo);
    static void bas2tapOutput(const void* dst, size_t length);

    Q_DISABLE_COPY(Compiler)
};

#endif

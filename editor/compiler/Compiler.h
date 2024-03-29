#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include "IErrorReporter.h"
#include <vector>
#include <memory>
#include <QObject>
#include <QDir>
#include <QMutex>

class Program;
class ProgramBinary;
class CodeEmitter;
class AssemblerRepeatContext;
class AssemblerIfContext;
class ProjectSettings;

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

    const QDir& projectDirectory() const { return mProjectDirectory; }

    void addSourceFile(const QString& fullName, const QString& path);
    void setOutputTapeFile(const QString& file) { mOutputTapeFile = file; }
    void setOutputSclFile(const QString& file) { mOutputSclFile = file; }
    void setOutputTrdFile(const QString& file) { mOutputTrdFile = file; }
    void setOutputWavFile(const QString& file) { mOutputWavFile = file; }
    void setGeneratedFilesDirectory(const QDir& dir) { mGeneratedFilesDirectory = dir; }
    void setProjectFile(const QString& file) { mProjectFile = file; }
    void setProjectDirectory(const QDir& dir) { mProjectDirectory = dir; }
    void setWriteTapeFile(bool flag) { mWriteTapFile = flag; }
    void setWriteSclFile(bool flag) { mWriteSclFile = flag; }
    void setWriteTrdFile(bool flag) { mWriteTrdFile = flag; }
    void setWriteWavFile(bool flag) { mWriteWavFile = flag; }

    const std::vector<std::unique_ptr<SourceFile>>& basicSources() const { return mBasicSources; }
    const std::vector<std::unique_ptr<SourceFile>>& assemblerSources() const { return mAssemblerSources; }
    const std::vector<std::unique_ptr<SourceFile>>& maps() const { return mMaps; }
    const std::vector<std::unique_ptr<SourceFile>>& buildScripts() const { return mBuildScripts; }

    void compile();

signals:
    void statusText(const QString& message);
    void errorMessage(const QString& message);
    void diagnosticMessage(const QString& message);
    void compilationEnded();

private:
    mutable QMutex mMutex;
    std::unique_ptr<Program> mProgram;
    std::unique_ptr<ProgramBinary> mProgramBinary;
    std::unique_ptr<ProjectSettings> mProjectSettings;
    QString mStatusText;
    QString mErrorFile;
    QString mErrorMessage;
    QString mOutputTapeFile;
    QString mOutputSclFile;
    QString mOutputTrdFile;
    QString mOutputWavFile;
    QString mProjectFile;
    QDir mGeneratedFilesDirectory;
    QDir mProjectDirectory;
    QByteArray mCompiledBasicCode;
    std::vector<std::shared_ptr<CodeEmitter>> mCodeEmitters;
    std::vector<std::unique_ptr<SourceFile>> mBasicSources;
    std::vector<std::unique_ptr<SourceFile>> mAssemblerSources;
    std::vector<std::unique_ptr<SourceFile>> mAssemblerBlobs;
    std::vector<std::unique_ptr<SourceFile>> mCSources;
    std::vector<std::unique_ptr<SourceFile>> mGraphics;
    std::vector<std::unique_ptr<SourceFile>> mMaps;
    std::vector<std::unique_ptr<SourceFile>> mBuildScripts;
    int mErrorLine;
    bool mWriteTapFile;
    bool mWriteTrdFile;
    bool mWriteSclFile;
    bool mWriteWavFile;
    bool mWasError;

    void error(const QString& file, int line, const QString& message) override;
    void setStatusText(const QString& text);

    bool runBuildScripts();

    void includeBinaryFile(const SourceFile* source, const QFileInfo& inputFile, const QByteArray& data);

    bool compileCCode();

    bool compileBasicCode();
    static void bas2tapError(int line, int stmt, const char* fmt, ...);
    static int bas2tapFGets(char** basicIndex, int* basicLineNo);
    static void bas2tapOutput(const void* dst, size_t length);

    template <typename T, typename... ARGS> std::shared_ptr<T> allocCodeEmitter(ARGS&&... args)
    {
        auto ptr = std::make_shared<T>(std::forward<ARGS>(args)...);
        mCodeEmitters.emplace_back(ptr);
        return ptr;
    }

    Q_DISABLE_COPY(Compiler)
    friend class AssemblerRepeatContext;
    friend class AssemblerIfContext;
};

#endif

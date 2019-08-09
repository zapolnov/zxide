#include "Compiler.h"
#include "FileManager.h"
#include <exception>
#include <QThread> // FIXME

Compiler::Compiler(QObject* parent)
    : QObject(parent)
    , mErrorFile(nullptr)
    , mErrorLine(0)
    , mWasError(false)
{
}

Compiler::~Compiler()
{
}

void Compiler::addSourceFile(File* file)
{
    mSources.emplace_back(SourceFile{ file, file->fileInfo().absoluteFilePath() });
}

void Compiler::compile()
{
    try {
        // FIXME
        setStatusText("Warming up...");
        QThread::sleep(2);
        error(nullptr, 0, "Compiler is not implemented yet");
    } catch (const std::exception& e) {
        error(nullptr, 0, tr("Exception: %1").arg(e.what()));
    } catch (...) {
        error(nullptr, 0, "Unhandled Exception");
    }

    setStatusText(tr("Compilation succeeded!"));
    emit compilationEnded();
}

void Compiler::error(File* file, int line, const QString& message)
{
    QMutexLocker lock(&mMutex);
    if (!mWasError) {
        mWasError = true;
        mErrorMessage = message;
        mErrorFile = file;
        mErrorLine = line;
        mStatusText = tr("Compilation failed!");
    }
}

void Compiler::setStatusText(const QString& text)
{
    QMutexLocker lock(&mMutex);
    if (!mWasError)
        mStatusText = text;
}

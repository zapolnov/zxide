#include "Compiler.h"
#include "Program.h"
#include "Assembler.h"
#include "FileManager.h"
#include <exception>

#ifndef emit
#define emit
#endif

Compiler::Compiler(QObject* parent)
    : QObject(parent)
    , mProgram(new Program)
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
        for (const auto& source : mSources) {
            QFileInfo info(source.path);
            setStatusText(tr("Compiling %1").arg(info.fileName()));
            QString extension = info.suffix();

            QFile file(info.absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                error(source.file, 0, file.errorString());
                break;
            }

            QByteArray fileData = file.readAll();
            file.close();

            if (extension == QStringLiteral("asm"))
                Assembler(mProgram.get(), this).parse(source.file, fileData);
            else {
                error(source.file, 0, tr("Unsupported file type: %1").arg(extension));
                break;
            }
        }
    } catch (const std::exception& e) {
        error(nullptr, 0, tr("Exception: %1").arg(e.what()));
    } catch (...) {
        error(nullptr, 0, tr("Unhandled Exception"));
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

#include "Compiler.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "Assembler.h"
#include "Linker.h"
#include "Util.h"
#include <exception>
#include <QFile>
#include <QFileInfo>

#ifndef emit
#define emit
#endif

namespace
{
    class CompilationFailed
    {
    };
}

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

void Compiler::addSourceFile(File* file, const QString& path)
{
    mSources.emplace_back(SourceFile{ file, path });
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

            if (extension == QStringLiteral("asm")) {
                if (!Assembler(mProgram.get(), this).parse(source.file, fileData))
                    throw CompilationFailed();
            } else {
                error(source.file, 0, tr("Unsupported file type: %1").arg(extension));
                throw CompilationFailed();
            }
        }

        setStatusText(tr("Generating code..."));
        auto binary = Linker(mProgram.get(), this).emitCode();
        if (!binary)
            throw CompilationFailed();

        // FIXME
        if (!writeFile("out.bin", binary->codeBytes(), binary->codeLength(), this))
            throw CompilationFailed();
    } catch (const CompilationFailed&) {
        emit compilationEnded();
        return;
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

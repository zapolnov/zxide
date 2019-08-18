#include "Compiler.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "Assembler.h"
#include "Linker.h"
#include "TapeFileWriter.h"
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
    , mOutputFile(QStringLiteral("out.tap"))
    , mErrorFile(nullptr)
    , mErrorLine(0)
    , mWasError(false)
{
}

Compiler::~Compiler()
{
}

std::unique_ptr<Program> Compiler::takeProgram()
{
    std::unique_ptr<Program> program{std::move(mProgram)};
    return program;
}

std::unique_ptr<ProgramBinary> Compiler::takeProgramBinary()
{
    std::unique_ptr<ProgramBinary> programBinary{std::move(mProgramBinary)};
    return programBinary;
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
            }
        }

        setStatusText(tr("Generating code..."));
        mProgramBinary = Linker(mProgram.get(), this).emitCode();
        if (!mProgramBinary)
            throw CompilationFailed();

        setStatusText(tr("Writing tape file..."));
        if (!TapeFileWriter(mProgramBinary.get(), this).writeTapeFile(mOutputFile))
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

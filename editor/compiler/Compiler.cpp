#include "Compiler.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "Assembler.h"
#include "Linker.h"
#include "TapeFileWriter.h"
#include "Util.h"
#include <lua.hpp>
#include <stdexcept>
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

    class LuaError : public std::runtime_error
    {
    public:
        LuaError(const char* message) : std::runtime_error(message ? message : "(unknown error)") {}
    };
}

Compiler::Compiler(QObject* parent)
    : QObject(parent)
    , mProgram(new Program)
    , mLua(nullptr)
    , mOutputFile(QStringLiteral("out.tap"))
    , mErrorFile(nullptr)
    , mErrorLine(0)
    , mWasError(false)
{
}

Compiler::~Compiler()
{
    destroyLuaVM();
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
    QString ext = QFileInfo(path).suffix();
    if (ext == QStringLiteral("lua"))
        mBuildScripts.emplace_back(SourceFile{ file, path });
    else if (ext == QStringLiteral("asm") || ext == QStringLiteral("gfx"))
        mSources.emplace_back(SourceFile{ file, path });
}

void Compiler::compile()
{
    try {
        if (!runBuildScripts())
            throw CompilationFailed();

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
    } catch (const LuaError& e) {
        error(nullptr, 0, QStringLiteral("Lua: %1").arg(e.what()));
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

bool Compiler::runBuildScripts()
{
    destroyLuaVM();

    mLua = luaL_newstate();
    if (!mLua)
        throw std::runtime_error("Unable to initialize Lua VM.");

    try {
        lua_atpanic(mLua, [](lua_State* L) -> int { throw LuaError(lua_tostring(L, -1)); });
        luaL_openlibs(mLua);

        for (const auto& script : mBuildScripts) {
            QFileInfo info(script.path);
            setStatusText(tr("Running %1").arg(info.fileName()));

            QFile file(info.absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                error(script.file, 0, file.errorString());
                return false;
            }

            QByteArray fileData = file.readAll();
            file.close();

            QByteArray fileName = QByteArray("@") + info.fileName().toUtf8();
            int r = luaL_loadbuffer(mLua, fileData.constData(), fileData.length(), fileName.constData());
            if (r == LUA_OK)
                r = lua_pcall(mLua, 0, 0, 0);

            if (r != LUA_OK) {
                int line = 1;

                const char* message = lua_tostring(mLua, -1);
                const char* p = strchr(message, '\2');
                if (p) {
                    line = (int)strtol(p + 1, nullptr, 10);
                    const char* end = strchr(p + 1, '\3');
                    if (!end)
                        end = p;
                    message = end + 1;
                }

                error(script.file, line, message ? QString::fromUtf8(message) : tr("(unknown error)"));
                return false;
            }
        }
    } catch (...) {
        destroyLuaVM();
        throw;
    }

    return true;
}

void Compiler::destroyLuaVM()
{
    if (mLua) {
        lua_close(mLua);
        mLua = nullptr;
    }
}

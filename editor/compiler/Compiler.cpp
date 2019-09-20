#include "Compiler.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "ProgramOpcode.h"
#include "Assembler.h"
#include "Linker.h"
#include "LuaBindings.h"
#include "TapeFileWriter.h"
#include "Util.h"
#include "GfxFile.h"
#include "MapFile.h"
#include "scripting/LuaVM.h"
#include <exception>
#include <QDataStream>
#include <QFile>
#include <QFileInfo>
#include <cstdarg>
#include <bas2tap.h>
#include <lua.hpp>

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
    , mOutputTapeFile(QStringLiteral("out.tap"))
    , mOutputWavFile(QStringLiteral("out.wav"))
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

void Compiler::addSourceFile(const QString& fullName, const QString& path)
{
    QString ext = QFileInfo(path).suffix();
    if (ext == QStringLiteral("lua"))
        mBuildScripts.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
    else if (ext == QStringLiteral("bas"))
        mBasicSources.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
    else if (ext == QStringLiteral("c"))
        mCSources.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
    else if (ext == QStringLiteral("asm"))
        mAssemblerSources.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
    else if (ext == QStringLiteral("gfx"))
        mGraphics.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
    else if (ext == QStringLiteral("map"))
        mMaps.emplace_back(std::make_unique<SourceFile>(SourceFile{ fullName, path }));
}

void Compiler::setSettings(CompileSettings settings)
{
    mCompileSettings = std::move(settings);
}

void Compiler::compile()
{
    try {
        if (!runBuildScripts())
            throw CompilationFailed();
        if (!compileCCode())
            throw CompilationFailed();

        // Compile assembler sources
        for (const auto& source : mAssemblerSources) {
            QFileInfo info(source->path);
            setStatusText(tr("Compiling %1").arg(info.fileName()));

            QFile file(info.absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                error(source->name, 0, file.errorString());
                break;
            }

            QByteArray fileData = file.readAll();
            file.close();

            if (!Assembler(mProgram.get(), this).parse(source.get(), fileData))
                throw CompilationFailed();
        }

        // Compile graphic files
        for (const auto& source : mGraphics) {
            QFileInfo info(source->path);
            setStatusText(tr("Processing %1").arg(info.fileName()));

            QFile file(info.absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                error(source->name, 0, file.errorString());
                break;
            }

            GfxFile gfxFile(file.readAll());
            file.close();

            GfxData data(0, 0);
            if (!gfxFile.deserializeFromJson(&data)) {
                error(source->name, 0,
                    tr("unable to load file '%1': %2").arg(file.fileName()).arg(gfxFile.lastError()));
                break;
            }

            switch (gfxFile.format) {
                case GfxFormat::None:
                    continue;

                case GfxFormat::Monochrome: {
                    gfxFile.clearData();
                    gfxFile.serializeToMonochrome(&data);
                    break;
                }

                case GfxFormat::BTile16: {
                    gfxFile.clearData();
                    gfxFile.serializeToBTile16(&data);
                    break;
                }

                default:
                    Q_ASSERT(false);
                    error(source->name, 0, tr("file '%1' has unknown output format"));
                    continue;
            }

            includeBinaryFile(source.get(), info, gfxFile.data());
        }

        // Compile map files
        for (const auto& source : mMaps) {
            QFileInfo info(source->path);
            setStatusText(tr("Processing %1").arg(info.fileName()));

            QFile file(info.absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                error(source->name, 0, file.errorString());
                break;
            }

            MapFile mapFile(file.readAll());
            file.close();

            MapData data(0, 0);
            if (!mapFile.deserializeFromJson(&data)) {
                error(source->name, 0,
                    tr("unable to load file '%1': %2").arg(file.fileName()).arg(mapFile.lastError()));
                break;
            }

            switch (mapFile.format) {
                case MapFormat::None:
                    continue;

                case MapFormat::ByteArray: {
                    mapFile.clearData();
                    mapFile.serializeToByteArray(&data);
                    break;
                }

                default:
                    Q_ASSERT(false);
                    error(source->name, 0, tr("file '%1' has unknown output format"));
                    continue;
            }

            includeBinaryFile(source.get(), info, mapFile.data());
        }

        setStatusText(tr("Linking assembly code..."));
        mProgramBinary = Linker(mProgram.get(), this).emitCode();
        if (!mProgramBinary)
            throw CompilationFailed();

        if (!compileBasicCode())
            throw CompilationFailed();

        setStatusText(tr("Writing bin files..."));
        for (const auto& it : mProgramBinary->files()) {
            mProgramBinary->setCurrentFile(it.first);
            QString fileName = QStringLiteral("%1@%2.bin").arg(it.first.c_str()).arg(mProgramBinary->baseAddress(), 0, 16);
            fileName = QDir(QFileInfo(mOutputTapeFile).absolutePath()).absoluteFilePath(fileName);
            std::vector<char> data;
            data.resize(mProgramBinary->baseAddress() + mProgramBinary->codeLength());
            memcpy(data.data() + mProgramBinary->baseAddress(), mProgramBinary->codeBytes(), mProgramBinary->codeLength());
            writeFile(fileName, data.data(), data.size(), this);
        }

        setStatusText(tr("Writing tape file..."));
        TapeFileWriter tapeWriter(mProgramBinary.get(), this);
        tapeWriter.setBasicCode(mCompiledBasicCode);
        tapeWriter.setBasicStartLine(mCompileSettings.basicStartLine);
        tapeWriter.setLoaderName(mCompileSettings.loaderName);
        tapeWriter.setProgramName(mCompileSettings.programName);
        if (!tapeWriter.makeTape()
                || !tapeWriter.writeTapeFile(mOutputTapeFile)
                || !tapeWriter.writeWavFile(mOutputWavFile))
            throw CompilationFailed();

        mProgramBinary->setCurrentFile(std::string());
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

void Compiler::error(const QString& file, int line, const QString& message)
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
    try {
        LuaVM lua;
        connect(&lua, &LuaVM::stringPrinted, this, &Compiler::diagnosticMessage);
        connect(&lua, &LuaVM::errorPrinted, this, &Compiler::diagnosticMessage);

        lua.openLibs();
        lua.openLib(LuaBindings);

        lua_pushlightuserdata(lua, this);
        lua_rawsetp(lua, LUA_REGISTRYINDEX, &LuaBindings_CompilerKey);

        lua.setGeneratedFilesDirectory(mGeneratedFilesDirectory);
        lua.setProjectDirectory(mProjectDirectory);

        for (const auto& script : mBuildScripts) {
            QFileInfo info(script->path);
            setStatusText(tr("Running %1").arg(info.fileName()));
            try {
                lua.runScript(info.absoluteFilePath());
            } catch (const LuaError& e) {
                error(script->name, e.line(), e.message());
                return false;
            }
        }

        for (const auto& file : lua.generatedFiles())
            addSourceFile(file.name, file.path);
    } catch (const LuaError& e) {
        error(nullptr, 0, QStringLiteral("Lua: %1").arg(e.message()));
        return false;
    }

    return true;
}

#ifdef emit
#undef emit
#endif

void Compiler::includeBinaryFile(const SourceFile* source, const QFileInfo& inputFile, const QByteArray& data)
{
    Token token;
    token.file = source;
    token.line = 0;
    token.id = T_IDENTIFIER;
    token.text = identifierFromString(inputFile.fileName());

    auto section = mProgram->getOrCreateSection(token.text, token);
    mProgram->addLabel(token, section, token.text);
    section->emit<DEFB_BYTEARRAY>(token, data);
}

namespace
{
    class CommandLine
    {
    public:
        int argc;
        char** argv;

        CommandLine() = default;

        void add(std::string arg)
        {
            mArgs.emplace_back(std::move(arg));
        }

        void finalize()
        {
            argc = int(mArgs.size());
            mArgv.clear();
            mArgv.reserve(mArgs.size());
            for (auto& it : mArgs)
                mArgv.emplace_back(&it[0]);
        }

    private:
        std::vector<std::string> mArgs;
        std::vector<char*> mArgv;

        Q_DISABLE_COPY(CommandLine)
    };
}

bool Compiler::compileCCode()
{
    for (const auto& source : mCSources) {
        QFileInfo info(source->path);
        setStatusText(tr("Compiling %1").arg(info.fileName()));

        CommandLine cmdLine;
        cmdLine.add("sdcpp");
        cmdLine.add(info.absoluteFilePath().toUtf8().constData());
        //cmdLine.add("-D...");
        //cmdLine.add("-I...");
        cmdLine.add("-fsigned-char");
        cmdLine.add("-std=c11"); // c89, c99
        cmdLine.finalize();

        /*
        QFile file(info.absoluteFilePath());
        if (!file.open(QFile::ReadOnly)) {
            error(source->name, 0, file.errorString());
            lines.clear();
            return false;
        }
        QByteArray fileData = file.readAll();
        file.close();
        */

        // FIXME
    }

    return true;
}

namespace
{
    struct Line
    {
        const SourceFile* file;
        int line;
        int basicIndex;
        QByteArray lineData;
    };

    static Compiler* compiler;
    static std::map<int, Line> lines;
    static std::map<int, Line>::const_iterator linesIter;
    static std::unique_ptr<QDataStream> compiledBasicStream;
    static const SourceFile* basicFile;
    static int basicFileLine;
}

#define APPEND(C) \
    if (d >= MAXLINELENGTH) { \
        error(source->name, line, tr("line is too long")); \
        return false; \
    } else \
        lineIn[d++] = (C)

#define APPENDSTR(STR) \
    for (const char* str = (STR); *str; ++str) \
        APPEND(*str)

bool Compiler::compileBasicCode()
{
    setStatusText(tr("Compiling BASIC code..."));

    compiler = this;
    bas2tap_error = bas2tapError;
    bas2tap_fgets = bas2tapFGets;
    bas2tap_output = bas2tapOutput;

    lines.clear();
    bas2tap_reset();

    for (const auto& source : mBasicSources) {
        QFileInfo info(source->path);
        QFile file(info.absoluteFilePath());
        if (!file.open(QFile::ReadOnly)) {
            error(source->name, 0, file.errorString());
            lines.clear();
            return false;
        }
        QByteArray fileData = file.readAll();
        file.close();

        const char* p = fileData.constData();
        const char* end = p + fileData.length();
        int line = 0;
        while (p < end) {
            ++line;
            basicFile = source.get();
            basicFileLine = line;

            char lineIn[MAXLINELENGTH + 1];
            int d = 0;
            while (*p) {
                char ch = *p++;
                if (ch == '\r' && *p == '\n') {
                    ++p;
                    ch = '\n';
                }

                if (ch == '@' && *p == '{') {
                    const char* pend = p + 1;
                    while (*pend && *pend != '}')
                        ++pend;
                    if (*pend == '}') {
                        int n = int(pend - (p + 1));
                        if (n == 9 && !strncmp(p + 1, "clearaddr", n)) {
                            char buf[32];
                            snprintf(buf, sizeof(buf), "%d", mProgramBinary->baseAddress() - 1);
                            APPENDSTR(buf);
                            p = pend + 1;
                            continue;
                        } else if (n == 8 && !strncmp(p + 1, "baseaddr", n)) {
                            char buf[32];
                            snprintf(buf, sizeof(buf), "%d", mProgramBinary->baseAddress());
                            APPENDSTR(buf);
                            p = pend + 1;
                            continue;
                        }
                    }
                }

                APPEND(ch);

                if (ch == '\n')
                    break;
            }
            lineIn[d] = 0;

            char* basicIndex = nullptr;
            int basicLine = bas2tap_PrepareLine(lineIn, line, &basicIndex);
            if (basicLine < 0) {
                if (basicLine == -1) {
                    lines.clear();
                    return false;
                }
                continue; // line should be skipped
            }

            Line l;
            l.file = source.get();
            l.line = line;
            l.basicIndex = int(basicIndex - bas2tap_ConvertedSpectrumLine);
            l.lineData = bas2tap_ConvertedSpectrumLine;
            if (!lines.emplace(basicLine, std::move(l)).second) {
                error(source->name, line, tr("duplicate use of line number %1").arg(basicLine));
                lines.clear();
                return false;
            }
        }
    }

    mCompiledBasicCode.clear();
    compiledBasicStream = std::make_unique<QDataStream>(&mCompiledBasicCode, QFile::WriteOnly);

    linesIter = lines.cbegin();
    basicFile = nullptr;
    basicFileLine = 0;
    bool success = (bas2tap_main() == 0);

    lines.clear();
    compiledBasicStream.reset();

    return success;
}

void Compiler::bas2tapError(int line, int stmt, const char* fmt, ...)
{
    char buf[1024];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    compiler->error((basicFile ? basicFile->name : QString()), basicFileLine, QString::fromUtf8(buf));
}

int Compiler::bas2tapFGets(char** basicIndex, int* basicLineNo)
{
    if (linesIter == lines.end())
        return 0;

    int basicLine = linesIter->first;
    const Line& line = linesIter->second;
    ++linesIter;

    basicFile = line.file;
    basicFileLine = line.line;
    memcpy(bas2tap_ConvertedSpectrumLine, line.lineData.constData(), line.lineData.length() + 1);
    *basicIndex = bas2tap_ConvertedSpectrumLine + line.basicIndex;
    *basicLineNo = basicLine;

    return 1;
}

void Compiler::bas2tapOutput(const void* dst, size_t length)
{
    compiledBasicStream->writeRawData(reinterpret_cast<const char*>(dst), int(length));
}

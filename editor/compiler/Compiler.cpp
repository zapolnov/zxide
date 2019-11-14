#include "Compiler.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "ProgramOpcode.h"
#include "Assembler.h"
#include "Linker.h"
#include "LuaBindings.h"
#include "TapeFileWriter.h"
#include "DiskFileWriter.h"
#include "Util.h"
#include "GfxFile.h"
#include "MapFile.h"
#include "ProjectSettings.h"
#include "IO.h"
#include "scripting/LuaVM.h"
#include <exception>
#include <QDateTime>
#include <QDataStream>
#include <QFileInfo>
#include <cstdarg>
#include <sstream>
#include <bas2tap.h>
#include <lua.hpp>
#include <unordered_set>
#include <sdcc_bridge.h>

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
    , mOutputDiskFile(QStringLiteral("out.scl"))
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

void Compiler::compile()
{
    try {
        mProjectSettings = std::make_unique<ProjectSettings>();
        mProjectSettings->load(mProjectFile);

        if (!runBuildScripts())
            throw CompilationFailed();
        if (!compileCCode())
            throw CompilationFailed();

        // Compile assembler sources
        for (const auto& source : mAssemblerSources) {
            QFileInfo info(source->path);
            setStatusText(tr("Assembling %1").arg(info.fileName()));

            QByteArray fileData;
            try {
                fileData = loadFile(info.absoluteFilePath());
            } catch (const IOException& e) {
                error(source->name, 0, e.message());
                break;
            }

            if (!Assembler(this, mProgram.get(), this).parse(source.get(), fileData))
                throw CompilationFailed();
        }

        // Compile graphic files
        for (const auto& source : mGraphics) {
            QFileInfo info(source->path);
            setStatusText(tr("Processing %1").arg(info.fileName()));

            QByteArray fileData;
            QString fileName = info.absoluteFilePath();
            try {
                fileData = loadFile(fileName);
            } catch (const IOException& e) {
                error(source->name, 0, e.message());
                break;
            }

            GfxFile gfxFile(fileData);
            GfxData data(0, 0);
            if (!gfxFile.deserializeFromJson(&data)) {
                error(source->name, 0,
                    tr("unable to load file '%1': %2").arg(fileName).arg(gfxFile.lastError()));
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

            QByteArray fileData;
            QString fileName = info.absoluteFilePath();
            try {
                fileData = loadFile(info.absoluteFilePath());
            } catch (const IOException& e) {
                error(source->name, 0, e.message());
                break;
            }

            MapFile mapFile(fileData);
            MapData data(0, 0);
            if (!mapFile.deserializeFromJson(&data)) {
                error(source->name, 0,
                    tr("unable to load file '%1': %2").arg(fileName).arg(mapFile.lastError()));
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
        tapeWriter.setBasicStartLine(mProjectSettings->basicStartLine);
        tapeWriter.setLoaderName(mProjectSettings->loaderFileName());
        tapeWriter.setProgramName(mProjectSettings->programFileName());
        if (!tapeWriter.makeTape()
                || !tapeWriter.writeTapeFile(mOutputTapeFile)
                || !tapeWriter.writeWavFile(mOutputWavFile))
            throw CompilationFailed();

        setStatusText(tr("Writing disk file..."));
        DiskFileWriter diskWriter(mProgramBinary.get(), this);
        diskWriter.setBasicCode(mCompiledBasicCode);
        diskWriter.setBasicStartLine(mProjectSettings->basicStartLine);
        diskWriter.setLoaderName(mProjectSettings->loaderFileName());
        diskWriter.setProgramName(mProjectSettings->programFileName());
        if (!diskWriter.writeSclFile(mOutputDiskFile))
            throw CompilationFailed();

        mProgramBinary->setCurrentFile(std::string());
    } catch (const CompilationFailed&) {
        emit compilationEnded();
        return;
    } catch (const IOException& e) {
        error(nullptr, 0, e.message());
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
    class Aborted
    {
    };

    class Failed
    {
    };

    class AutoCleanup
    {
    public:
        explicit AutoCleanup(const std::function<void()>&& func) : mFunc(func) {}
        ~AutoCleanup() { mFunc(); }

    private:
        std::function<void()> mFunc;

        Q_DISABLE_COPY(AutoCleanup)
    };

    class CommandLine
    {
    public:
        int argc;
        const char** argv;

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
            argv = &mArgv[0];
        }

    private:
        std::vector<std::string> mArgs;
        std::vector<const char*> mArgv;

        Q_DISABLE_COPY(CommandLine)
    };

    static QDir projectDir;
    static std::vector<std::string> includeFiles;
    static std::unordered_set<QFile*> openFiles;
    static std::stringstream msg;
    static std::stringstream out;
    static std::string input;
    static size_t inputIndex;
    static const char* cFileName;
    static int cLineNumber = -1;
    static IErrorReporter* cErrorReporter;

    static void sdccAbort()
    {
        throw Aborted();
    }

    static void sdccFatalExit()
    {
        throw Failed();
    }

    void* sdccInOpen(const char* fileName)
    {
        QString name = QString::fromUtf8(fileName);

        if (fileName[0] == ':') {
            auto file = std::make_unique<QFile>(name);
            if (file->open(QFile::ReadOnly)) {
                openFiles.emplace(file.get());
                return file.release();
            }
        }

        auto file = std::make_unique<QFile>(projectDir.absoluteFilePath(name));
        if (file->open(QFile::ReadOnly)) {
            openFiles.emplace(file.get());
            return file.release();
        }

        file->setFileName(QStringLiteral(":/include/%1").arg(name));
        if (file->open(QFile::ReadOnly)) {
            openFiles.emplace(file.get());
            return file.release();
        }

        return nullptr;
    }

    void sdccInClose(void* file)
    {
        openFiles.erase(reinterpret_cast<QFile*>(file));
        delete reinterpret_cast<QFile*>(file);
    }

    int sdccInRead(void* file, void* buffer, size_t size)
    {
        auto f = reinterpret_cast<QFile*>(file);
        return int(f->read(reinterpret_cast<char*>(buffer), size));
    }

    int sdccInGetChar(void* file)
    {
        char ch = 0;
        auto f = reinterpret_cast<QFile*>(file);
        if (f->read(&ch, 1) != 1)
            return EOF;
        return ch;
    }

    long sdccInGetFileSize(void* file)
    {
        auto f = reinterpret_cast<QFile*>(file);
        return long(f->size());
    }

    void sdccInRewind(void* file)
    {
        auto f = reinterpret_cast<QFile*>(file);
        f->seek(0);
    }

    int sdccInEof(void* file)
    {
        auto f = reinterpret_cast<QFile*>(file);
        return f->atEnd();
    }

    int sdccYYInGetChar()
    {
        if (inputIndex >= input.length())
            return EOF;
        return input[inputIndex++];
    }

    char* sdccInFGetS(char* buf, size_t max, void* file)
    {
        if (!file) {
            char* p = buf;
            while (max-- > 1) {
                int ch = sdccYYInGetChar();
                if (ch == EOF) {
                    if (p == buf)
                        return NULL;
                    break;
                }
                *p++ = ch;
                if (ch == '\n')
                    break;
            }
            if (p >= buf + 2 && p[-1] == '\n' && p[-2] == '\r') {
                --p;
                p[-1] = '\n';
            }
            if (max > 0)
                *p = 0;
            return buf;
        }

        auto f = reinterpret_cast<QFile*>(file);
        if (f->atEnd())
            return nullptr;
        QByteArray line = f->readLine();
        if (line.endsWith("\r\n"))
            line = line.mid(0, line.length() - 2) + "\n";
        size_t len = std::min<size_t>(max - 1, size_t(line.length()));
        memcpy(buf, line.constData(), len);
        buf[len] = 0;
        return buf;
    }

    void sdccOutPutChar(char ch)
    {
        out << ch;
    }

    void sdccOutPutString(const char* str)
    {
        out << str;
    }

    void sdccOutPrintF(const char* fmt, ...)
    {
        char buf[16384];
        va_list args;

        va_start(args, fmt);
        vsnprintf(buf, sizeof(buf), fmt, args);
        va_end(args);

        sdccOutPutString(buf);
    }

    void sdccOutWrite(const void* data, size_t size)
    {
        out.write(reinterpret_cast<const char*>(data), size);
    }

    void sdccMsgSetLocation(const char* filename, int line)
    {
        cFileName = filename;
        cLineNumber = line;
    }

    void sdccMsgPutChar(char ch)
    {
        if (ch != '\n')
            msg << ch;
        else {
            std::string str = msg.str();
            msg.str(std::string());

            if (!cFileName)
                qDebug("%s", str.c_str());
            else {
                if (cFileName[0] == '.' && cFileName[1] == '/')
                    cFileName += 2;
                cErrorReporter->error(QString::fromUtf8(cFileName), cLineNumber, QString::fromUtf8(str.c_str()));
                qDebug("%s(%d): %s", cFileName, cLineNumber, str.c_str());
            }

            cFileName = NULL;
            cLineNumber = -1;
        }
    }

    void sdccMsgPutString(const char* str)
    {
        while (*str)
            sdccMsgPutChar(*str++);
    }

    void sdccMsgVPrintF(const char* fmt, va_list args)
    {
        char buf[16384];
        vsnprintf(buf, sizeof(buf), fmt, args);
        sdccMsgPutString(buf);
    }

    void sdccMsgPrintF(const char* fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        sdccMsgVPrintF(fmt, args);
        va_end(args);
    }

    void sdccPrintInclude(const char* file)
    {
        if (file[0] == '.' && file[1] == '/')
            file += 2;
      #ifdef _WIN32
        else if (file[0] == '.' && file[1] == '\\')
            file += 2;
      #endif
        includeFiles.emplace_back(file);
    }

    static void sdccCleanup()
    {
        sdcc_closeInputFile();
        sdcc_cleanupAsm();
        sdcc_cleanupAst();
        sdcc_cleanupLabel();
        sdcc_cleanupGen();
        sdcc_cleanupRAlloc();
        sdcc_cleanupPeeph();
        sdcc_cleanupHTab();
        sdcc_cleanupLRange();
        sdcc_cleanupOpt();
        sdcc_cleanupZ80Gen();
        sdcc_cleanupGlue();
        sdcc_cleanupY();
        sdcc_cleanupLex();

        while (!openFiles.empty()) {
            void* file = *openFiles.begin();
            sdccInClose(file);
        }

        sdcc_collectGarbage();
    }
}

extern "C" int copt_main(int argc, const char** argv);

bool Compiler::compileCCode()
{
    AutoCleanup cleanup{sdccCleanup};

    projectDir = mProjectDirectory;

    sdcc_abort = sdccAbort;
    sdcc_fatal_exit = sdccFatalExit;
    sdcc_in_open = sdccInOpen;
    sdcc_in_close = sdccInClose;
    sdcc_in_read = sdccInRead;
    sdcc_in_getc = sdccInGetChar;
    sdcc_in_getfilesize = sdccInGetFileSize;
    sdcc_in_rewind = sdccInRewind;
    sdcc_in_eof = sdccInEof;
    sdcc_in_fgets = sdccInFGetS;
    sdcc_yyin_getc = sdccYYInGetChar;
    sdcc_out_putc = sdccOutPutChar;
    sdcc_out_puts = sdccOutPutString;
    sdcc_out_printf = sdccOutPrintF;
    sdcc_out_write = sdccOutWrite;
    sdcc_msg_setlocation = sdccMsgSetLocation;
    sdcc_msg_putc = sdccMsgPutChar;
    sdcc_msg_puts = sdccMsgPutString;
    sdcc_msg_printf = sdccMsgPrintF;
    sdcc_msg_vprintf = sdccMsgVPrintF;
    sdcc_print_include = sdccPrintInclude;

    for (const auto& source : mCSources) {
        QFileInfo info(source->path);
        setStatusText(tr("Checking dependencies for %1").arg(info.fileName()));

        QFileInfo outInfo(source->name);
        QString outFileName = QStringLiteral("%1/%2.asm").arg(outInfo.path()).arg(outInfo.completeBaseName());
        QString outFilePath = mGeneratedFilesDirectory.absoluteFilePath(outFileName);
        QString depFileName = QStringLiteral("%1/%2.asm.dep").arg(outInfo.path()).arg(outInfo.completeBaseName());
        QString depFilePath = mGeneratedFilesDirectory.absoluteFilePath(depFileName);

        mAssemblerSources.emplace_back(std::make_unique<SourceFile>(SourceFile{
                QStringLiteral("generated/%1").arg(outFileName),
                outFilePath
            }));

        if (QFile::exists(outFilePath) && QFile::exists(depFilePath)) {
            QFileInfo outFileInfo(outFilePath);
            if (info.lastModified() < outFileInfo.lastModified()) {
                bool changed = false;
                QList<QByteArray> deps = loadFile(depFilePath).split('\n');
                for (const auto& dep : deps) {
                    QFileInfo depInfo(mProjectDirectory.absoluteFilePath(dep));
                    if (!depInfo.exists() || depInfo.lastModified() >= outFileInfo.lastModified()) {
                        changed = true;
                        break;
                    }
                }

                if (!changed)
                    continue;
            }
         }

        setStatusText(tr("Preprocessing %1").arg(info.fileName()));

        CommandLine ppCmd;
        ppCmd.add("sdcpp");
        ppCmd.add(source->name.toUtf8().constData());
        switch (mProjectSettings->standard) {
            case CStandard::C89: ppCmd.add("-std=c89"); break;
            case CStandard::C99: ppCmd.add("-std=c99"); break;
            case CStandard::C11: ppCmd.add("-std=c11"); break;
        }
        ppCmd.add(mProjectSettings->charIsUnsigned ? "-funsigned-char" : "-fsigned-char");
        ppCmd.add("-H");
        ppCmd.add("-D__SDCC_z80");
        for (const auto& it : mProjectSettings->defines) {
            if (!it.empty())
                ppCmd.add("-D" + it);
        }
        ppCmd.add("-I.");
        ppCmd.finalize();

        includeFiles.clear();
        msg.str(std::string());
        out.str(std::string());
        cFileName = NULL;
        cLineNumber = -1;
        cErrorReporter = this;

        try {
            int r = sdcpp_main(ppCmd.argc, ppCmd.argv);
            if (r != 0) {
                error(source->name, 0, "internal preprocessor error");
                return false;
            }
        } catch (const Aborted&) {
            error(source->name, 0, "internal preprocessor error");
            return false;
        } catch (const Failed&) {
            error(source->name, 0, "internal preprocessor error");
            return false;
        }

        setStatusText(tr("Compiling %1").arg(info.fileName()));

        CommandLine ccCmd;
        ccCmd.add("sdcc");
        ccCmd.add("--c1mode");
        ccCmd.add("-o"); ccCmd.add("output");
        ccCmd.add("-mz80");
        ccCmd.add("-pz80");
        switch (mProjectSettings->standard) {
            case CStandard::C89: ccCmd.add("--std-sdcc89"); break;
            case CStandard::C99: ccCmd.add("--std-sdcc99"); break;
            case CStandard::C11: ccCmd.add("--std-sdcc11"); break;
        }
        switch (mProjectSettings->optimization) {
            case COptimization::Default: break;
            case COptimization::FavorSpeed: ccCmd.add("--opt-code-speed"); break;
            case COptimization::FavorSize: ccCmd.add("--opt-code-size"); break;
        }
        ccCmd.add("--codeseg"); ccCmd.add(mProjectSettings->codeSeg());
        ccCmd.add("--constseg"); ccCmd.add(mProjectSettings->constSeg());
        ccCmd.add("--dataseg"); ccCmd.add(mProjectSettings->dataSeg());
        if (!mProjectSettings->charIsUnsigned)
            ccCmd.add("--fsigned-char");
        if (mProjectSettings->stackAutomaticVariables)
            ccCmd.add("--stack-auto");
        if (mProjectSettings->calleeSaves)
            ccCmd.add("--all-callee-saves");
        if (mProjectSettings->omitFramePointer)
            ccCmd.add("--fomit-frame-pointer");
        ccCmd.add("--no-optsdcc-in-asm");
        ccCmd.add("--allow-unsafe-read");
        ccCmd.finalize();

        input = out.str();
        inputIndex = 0;
        cFileName = NULL;
        cLineNumber = -1;
        out.str(std::string());

        try {
            char* envp[] = { NULL };
            int r = sdcc_main(ccCmd.argc, (char**)ccCmd.argv, envp);
            if (r != 0) {
                error(source->name, 0, "internal compiler error");
                return false;
            }
        } catch (const Aborted&) {
            error(source->name, 0, "internal compiler error");
            return false;
        } catch (const Failed&) {
            error(source->name, 0, "internal compiler error");
            return false;
        }

        for (const auto& it : { "1", "9", "2" }) {
            CommandLine coptCmd;
            coptCmd.add("copt");
            coptCmd.add(std::string(":/z88dk/sdcc_opt.") + it);
            coptCmd.finalize();

            input = out.str();
            inputIndex = 0;
            cFileName = NULL;
            cLineNumber = -1;
            out.str(std::string());

            try {
                int r = copt_main(coptCmd.argc, coptCmd.argv);
                if (r != 0) {
                    error(source->name, 0, "internal optimizer error");
                    return false;
                }
            } catch (const Aborted&) {
                error(source->name, 0, "internal optimizer error");
                return false;
            } catch (const Failed&) {
                error(source->name, 0, "internal optimizer error");
                return false;
            }
        }

        if (!writeFile(outFilePath, out.str(), this))
            return false;

        std::stringstream dep;
        for (const auto& file : includeFiles)
            dep << file << '\n';
        if (!writeFile(depFilePath, dep.str(), this))
            return false;

        sdccCleanup();
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

    mProgramBinary->setCurrentFile("");

    for (const auto& source : mBasicSources) {
        QFileInfo info(source->path);

        QByteArray fileData;
        try {
            fileData = loadFile(info.absoluteFilePath());
        } catch (const IOException& e) {
            error(source->name, 0, e.message());
            lines.clear();
            return false;
        }

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
    compiledBasicStream = std::make_unique<QDataStream>(&mCompiledBasicCode, QIODevice::WriteOnly);

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

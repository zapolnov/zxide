#include "LuaVM.h"
#include "LuaFiles.h"
#include "LuaGfx.h"
#include "LuaTileSet.h"
#include "LuaMap.h"
#include "LuaMusic.h"
#include "LuaUtil.h"
#include <QFile>
#include <QCoreApplication>
#include <cstdio>
#include <sstream>

static char ThisKey;
static char StringBufferKey;

namespace
{
    struct StringBuffer
    {
        std::stringstream stream;
    };
}

#undef lua_writestring
void lua_writestring(lua_State* L, const char* str, size_t length)
{
    lua_rawgetp(L, LUA_REGISTRYINDEX, &StringBufferKey);
    StringBuffer* buffer = reinterpret_cast<StringBuffer*>(lua_touserdata(L, -1));
    lua_pop(L, 1);

    if (buffer)
        buffer->stream.write(str, length);
}

#undef lua_writeline
void lua_writeline(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    lua_rawgetp(L, LUA_REGISTRYINDEX, &StringBufferKey);
    StringBuffer* buffer = reinterpret_cast<StringBuffer*>(lua_touserdata(L, -1));
    lua_pop(L, 1);

    if (buffer) {
        std::string str = buffer->stream.str();
        buffer->stream.str(std::string());
        emit vm->stringPrinted(QString::fromUtf8(str.data(), int(str.length())));
    }
}

#undef lua_writestringerror
void lua_writestringerror(lua_State* L, const char* fmt, const char* arg)
{
    char buf[1024];
    snprintf(buf, sizeof(buf), fmt, arg);
    emit LuaVM::fromLua(L)->errorPrinted(QString::fromUtf8(buf));
}

LuaVM::LuaVM(QObject* parent)
    : QObject(parent)
{
    mLua = luaL_newstate();
    if (!mLua)
        throw LuaError("Unable to initialize Lua VM.", 0);

    lua_atpanic(mLua, [](lua_State* L) -> int { throw LuaError(lua_tostring(L, -1), 0); });

    try {
        lua_pushlightuserdata(mLua, this);
        lua_rawsetp(mLua, LUA_REGISTRYINDEX, &ThisKey);
        pushNew<StringBuffer>();
        lua_rawsetp(mLua, LUA_REGISTRYINDEX, &StringBufferKey);
    } catch (const LuaError&) {
        lua_close(mLua);
        throw;
    }
}

LuaVM::~LuaVM()
{
    lua_close(mLua);
}

LuaVM* LuaVM::fromLua(lua_State* L)
{
    lua_rawgetp(L, LUA_REGISTRYINDEX, &ThisKey);
    void* ptr = lua_touserdata(L, -1);
    lua_pop(L, 1);
    return reinterpret_cast<LuaVM*>(ptr);
}

void LuaVM::openLibs()
{
    luaL_openlibs(mLua);
    openLib(LuaFiles);
    openLib(LuaGfx);
    openLib(LuaTileSet);
    openLib(LuaMap);
    openLib(LuaMusic);
    openLib(LuaUtil);
}

void LuaVM::openLib(const char* name, lua_CFunction func)
{
    luaL_requiref(mLua, name, func, 1);
    lua_pop(mLua, 1);
}

void LuaVM::openLib(const luaL_Reg* funcs)
{
    lua_pushglobaltable(mLua);
    luaL_setfuncs(mLua, funcs, 0);
    lua_pop(mLua, 1);
}

const QDir& LuaVM::projectDirectory() const
{
    return mProjectDirectory;
}

void LuaVM::setProjectDirectory(const QDir& dir)
{
    mProjectDirectory = dir;
}

const QDir& LuaVM::generatedFilesDirectory() const
{
    return mGeneratedFilesDirectory;
}

void LuaVM::setGeneratedFilesDirectory(const QDir& dir)
{
    mGeneratedFilesDirectory = dir;
}

void LuaVM::addGeneratedFile(const QString& name, const QString& path)
{
    mGeneratedFiles.emplace_back(GeneratedFile{name, path});
}

void LuaVM::pushString(const std::string& str)
{
    lua_pushlstring(mLua, str.data(), str.length());
}

void LuaVM::pushString(const QString& str)
{
    pushByteArray(str.toUtf8());
}

void LuaVM::pushByteArray(const QByteArray& str)
{
    lua_pushlstring(mLua, str.constData(), str.length());
}

void LuaVM::runScript(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        throw LuaError(file.errorString(), 0);
    QByteArray fileData = file.readAll();
    file.close();

    QByteArray luaFileName = QByteArray("@") + fileName.toUtf8();
    int r = luaL_loadbuffer(mLua, fileData.constData(), fileData.length(), luaFileName.constData());
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

        throw LuaError(message ? QString::fromUtf8(message) : QCoreApplication::tr("(unknown error)"), line);
    }
}

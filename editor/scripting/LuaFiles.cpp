#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/IO.h"
#include <QFile>
#include <QFileInfo>
#include <lua.hpp>

int luaFileExists(lua_State* L, const char* name)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const QDir& dir = vm->projectDirectory();
    QString fileName = QString::fromUtf8(name);
    QString filePath = dir.absoluteFilePath(fileName);

    lua_pushboolean(L, QFileInfo::exists(filePath));
    return 1;
}

int luaReadFile(lua_State* L, const char* name)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const QDir& dir = vm->projectDirectory();
    QString fileName = QString::fromUtf8(name);
    QString filePath = dir.absoluteFilePath(fileName);

    QByteArray data = loadFile(filePath);
    vm->pushByteArray(data);

    return 1;
}

int luaReadCsvFile(lua_State* L, const char* name)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const QDir& dir = vm->projectDirectory();
    QString fileName = QString::fromUtf8(name);
    QString filePath = dir.absoluteFilePath(fileName);

    QByteArray data = loadFile(filePath);
    const char* p = data.constData();

    lua_newtable(L);
    int row = 1;
    while (*p) {
        lua_newtable(L);
        const char* start = p;
        int col = 1;
        while (*p && *p != '\r' && *p != '\n') {
            if (*p++ == ',') {
                lua_pushlstring(L, start, p - start - 1);
                start = p;
                lua_rawseti(L, -2, col++);
            }
        }
        lua_pushlstring(L, start, p - start);
        lua_rawseti(L, -2, col);
        if (*p == '\n')
            ++p;
        else if (*p == '\r' && p[1] == '\n')
            p += 2;
        lua_rawseti(L, -2, row++);
    }

    return 1;
}

int luaWriteFile(lua_State* L, const char* name, const void* contents, size_t contentsLength)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const QDir& dir = vm->generatedFilesDirectory();
    QString fileName = QString::fromUtf8(name);
    QString filePath = dir.absoluteFilePath(fileName);
    QString relativeName = vm->projectDirectory().relativeFilePath(filePath);

    QFileInfo fileInfo(filePath);
    QDir(fileInfo.absolutePath()).mkpath(QStringLiteral("."));

    bool writeFile = true;
    if (fileInfo.exists() && fileInfo.size() == qint64(contentsLength)) {
        QByteArray data = loadFile(filePath);
        if (data.length() == int(contentsLength) && memcmp(data.constData(), contents, contentsLength) == 0)
            writeFile = false;
    }

    if (writeFile) {
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly)) {
            QString error = file.errorString();
            QFile::remove(filePath);
            return luaL_error(L, "unable to write file '%s': %s", name, error.toUtf8().constData());
        }

        qint64 bytesWritten = file.write(reinterpret_cast<const char*>(contents), qint64(contentsLength));
        if (bytesWritten < 0) {
            QString error = file.errorString();
            file.close();
            QFile::remove(filePath);
            return luaL_error(L, "unable to write file '%s': %s", name, error.toUtf8().constData());
        }

        if (bytesWritten != qint64(contentsLength)) {
            file.close();
            QFile::remove(filePath);
            return luaL_error(L, "unable to write file '%s'", name);
        }
    }

    vm->addGeneratedFile(relativeName, filePath);

    return 0;
}

static int luaFileExists(lua_State* L)
{
    const char* fileName = luaL_checkstring(L, 1);
    return luaFileExists(L, fileName);
}

static int luaReadFile(lua_State* L)
{
    const char* fileName = luaL_checkstring(L, 1);
    return luaReadFile(L, fileName);
}

static int luaReadCsvFile(lua_State* L)
{
    const char* fileName = luaL_checkstring(L, 1);
    return luaReadCsvFile(L, fileName);
}

static int luaWriteFile(lua_State* L)
{
    size_t contentsLength = 0;
    const char* fileName = luaL_checkstring(L, 1);
    const char* contents = luaL_checklstring(L, 2, &contentsLength);

    return luaWriteFile(L, fileName, contents, contentsLength);
}

const luaL_Reg LuaFiles[] = {
    { "fileExists", luaFileExists },
    { "readFile", luaReadFile },
    { "readCsvFile", luaReadCsvFile },
    { "writeFile", luaWriteFile },
    { nullptr, nullptr }
};

#include "LuaFiles.h"
#include "LuaVM.h"
#include <QFile>
#include <QFileInfo>
#include <lua.hpp>

int luaWriteFile(lua_State* L, const char* fileName, const void* contents, size_t contentsLength)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const QDir& dir = vm->generatedFilesDirectory();
    QString filePath = dir.absoluteFilePath(QString::fromUtf8(fileName));

    QFileInfo fileInfo(filePath);
    QDir(fileInfo.absolutePath()).mkpath(QStringLiteral("."));

    QFile file(filePath);
    if (!file.open(QFile::WriteOnly)) {
        QString error = file.errorString();
        QFile::remove(filePath);
        return luaL_error(L, "unable to write file '%s': %s", fileName, error.toUtf8().constData());
    }

    qint64 bytesWritten = file.write(reinterpret_cast<const char*>(contents), qint64(contentsLength));
    if (bytesWritten < 0) {
        QString error = file.errorString();
        file.close();
        QFile::remove(filePath);
        return luaL_error(L, "unable to write file '%s': %s", fileName, error.toUtf8().constData());
    }

    if (bytesWritten != qint64(contentsLength)) {
        file.close();
        QFile::remove(filePath);
        return luaL_error(L, "unable to write file '%s'", fileName);
    }

    vm->addGeneratedFile(filePath);

    return 0;
}

static int luaWriteFile(lua_State* L)
{
    size_t contentsLength = 0;
    const char* fileName = luaL_checkstring(L, 1);
    const char* contents = luaL_checklstring(L, 2, &contentsLength);

    return luaWriteFile(L, fileName, contents, contentsLength);
}

const luaL_Reg LuaFiles[] = {
    { "writeFile", luaWriteFile },
    { nullptr, nullptr }
};

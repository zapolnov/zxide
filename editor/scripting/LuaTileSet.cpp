#include "LuaTileSet.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/TileSetFile.h"
#include "compiler/TileSetData.h"
#include <string>
#include <sstream>
#include <lua.hpp>

static int luaTilesetLoad(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const char* fileName = luaL_checkstring(L, 1);
    const QDir& dir = vm->projectDirectory();
    QString filePath = dir.absoluteFilePath(QString::fromUtf8(fileName));

    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)) {
        QString error = file.errorString();
        return luaL_error(L, "unable to open file '%s': %s", fileName, error.toUtf8().constData());
    }

    TileSetFile tileSetFile(file.readAll());
    file.close();

    TileSetData* data = vm->pushNew<TileSetData>();
    if (!tileSetFile.deserializeFromJson(data)) {
        QString error = tileSetFile.lastError();
        return luaL_error(L, "unable to load file '%s': %s", fileName, error.toUtf8().constData());
    }

    return 1;
}

const luaL_Reg LuaTileSet[] = {
    { "tilesetLoad", luaTilesetLoad },
    { nullptr, nullptr }
};

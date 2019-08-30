#include "LuaGfx.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/GfxFile.h"
#include "compiler/GfxData.h"
#include <string>
#include <sstream>
#include <lua.hpp>

static int luaGfxLoad(lua_State* L)
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

    GfxFile gfxFile(file.readAll());
    file.close();

    GfxData* data = vm->pushNew<GfxData>(0, 0);
    if (!gfxFile.deserializeFromJson(data)) {
        QString error = gfxFile.lastError();
        return luaL_error(L, "unable to load file '%s': %s", fileName, error.toUtf8().constData());
    }

    return 1;
}

static int luaGfxWriteBTile16(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    GfxData& data = vm->check<GfxData>(1);
    const char* symbol = luaL_checkstring(L, 2);

    GfxFile file;
    file.serializeToBTile16(&data);

    std::stringstream ss;
    ss << "; THIS FILE HAS BEEN AUTOMATICALLY GENERATED\n";
    ss << "section " << symbol << "\n";
    ss << symbol << ":\n";
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }
    std::string str = ss.str();

    ss.str(std::string());
    ss << symbol << ".asm";
    std::string fileName = ss.str();

    return luaWriteFile(L, fileName.c_str(), str.data(), str.length());
}

const luaL_Reg LuaGfx[] = {
    { "gfxLoad", luaGfxLoad },
    { "gfxWriteBTile16", luaGfxWriteBTile16 },
    { nullptr, nullptr }
};

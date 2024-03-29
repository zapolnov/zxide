#include "LuaMap.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/MapFile.h"
#include "compiler/MapData.h"
#include <string>
#include <sstream>
#include <lua.hpp>

namespace
{
    struct MapObject
    {
        QString tilesetFile;
        MapData data{0, 0};
    };
}

static int luaMapLoad(lua_State* L)
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

    MapFile mapFile(file.readAll());
    file.close();

    MapObject* obj = vm->pushNew<MapObject>();
    if (!mapFile.deserializeFromJson(&obj->data)) {
        QString error = mapFile.lastError();
        return luaL_error(L, "unable to load file '%s': %s", fileName, error.toUtf8().constData());
    }

    obj->tilesetFile = mapFile.tileSetFile;

    return 1;
}

static int luaMapGetSize(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    MapObject& obj = vm->check<MapObject>(1);
    lua_pushinteger(L, obj.data.width());
    lua_pushinteger(L, obj.data.height());
    return 2;
}

static int luaMapGetTilesetFile(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    MapObject& obj = vm->check<MapObject>(1);
    vm->pushString(obj.tilesetFile);
    return 1;
}

static int luaMapGetTileAt(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    MapObject& obj = vm->check<MapObject>(1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    if (x < 0 || x >= obj.data.width())
        return luaL_error(L, "x coordinate is out of range.");
    if (y < 0 || y >= obj.data.height())
        return luaL_error(L, "y coordinate is out of range.");

    lua_pushinteger(L, obj.data.at(x, y));
    return 1;
}

static int luaMapGetEntityAt(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    MapObject& obj = vm->check<MapObject>(1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    if (x < 0 || x >= obj.data.width())
        return luaL_error(L, "x coordinate is out of range.");
    if (y < 0 || y >= obj.data.height())
        return luaL_error(L, "y coordinate is out of range.");

    vm->pushString(obj.data.entityAt(x, y));
    return 1;
}

static int luaMapWriteByteArray(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    MapObject& obj = vm->check<MapObject>(1);
    const char* symbol = luaL_checkstring(L, 2);

    MapFile file;
    file.tileSetFile = obj.tilesetFile;
    file.serializeToByteArray(&obj.data);

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

const luaL_Reg LuaMap[] = {
    { "mapLoad", luaMapLoad },
    { "mapGetSize", luaMapGetSize },
    { "mapGetTilesetFile", luaMapGetTilesetFile },
    { "mapGetTileAt", luaMapGetTileAt },
    { "mapGetEntityAt", luaMapGetEntityAt },
    { "mapWriteByteArray", luaMapWriteByteArray },
    { nullptr, nullptr }
};

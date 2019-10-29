#include "LuaGfx.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/GfxFile.h"
#include "compiler/GfxData.h"
#include <string>
#include <sstream>
#include <lua.hpp>

int luaGfxLoad(lua_State* L)
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

static int luaGfxGetDimensions(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    lua_pushinteger(L, data.width());
    lua_pushinteger(L, data.height());
    return 2;
}

static int luaGfxGetFragment(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    GfxData& data = vm->check<GfxData>(1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    int w = luaL_checkinteger(L, 4);
    int h = luaL_checkinteger(L, 5);

    if (w < 0)
        return luaL_error(L, "invalid width.");
    if (h < 0)
        return luaL_error(L, "invalid height.");

    QByteArray pixels = data.bytes(x, y, x + w - 1, y + h - 1);
    QByteArray attrib = data.attrib(x, y, x + w - 1, y + h - 1);

    GfxData* newData = vm->pushNew<GfxData>(w, h);
    newData->setBytes(x, y, w, h, pixels);
    newData->setAttrib(x, y, w, h, attrib);

    return 1;
}

static std::string generateMonochrome(const GfxData& data)
{
    GfxFile file;
    file.serializeToMonochrome(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static std::string generateStandard(const GfxData& data)
{
    GfxFile file;
    file.serializeToStandard(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static std::string generateStandardAttributes(const GfxData& data)
{
    GfxFile file;
    file.serializeToStandardAttributes(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static std::string generateZigZag(const GfxData& data)
{
    GfxFile file;
    file.serializeToZigZag(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static std::string generateBTile16(const GfxData& data)
{
    GfxFile file;
    file.serializeToBTile16(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static std::string generateBTile16Attributes(const GfxData& data)
{
    GfxFile file;
    file.serializeToBTile16Attributes(&data);

    std::stringstream ss;
    for (char ch : file.data()) {
        char buf[32];
        snprintf(buf, sizeof(buf), "db 0x%02X\n", static_cast<unsigned char>(ch));
        ss << buf;
    }

    return ss.str();
}

static int luaGfxGenerateMonochromeAssembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateMonochrome(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxGenerateStandardAssembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateStandard(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxGenerateStandardAttributesAssembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateStandardAttributes(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxGenerateZigZagAssembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateZigZag(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxGenerateBTile16Assembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateBTile16(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxGenerateBTile16AttributesAssembly(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    GfxData& data = vm->check<GfxData>(1);
    std::string result = generateBTile16Attributes(data);
    vm->pushString(result);
    return 1;
}

static int luaGfxWriteMonochrome(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    GfxData& data = vm->check<GfxData>(1);
    const char* symbol = luaL_checkstring(L, 2);

    std::stringstream ss;
    ss << "; THIS FILE HAS BEEN AUTOMATICALLY GENERATED\n";
    ss << "section " << symbol << "\n";
    ss << symbol << ":\n";
    ss << generateMonochrome(data);
    std::string str = ss.str();

    ss.str(std::string());
    ss << symbol << ".asm";
    std::string fileName = ss.str();

    return luaWriteFile(L, fileName.c_str(), str.data(), str.length());
}

static int luaGfxWriteBTile16(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    GfxData& data = vm->check<GfxData>(1);
    const char* symbol = luaL_checkstring(L, 2);

    std::stringstream ss;
    ss << "; THIS FILE HAS BEEN AUTOMATICALLY GENERATED\n";
    ss << "section " << symbol << "\n";
    ss << symbol << ":\n";
    ss << generateBTile16(data);
    std::string str = ss.str();

    ss.str(std::string());
    ss << symbol << ".asm";
    std::string fileName = ss.str();

    return luaWriteFile(L, fileName.c_str(), str.data(), str.length());
}

static int luaGfxWriteBTile16Attributes(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    GfxData& data = vm->check<GfxData>(1);
    const char* symbol = luaL_checkstring(L, 2);

    std::stringstream ss;
    ss << "; THIS FILE HAS BEEN AUTOMATICALLY GENERATED\n";
    ss << "section " << symbol << "\n";
    ss << symbol << ":\n";
    ss << generateBTile16Attributes(data);
    std::string str = ss.str();

    ss.str(std::string());
    ss << symbol << ".asm";
    std::string fileName = ss.str();

    return luaWriteFile(L, fileName.c_str(), str.data(), str.length());
}

const luaL_Reg LuaGfx[] = {
    { "gfxLoad", luaGfxLoad },
    { "gfxGetDimensions", luaGfxGetDimensions },
    { "gfxGetFragment", luaGfxGetFragment },
    { "gfxGenerateMonochromeAssembly", luaGfxGenerateMonochromeAssembly },
    { "gfxGenerateStandardAssembly", luaGfxGenerateStandardAssembly },
    { "gfxGenerateStandardAttributesAssembly", luaGfxGenerateStandardAttributesAssembly },
    { "gfxGenerateZigZagAssembly", luaGfxGenerateZigZagAssembly },
    { "gfxGenerateBTile16Assembly", luaGfxGenerateBTile16Assembly },
    { "gfxGenerateBTile16AttributesAssembly", luaGfxGenerateBTile16AttributesAssembly },
    { "gfxWriteMonochrome", luaGfxWriteMonochrome },
    { "gfxWriteBTile16", luaGfxWriteBTile16 },
    { "gfxWriteBTile16Attributes", luaGfxWriteBTile16Attributes },
    { nullptr, nullptr }
};

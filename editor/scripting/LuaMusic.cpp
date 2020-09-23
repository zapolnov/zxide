#include "LuaMusic.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/MusicCompiler.h"
#include "compiler/IO.h"
#include <string>
#include <sstream>
#include <lua.hpp>

static int luaMusicProcess(lua_State* L)
{
    /*
    LuaVM* vm = LuaVM::fromLua(L);

    const char* fileName = luaL_checkstring(L, 1);
    const QDir& dir = vm->projectDirectory();
    QString filePath = dir.absoluteFilePath(QString::fromUtf8(fileName));

    auto compiler = std::make_unique<MusicCompiler>();

    QByteArray data = loadFile(filePath);
    unsigned char* p = reinterpret_cast<unsigned char*>(data.data());
    unsigned long size = data.size();

    auto musicHandle = ay_initsongindirect(p, 44100, size, nullptr);
    if (!musicHandle)
        return luaL_error(L, "ay_initsongindirect() failed.");
    compiler->open_ay_dump(musicHandle);
    ay_closesong(&musicHandle);

    compiler->compile();
    if (!compiler->calctbl())
        return luaL_error(L, "song can't be compiled -- too many variants.");
    std::string code = compiler->save();

    lua_pushlstring(L, code.data(), int(code.size()));
    return 1;
    */
    return luaL_error(L, "not implemented.");
}

const luaL_Reg LuaMusic[] = {
    { "musicProcess", luaMusicProcess },
    { nullptr, nullptr }
};

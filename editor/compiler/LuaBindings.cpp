#include "LuaBindings.h"
#include "compiler/Compiler.h"
#include "scripting/LuaVM.h"
#include <lua.hpp>

char LuaBindings_CompilerKey;

static Compiler* getCompiler(lua_State* L)
{
    lua_rawgetp(L, LUA_REGISTRYINDEX, &LuaBindings_CompilerKey);
    auto compiler = reinterpret_cast<Compiler*>(lua_touserdata(L, -1));
    lua_pop(L, 1);
    return compiler;
}

static int pushFileList(lua_State* L, const std::vector<std::unique_ptr<SourceFile>>& files)
{
    LuaVM* vm = LuaVM::fromLua(L);

    int i = 0;
    lua_createtable(L, int(files.size()), 0);
    for (const auto& file : files) {
        vm->pushString(file->name);
        lua_rawseti(L, -2, ++i);
    }

    return 1;
}

static int luaCompilerGetBasicSources(lua_State* L)
{
    return pushFileList(L, getCompiler(L)->basicSources());
}

static int luaCompilerGetAssemblerSources(lua_State* L)
{
    return pushFileList(L, getCompiler(L)->assemblerSources());
}

static int luaCompilerGetMaps(lua_State* L)
{
    return pushFileList(L, getCompiler(L)->maps());
}

static int luaCompilerGetBuildScripts(lua_State* L)
{
    return pushFileList(L, getCompiler(L)->buildScripts());
}

const luaL_Reg LuaBindings[] = {
    { "compilerGetBasicSources", luaCompilerGetBasicSources },
    { "compilerGetAssemblerSources", luaCompilerGetAssemblerSources },
    { "compilerGetMaps", luaCompilerGetMaps },
    { "compilerGetBuildScripts", luaCompilerGetBuildScripts },
    { nullptr, nullptr }
};

#ifndef SCRIPTING_LUAFILES_H
#define SCRIPTING_LUAFILES_H

#include <cstddef>

struct lua_State;
struct luaL_Reg;

extern const luaL_Reg LuaFiles[];

int luaWriteFile(lua_State* L, const char* fileName, const void* contents, size_t contentsLength);

#endif

#ifndef SCRIPTING_LUAFILES_H
#define SCRIPTING_LUAFILES_H

#include <cstddef>

struct lua_State;
struct luaL_Reg;

extern const luaL_Reg LuaFiles[];

int luaReadFile(lua_State* L, const char* name);
int luaReadCsvFile(lua_State* L, const char* name);
int luaWriteFile(lua_State* L, const char* name, const void* contents, size_t contentsLength);

#endif

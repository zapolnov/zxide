#ifndef SCRIPTING_LUAGFX_H
#define SCRIPTING_LUAGFX_H

struct luaL_Reg;
struct lua_State;

extern const luaL_Reg LuaGfx[];

int luaGfxLoad(lua_State* L);

#endif

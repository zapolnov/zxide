#include "LuaUtil.h"
#include "LuaVM.h"
#include "compiler/Assembler.h"
#include "compiler/Util.h"
#include <QFileInfo>
#include <lua.hpp>
#include <sstream>

extern "C" {
#include <md5.h>
}

static void md5Final(lua_State* L, MD5_CTX* ctx)
{
    unsigned char buf[16];
    MD5_Final(buf, ctx);

    static const char hex[] = "0123456789abcdef";
    char md5[32];
    for (int i = 0; i < 16; i++) {
        md5[i * 2 + 0] = hex[buf[i] >> 4];
        md5[i * 2 + 1] = hex[buf[i] & 15];
    }

    lua_pushlstring(L, md5, 32);
}

static int luaMd5(lua_State* L)
{
    size_t length = 0;
    const char* data = luaL_checklstring(L, 1, &length);

    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, static_cast<unsigned long>(length));
    md5Final(L, &ctx);

    return 1;
}

static int luaMd5Init(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    MD5_CTX* ctx = vm->pushNewNoDestructor<MD5_CTX>();
    MD5_Init(ctx);

    return 1;
}

static int luaMd5Update(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    MD5_CTX& ctx = vm->check<MD5_CTX>(1);

    size_t length = 0;
    const char* data = luaL_checklstring(L, 2, &length);
    MD5_Update(&ctx, data, static_cast<unsigned long>(length));

    return 0;
}

static int luaMd5Final(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);
    MD5_CTX& ctx = vm->check<MD5_CTX>(1);

    md5Final(L, &ctx);
    return 1;
}

static int pushIdentifierFromString(lua_State* L, const QString& str)
{
    LuaVM::fromLua(L)->pushString(identifierFromString(str));
    return 1;
}

static int luaMakeValidIdentifier(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);
    return pushIdentifierFromString(L, QString::fromUtf8(name));
}

static int luaMakeValidIdentifierFromFileName(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);
    QFileInfo info(QString::fromUtf8(name));
    return pushIdentifierFromString(L, info.completeBaseName());
}

static int luaDontObfuscate(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);
    dontObfuscate(name);
    return 0;
}

const luaL_Reg LuaUtil[] = {
    { "md5", luaMd5 },
    { "md5Init", luaMd5Init },
    { "md5Update", luaMd5Update },
    { "md5Final", luaMd5Final },
    { "makeValidIdentifier", luaMakeValidIdentifier },
    { "makeValidIdentifierFromFileName", luaMakeValidIdentifierFromFileName },
    { "dontObfuscate", luaDontObfuscate },
    { nullptr, nullptr }
};

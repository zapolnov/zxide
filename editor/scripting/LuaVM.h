#ifndef SCRIPTING_LUAVM_H
#define SCRIPTING_LUAVM_H

#include <QString>
#include <QStringList>
#include <QDir>
#include <lua.hpp>
#include <new>
#include <type_traits>
#include <typeinfo>

class LuaError
{
public:
    LuaError(const QString& message, int line) : mMessage(message), mLine(line) {}

    const QString& message() const { return mMessage; }
    int line() const { return mLine; }

private:
    QString mMessage;
    int mLine;
};

class LuaVM
{
public:
    LuaVM();
    ~LuaVM();

    static LuaVM* fromLua(lua_State* L);
    operator lua_State*() const { return mLua; }

    void openLibs();
    void openLib(const char* name, lua_CFunction func);
    void openLib(const luaL_Reg* funcs);

    const QDir& generatedFilesDirectory() const;
    void setGeneratedFilesDirectory(const QDir& dir);

    const QStringList& generatedFiles() const { return mGeneratedFiles; }
    void addGeneratedFile(const QString& file) { mGeneratedFiles << file; }

    void runScript(const QString& file);

    template <typename T> T& check(int index)
    {
        return *reinterpret_cast<T*>(luaL_checkudata(mLua, index, typeid(T).name()));
    }

    template <typename T> void push(T&& value)
    {
        using Type = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
        void* ptr = lua_newuserdata(mLua, sizeof(Type));

        luaL_getmetatable(mLua, typeid(Type).name());
        if (!lua_istable(mLua, -1)) {
            lua_pop(mLua, 1);
            luaL_newmetatable(mLua, typeid(Type).name());
            lua_pushliteral(mLua, "__gc");
            lua_pushcclosure(mLua, [](lua_State* L) {
                    return (reinterpret_cast<Type*>(lua_touserdata(L, 1))->~Type()), 0;
                }, 0);
            lua_rawset(mLua, -3);
        }

        new(ptr) Type(std::forward<T>(value));
        lua_setmetatable(mLua, -2);
    }

private:
    lua_State* mLua;
    QDir mGeneratedFilesDirectory;
    QStringList mGeneratedFiles;

    Q_DISABLE_COPY(LuaVM)
};

#endif

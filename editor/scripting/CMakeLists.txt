
add_library(Scripting STATIC)
set_target_properties(Scripting PROPERTIES FOLDER "Compiler")
target_link_libraries(Scripting Lua Md5 Compiler LibAyFly)
qt_link_libraries(Scripting Core Gui Widgets)

qt_add_sources(Scripting
        LuaFiles.cpp
        LuaFiles.h
        LuaGfx.cpp
        LuaGfx.h
        LuaMap.cpp
        LuaMap.h
        LuaMusic.cpp
        LuaMusic.h
        LuaTileSet.cpp
        LuaTileSet.h
        LuaUtil.cpp
        LuaUtil.h
        LuaVM.cpp
        LuaVM.h
    )

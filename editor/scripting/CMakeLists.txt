
add_library(Scripting STATIC)
set_target_properties(Scripting PROPERTIES FOLDER "Compiler")
target_link_libraries(Scripting Lua Compiler)
qt_link_libraries(Scripting Core)

qt_add_sources(Scripting
        LuaFiles.cpp
        LuaFiles.h
        LuaGfx.cpp
        LuaGfx.h
        LuaVM.cpp
        LuaVM.h
    )

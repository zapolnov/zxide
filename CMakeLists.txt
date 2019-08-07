
cmake_minimum_required(VERSION 3.10)
project(Game)

include(cmake/Macros.cmake)
include(cmake/Qt.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

if(MSVC)
    add_definitions(
        -D_CRT_SECURE_NO_DEPRECATE=1
        -D_CRT_SECURE_NO_WARNINGS=1
        -D_CRT_NONSTDC_NO_DEPRECATE=1
        -D_SCL_SECURE_NO_WARNINGS=1
        )
endif()

set(GAME_NAME "Cool Game")
set(GAME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/game")

mingw_install_libraries()

add_subdirectory(editor)

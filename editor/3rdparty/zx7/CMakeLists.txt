
add_library(Zx7 STATIC ${src})
set_target_properties(Zx7 PROPERTIES FOLDER "ThirdParty")
target_include_directories(Zx7 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_sources(Zx7
    src/compress.c
    src/optimize.c
    src/zx7.h
    )

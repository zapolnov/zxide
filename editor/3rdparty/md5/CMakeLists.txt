
add_library(Md5 STATIC ${src})
set_target_properties(Md5 PROPERTIES FOLDER "ThirdParty")
target_include_directories(Md5 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_sources(Md5
    md5.c
    md5.h
    )

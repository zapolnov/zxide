
add_library(Bas2Tap STATIC ${src})
target_include_directories(Bas2Tap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(Bas2Tap PROPERTIES FOLDER "ThirdParty")

add_sources(Bas2Tap
    bas2tap.c
    bas2tap.h
    )

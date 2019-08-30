
add_library(Tape2Wav STATIC)
set_target_properties(Tape2Wav PROPERTIES FOLDER "ThirdParty")
target_link_libraries(Tape2Wav LibSpectrum)

if(WIN32)
    add_definitions(-DWIN32)
endif()

add_sources(Tape2Wav
    compat.h
    tape2wav.c
    #utils.c
    utils.h
    )

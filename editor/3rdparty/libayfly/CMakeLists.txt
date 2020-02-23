
if(MSVC)
    add_definitions(/wd4305)    # truncation from double to float
endif()

add_library(LibAyFly STATIC)
target_compile_definitions(LibAyFly PUBLIC AYFLY_STATIC)
set_target_properties(LibAyFly PROPERTIES FOLDER "ThirdParty" OUTPUT_NAME "AyFly")

target_include_directories(LibAyFly PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/libayfly"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/libayfly/z80ex/include"
    )

add_sources(LibAyFly
    src/libayfly/players/ASCPlay.h
    src/libayfly/players/AYPlay.h
    src/libayfly/players/PSCPlay.h
    src/libayfly/players/PSGPlay.h
    src/libayfly/players/PT1Play.h
    src/libayfly/players/PT2Play.h
    src/libayfly/players/PT3Play.h
    src/libayfly/players/SQTPlay.h
    src/libayfly/players/STCPlay.h
    src/libayfly/players/STPPlay.h
    src/libayfly/players/VTXPlay.h
    src/libayfly/players/YMPlay.h
    #src/libayfly/s60/ayfly_s602ndAudio.cpp
    #src/libayfly/s60/ayfly_s602ndAudio.h
    #src/libayfly/s60/ayfly_s60Audio.cpp
    #src/libayfly/s60/ayfly_s60Audio.h
    #src/libayfly/unix/SDLAudio.cpp
    #src/libayfly/unix/SDLAudio.h
    #src/libayfly/windows/DXAudio.cpp
    #src/libayfly/windows/DXAudio.h
    #src/libayfly/windows/WaveAudio.cpp
    #src/libayfly/windows/WaveAudio.h
    src/libayfly/z80ex/include/z80ex.h
    src/libayfly/z80ex/include/z80ex_common.h
    src/libayfly/z80ex/opcodes/opcodes_base.c
    src/libayfly/z80ex/opcodes/opcodes_cb.c
    src/libayfly/z80ex/opcodes/opcodes_dasm.c
    src/libayfly/z80ex/opcodes/opcodes_dd.c
    src/libayfly/z80ex/opcodes/opcodes_ddcb.c
    src/libayfly/z80ex/opcodes/opcodes_ed.c
    src/libayfly/z80ex/opcodes/opcodes_fd.c
    src/libayfly/z80ex/opcodes/opcodes_fdcb.c
    src/libayfly/z80ex/macros.h
    src/libayfly/z80ex/ptables.c
    src/libayfly/z80ex/typedefs.h
    src/libayfly/z80ex/z80ex.c
    src/libayfly/AbstractAudio.cpp
    src/libayfly/AbstractAudio.h
    src/libayfly/ay.cpp
    src/libayfly/ay.h
    src/libayfly/ayfly.h
    src/libayfly/ayflyString.cpp
    src/libayfly/ayflyString.h
    #src/libayfly/ay_s60.cpp
    #src/libayfly/ay_s60.h
    src/libayfly/common.cpp
    src/libayfly/Filter3.cpp
    src/libayfly/Filter3.h
    src/libayfly/formats.cpp
    src/libayfly/lha.cpp
    src/libayfly/speccy.cpp
    src/libayfly/z80ex
    )

set_source_files_properties(
    src/libayfly/z80ex/opcodes/opcodes_base.c
    src/libayfly/z80ex/opcodes/opcodes_cb.c
    src/libayfly/z80ex/opcodes/opcodes_dasm.c
    src/libayfly/z80ex/opcodes/opcodes_dd.c
    src/libayfly/z80ex/opcodes/opcodes_ddcb.c
    src/libayfly/z80ex/opcodes/opcodes_ed.c
    src/libayfly/z80ex/opcodes/opcodes_fd.c
    src/libayfly/z80ex/opcodes/opcodes_fdcb.c
    src/libayfly/z80ex/ptables.c
    PROPERTIES HEADER_FILE_ONLY TRUE)

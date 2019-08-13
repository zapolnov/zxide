
include(CheckIncludeFile)
include(CheckCSourceCompiles)
include(CheckFunctionExists)
include(TestBigEndian)

test_big_endian(WORDS_BIGENDIAN)
check_include_file("libgen.h" HAVE_LIBGEN_H)
check_include_file("io.h" HAVE_IO_H)
check_include_file("unistd.h" HAVE_UNISTD_H)
check_include_file("strings.h" HAVE_STRINGS_H)
check_c_source_compiles("
    #include <strings.h>
    int main() {
        return strcasecmp(\"a\", \"b\");
    }" HAVE_STRINGS_STRCASECMP)

include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_definitions(-DHAVE_CONFIG_H)

if(NOT HAVE_UNISTD_H)
    add_definitions(-DYY_NO_UNISTD_H)
endif()

if(WIN32)
    add_definitions(-Dssize_t=ptrdiff_t -Dstrcasecmp=stricmp)
endif()

configure_file(roms/48.rom "${CMAKE_BINARY_DIR}/roms/48.rom" COPYONLY)

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

add_library(Fuse STATIC "${config_h}")
set_target_properties(Fuse PROPERTIES FOLDER "ThirdParty")
target_include_directories(Fuse PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Fuse LibSpectrum)

add_sources(Fuse
    debugger/breakpoint.c
    debugger/breakpoint.h
    debugger/command.c
    debugger/commandl.c
    debugger/commandy.c
    debugger/commandy.h
    debugger/debugger.c
    debugger/debugger.h
    debugger/debugger_internals.h
    debugger/disassemble.c
    debugger/event.c
    debugger/expression.c
    debugger/system_variable.c
    debugger/variable.c
    infrastructure/startup_manager.c
    infrastructure/startup_manager.h
    machines/machines.h
    machines/machines_periph.c
    machines/machines_periph.h
    machines/pentagon.c
    machines/pentagon.h
    machines/pentagon1024.c
    machines/pentagon512.c
    machines/scorpion.c
    machines/scorpion.h
    machines/spec128.c
    machines/spec128.h
    machines/spec16.c
    machines/spec48.c
    machines/spec48.h
    machines/spec48_ntsc.c
    machines/spec_se.c
    machines/specplus2.c
    machines/specplus2a.c
    machines/specplus3.c
    machines/specplus3.h
    machines/specplus3e.c
    machines/tc2048.c
    machines/tc2068.c
    machines/tc2068.h
    machines/ts2068.c
    peripherals/disk/beta.c
    peripherals/disk/beta.h
    peripherals/disk/crc.c
    peripherals/disk/crc.h
    peripherals/disk/didaktik.c
    peripherals/disk/didaktik.h
    peripherals/disk/disciple.c
    peripherals/disk/disciple.h
    peripherals/disk/disk.c
    peripherals/disk/disk.h
    peripherals/disk/fdd.c
    peripherals/disk/fdd.h
    peripherals/disk/opus.c
    peripherals/disk/opus.h
    peripherals/disk/plusd.c
    peripherals/disk/plusd.h
    peripherals/disk/trdos.c
    peripherals/disk/trdos.h
    peripherals/disk/upd_fdc.c
    peripherals/disk/upd_fdc.h
    peripherals/disk/wd_fdc.c
    peripherals/disk/wd_fdc.h
    peripherals/flash/am29f010.c
    peripherals/flash/am29f010.h
    peripherals/ide/divide.c
    peripherals/ide/divide.h
    peripherals/ide/divmmc.c
    peripherals/ide/divmmc.h
    peripherals/ide/divxxx.c
    peripherals/ide/divxxx.h
    peripherals/ide/ide.c
    peripherals/ide/ide.h
    peripherals/ide/simpleide.c
    peripherals/ide/simpleide.h
    peripherals/ide/zxatasp.c
    peripherals/ide/zxatasp.h
    peripherals/ide/zxcf.c
    peripherals/ide/zxcf.h
    peripherals/ide/zxmmc.c
    peripherals/ide/zxmmc.h
    peripherals/nic/enc28j60.c
    peripherals/nic/enc28j60.h
    peripherals/nic/w5100.c
    peripherals/nic/w5100.h
    peripherals/nic/w5100_internals.h
    peripherals/nic/w5100_socket.c
    peripherals/ay.c
    peripherals/ay.h
    peripherals/covox.c
    peripherals/covox.h
    peripherals/dck.c
    peripherals/dck.h
    peripherals/fuller.c
    peripherals/fuller.h
    peripherals/if1.c
    peripherals/if1.h
    peripherals/if2.c
    peripherals/if2.h
    peripherals/joystick.c
    peripherals/joystick.h
    peripherals/kempmouse.c
    peripherals/kempmouse.h
    peripherals/melodik.c
    peripherals/melodik.h
    peripherals/multiface.c
    peripherals/multiface.h
    peripherals/printer.c
    peripherals/printer.h
    peripherals/scld.c
    peripherals/scld.h
    peripherals/speccyboot.c
    peripherals/speccyboot.h
    peripherals/specdrum.c
    peripherals/specdrum.h
    peripherals/spectranet.c
    peripherals/spectranet.h
    peripherals/ula.c
    peripherals/ula.h
    peripherals/usource.c
    peripherals/usource.h
    pokefinder/pokefinder.c
    pokefinder/pokefinder.h
    pokefinder/pokemem.c
    pokefinder/pokemem.h
    sound/blipbuffer.c
    sound/blipbuffer.h
    sound/coreaudiosound.c
    sound/dxsound.c
    sound/nullsound.c
    sound/sfifo.c
    sound/sfifo.h
    timer/timer.c
    timer/timer.h
    ui/null/null_ui.c
    ui/null/options.c
    ui/scaler/scaler.c
    ui/scaler/scaler.h
    ui/scaler/scaler_hq2x.c
    ui/scaler/scaler_hq3x.c
    ui/scaler/scaler_internals.h
    ui/scaler/scalers.c
    ui/scaler/scalers16.c
    ui/scaler/scalers32.c
    ui/ui.h
    ui/uidisplay.h
    ui/uijoystick.h
    ui/uimedia.h
    z80/opcodes_base.c
    z80/z80.c
    z80/z80.h
    z80/z80_cb.c
    z80/z80_checks.h
    z80/z80_ddfd.c
    z80/z80_ddfdcb.c
    z80/z80_debugger_variables.c
    z80/z80_ed.c
    z80/z80_internals.h
    z80/z80_macros.h
    z80/z80_ops.c
    bitmap.h
    compat.h
    display.c
    display.h
    event.c
    event.h
    fuse.c
    fuse.h
    input.c
    input.h
    keyboard.c
    keyboard.h
    loader.c
    loader.h
    machine.c
    machine.h
    memory_pages.c
    memory_pages.h
    mempool.c
    mempool.h
    #menu.c
    menu.h
    module.c
    module.h
    movie.c
    movie.h
    movie_tables.h
    options.h
    periph.c
    periph.h
    phantom_typist.c
    phantom_typist.h
    profile.c
    profile.h
    psg.c
    psg.h
    rectangle.c
    rectangle.h
    rzx.c
    rzx.h
    screenshot.c
    screenshot.h
    settings.c
    settings.h
    slt.c
    slt.h
    snapshot.c
    snapshot.h
    sound.c
    sound.h
    spectrum.c
    spectrum.h
    svg.c
    svg.h
    tape.c
    tape.h
    ui.c
    uidisplay.c
    uimedia.c
    utils.c
    utils.h
    )

set_source_files_properties(
    ui/scaler/scaler_hq2x.c
    ui/scaler/scaler_hq3x.c
    ui/scaler/scalers.c
    z80/opcodes_base.c
    z80/z80_cb.c
    z80/z80_ddfd.c
    z80/z80_ddfdcb.c
    z80/z80_ed.c
    PROPERTIES HEADER_FILE_ONLY TRUE
    )

if(WIN32)
    target_link_libraries(Fuse ws2_32 dxguid)
    set_source_files_properties(
        sound/coreaudiosound.c
        #sound/dxsound.c
        sound/nullsound.c
        PROPERTIES HEADER_FILE_ONLY TRUE)
elseif(APPLE)
    find_library(AudioToolbox AudioToolbox)
    find_library(CoreAudio CoreAudio)
    target_link_libraries(Fuse ${AudioToolbox} ${CoreAudio})
    set_source_files_properties(
        #sound/coreaudiosound.c
        sound/dxsound.c
        sound/nullsound.c
        PROPERTIES HEADER_FILE_ONLY TRUE)
endif()

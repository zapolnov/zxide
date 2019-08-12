
include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckCSourceCompiles)
include(TestBigEndian)

test_big_endian(WORDS_BIGENDIAN)
check_include_file("stdatomic.h" HAVE_STDATOMIC_H)
check_include_file("strings.h" HAVE_STRINGS_H)
check_include_file("unistd.h" HAVE_UNISTD_H)
check_function_exists("strcasecmp" HAVE_STRCASECMP)
check_function_exists("strncasecmp" HAVE_STRNCASECMP)
check_function_exists("_stricmp" HAVE__STRICMP)
check_function_exists("_strnicmp" HAVE__STRNICMP)

check_c_source_compiles("
    #include <stdio.h>
    int main() {
        char buf[256];
        return snprintf(buf, sizeof(buf), \"%d\", 4);
    }" HAVE_SNPRINTF)

check_c_source_compiles("
    #include <stdio.h>
    int main() {
        char buf[256];
        return _snprintf(buf, sizeof(buf), \"%d\", 4);
    }" HAVE__SNPRINTF)

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

add_library(LibSpectrum STATIC ${src_myglib} ${src} "${config_h}")
target_include_directories(LibSpectrum PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(LibSpectrum ZLib LibBZ2 LibAudioFile)
set_target_properties(LibSpectrum PROPERTIES FOLDER "ThirdParty" OUTPUT_NAME "Spectrum")

if(NOT HAVE_STDATOMIC_H)
    set_source_files_properties(myglib/glock.c PROPERTIES HEADER_FILE_ONLY TRUE)
endif()

add_sources(LibSpectrum
    myglib/garray.c
    myglib/ghash.c
    myglib/glock.c
    myglib/gslist.c
    buffer.c
    bzip2.c
    config.h.in
    creator.c
    csw.c
    dck.c
    ide.c
    internals.h
    libspectrum.c
    libspectrum.h
    memory.c
    microdrive.c
    mmc.c
    plusd.c
    pzx_read.c
    rzx.c
    sna.c
    snap_accessors.c
    snapshot.c
    snp.c
    sp.c
    symbol_table.c
    szx.c
    tap.c
    tape.c
    tape_accessors.c
    tape_block.c
    tape_block.h
    tape_set.c
    timings.c
    tzx_read.c
    tzx_write.c
    utilities.c
    warajevo_read.c
    wav.c
    z80.c
    z80em.c
    zip.c
    zip.h
    zlib.c
    zxs.c
    )

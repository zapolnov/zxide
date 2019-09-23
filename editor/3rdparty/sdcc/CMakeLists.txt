
if(MSVC)
    add_definitions(/wd4047 /wd4090 /wd4101 /wd4116 /wd4146 /wd4244 /wd4267 /wd4273)
else()
    add_definitions(-Wno-logical-op-parentheses -Wno-parentheses)
endif()

include(TestBigEndian)
include(CheckTypeSize)
include(CheckCSourceCompiles)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckFunctionExists)

test_big_endian(WORDS_BIGENDIAN)

check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)

check_include_file("unistd.h" HAVE_UNISTD_H)
check_include_file("strings.h" HAVE_STRINGS_H)
check_include_file("stdio_ext.h" HAVE_STDIO_EXT_H)
check_include_file("malloc.h" HAVE_MALLOC_H)
check_include_file("fcntl.h" HAVE_FCNTL_H)
check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)
check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("sys/file.h" HAVE_SYS_FILE_H)
check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_file("sys/mman.h" HAVE_SYS_MMAN_H)
check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)
check_include_file("sys/times.h" HAVE_SYS_TIMES_H)
check_include_file("io.h" HAVE_IO_H)
check_include_file("direct.h" HAVE_DIRECT_H)

check_function_exists("getcwd" HAVE_GETCWD)
#check_function_exists("sbrk" HAVE_SBRK)
check_function_exists("__fsetlocking" HAVE___FSETLOCKING)
check_function_exists("kill" HAVE_KILL)
check_function_exists("strsignal" HAVE_STRSIGNAL)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <string.h>
    int main() { char* p = basename(\"\"); (void)p; return 0; }
    " HAVE_DECL_BASENAME)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <string.h>
    int main() { size_t l = strnlen(\"\", 1); (void)l; return 0; }
    " HAVE_DECL_STRNLEN)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <stdio.h>
    int main() { char* p; int x = asprintf(&p, \"\"); return x; }
    " HAVE_DECL_ASPRINTF)

#check_cxx_source_compiles("
#    #define _GNU_SOURCE
#    #include <unistd.h>
#    int main() { void* p = sbrk(0); (void)p; return 0; }
#    " HAVE_DECL_SBRK)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdarg.h>
    int f(const char* fmt, ...) {
        char* p; va_list args;
        va_start(args, fmt);
        int x = vasprintf(&p, fmt, args);
        va_end(args);
        return x; }
    int main() { return f(\"\"); }
    " HAVE_DECL_VASPRINTF)

check_c_source_compiles("
    #define _GNU_SOURCE
    #include <string.h>
    #include <strings.h>
    int main() { return 0; }
    " STRING_WITH_STRINGS)

check_c_source_compiles("
    #define _GNU_SOURCE
    #include <sys/time.h>
    #include <time.h>
    int main() { return 0; }
    " TIME_WITH_SYS_TIME)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <langinfo.h>
    int main() { const char* encoding = nl_langinfo(CODESET); (void)encoding; return 0; }
    " HAVE_LANGINFO_CODESET)

check_cxx_source_compiles("
    #define _GNU_SOURCE
    #include <sys/types.h>
    int main() { ssize_t x = 0; (void)x; return 0; }
    " HAVE_SSIZE_T)

######################################################################################################################
# zsdcpp

add_library(ZSdCPP STATIC)
set_target_properties(ZSdCPP PROPERTIES FOLDER "ThirdParty")

target_compile_definitions(ZSdCPP PRIVATE
    _GNU_SOURCE
    HAVE_CONFIG_H
    )

target_include_directories(ZSdCPP PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

target_include_directories(ZSdCPP PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/sdccp_generated"
    "${CMAKE_CURRENT_SOURCE_DIR}/support/cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/support/cpp/libcpp/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/support/cpp/libcpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/support/sdbinutils/include"
    )

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/sdccp_generated/generated_config.h")
configure_file("sdcppconfig.in.h" "${config_h}")

set(options_c "support/cpp/options.c")
set(options_h "support/cpp/options.h")

set(gen "${config_h}" "${options_c}" "${options_h}")
source_group("Generated Files" FILES ${gen})
target_sources(ZSdCPP PRIVATE ${gen})

if(WIN32)
    target_include_directories(ZSdCPP PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/support/cpp/win32"
        )
else()
    set_source_files_properties(
        "support/cpp/win32/dirent.c"
        PROPERTIES HEADER_FILE_ONLY TRUE
        )
endif()

add_sources(ZSdCPP
    support/cpp/libcpp/include/cpp-id-data.h
    support/cpp/libcpp/include/cpplib.h
    support/cpp/libcpp/include/line-map.h
    support/cpp/libcpp/include/mkdeps.h
    support/cpp/libcpp/include/symtab.h
    support/cpp/libcpp/charset.c
    support/cpp/libcpp/directives.c
    support/cpp/libcpp/errors.c
    support/cpp/libcpp/expr.c
    support/cpp/libcpp/files.c
    support/cpp/libcpp/identifiers.c
    support/cpp/libcpp/init.c
    support/cpp/libcpp/internal.h
    support/cpp/libcpp/lex.c
    support/cpp/libcpp/line-map.c
    support/cpp/libcpp/macro.c
    support/cpp/libcpp/mkdeps.c
    support/cpp/libcpp/symtab.c
    support/cpp/libcpp/system.h
    support/cpp/libcpp/traditional.c
    support/cpp/libcpp/ucnid.h
    support/cpp/win32/dirent.c
    support/cpp/win32/dirent.h
    support/cpp/c-incpath.c
    support/cpp/c-incpath.h
    support/cpp/c-ppoutput.c
    support/cpp/config.h
    support/cpp/cppdefault.c
    support/cpp/cppdefault.h
    support/cpp/hwint.h
    support/cpp/intl.h
    support/cpp/opts-common.c
    support/cpp/opts.c
    support/cpp/opts.h
    support/cpp/prefix.c
    support/cpp/prefix.h
    support/cpp/sdcpp-diagnostic.c
    support/cpp/sdcpp-opts.c
    support/cpp/sdcpp.c
    support/cpp/sdcpp.h
    support/cpp/system.h
    support/cpp/version.c
    support/cpp/version.h
    support/sdbinutils/include/ansidecl.h
    support/sdbinutils/include/filenames.h
    support/sdbinutils/include/hashtab.h
    support/sdbinutils/include/libiberty.h
    support/sdbinutils/include/md5.h
    support/sdbinutils/include/obstack.h
    support/sdbinutils/include/safe-ctype.h
    support/sdbinutils/libiberty/alloca.c
    support/sdbinutils/libiberty/concat.c
    support/sdbinutils/libiberty/fopen_unlocked.c
    support/sdbinutils/libiberty/getpwd.c
    support/sdbinutils/libiberty/hashtab.c
    support/sdbinutils/libiberty/hex.c
    support/sdbinutils/libiberty/lbasename.c
    support/sdbinutils/libiberty/md5.c
    support/sdbinutils/libiberty/obstack.c
    support/sdbinutils/libiberty/safe-ctype.c
    support/sdbinutils/libiberty/vasprintf.c
    support/sdbinutils/libiberty/vprintf-support.c
    support/sdbinutils/libiberty/vprintf-support.h
    support/sdbinutils/libiberty/xexit.c
    support/sdbinutils/libiberty/xmalloc.c
    support/sdbinutils/libiberty/xmemdup.c
    support/sdbinutils/libiberty/xstrdup.c
    support/sdbinutils/libiberty/xstrerror.c
    sdcc_bridge.c
    sdcc_bridge.h
    )

######################################################################################################################
# zsdcc

add_library(ZSdCC STATIC)
set_target_properties(ZSdCC PROPERTIES FOLDER "ThirdParty")

target_include_directories(ZSdCC PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

target_include_directories(ZSdCC PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/support/util"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/z80"
    "${CMAKE_CURRENT_BINARY_DIR}/sdcc_generated"
    "${CMAKE_CURRENT_SOURCE_DIR}/../boost"
    )

set(sdccconf_h "${CMAKE_CURRENT_BINARY_DIR}/sdcc_generated/sdccconf.h")
configure_file("sdccconf.in.h" "${sdccconf_h}")

set(sdcc_vc_h "${CMAKE_CURRENT_BINARY_DIR}/sdcc_generated/sdcc_vc.h")
if(NOT EXISTS "${sdcc_vc_h}")
    file(WRITE "${sdcc_vc_h}" "#include \"${CMAKE_CURRENT_BINARY_DIR}/sdcc_generated/sdccconf.h\"\n")
endif()

set(version_h "${CMAKE_CURRENT_BINARY_DIR}/sdcc_generated/version.h")
if(NOT EXISTS "${version_h}")
    file(WRITE "${version_h}" "#define SDCC_BUILD_NUMBER \"0\"\n")
endif()

set(SDCClex_c "${CMAKE_CURRENT_SOURCE_DIR}/src/SDCClex.c")
set(SDCCy_c "${CMAKE_CURRENT_SOURCE_DIR}/src/SDCCy.c")
set(SDCCy_h "${CMAKE_CURRENT_SOURCE_DIR}/src/SDCCy.h")

set(def
    "src/z80/peeph.def"
    "src/z80/peeph-z80.def"
    )

set(rul)
foreach(deffile ${def})
    string(REGEX REPLACE ".def$" ".rul" rulfile "${deffile}")
    set_source_files_properties("${deffile}" "{rulfile}" PROPERTIES HEADER_FILE_ONLY TRUE)
    source_group("Generated Files\\z80" FILES "${rulfile}")
    list(APPEND rul "${rulfile}")
endforeach()

set(gen "${version_h}" "${sdccconf_h}" "${sdcc_vc_h}" "${SDCClex_c}" "${SDCCy_c}" "${SDCCy_h}")
source_group("Generated Files" FILES ${gen})
target_sources(ZSdCC PRIVATE ${gen} ${rul})

if(WIN32)
    set_source_files_properties(
        "sdcc/support/util/findme.c"
        PROPERTIES HEADER_FILE_ONLY TRUE
        )
endif()

add_sources(ZSdCC
    sdccconf.in.h
    src/z80/gen.c
    src/z80/gen.h
    src/z80/main.c
    src/z80/mappings.i
    src/z80/peep.c
    src/z80/peep.h
    src/z80/peeph.def
    src/z80/peeph-z80.def
    src/z80/ralloc.c
    src/z80/ralloc.h
    src/z80/ralloc2.cc
    src/z80/support.c
    src/z80/support.h
    src/z80/z80.h
    src/cdbFile.c
    src/common.h
    src/port.h
    src/SDCC.lex
    src/SDCC.y
    src/SDCCargs.h
    src/SDCCasm.c
    src/SDCCasm.h
    src/SDCCast.c
    src/SDCCast.h
    src/SDCCBBlock.c
    src/SDCCBBlock.h
    src/SDCCbitv.c
    src/SDCCbitv.h
    src/SDCCbtree.cc
    src/SDCCbtree.h
    src/SDCCcflow.c
    src/SDCCcflow.h
    src/SDCCcse.c
    src/SDCCcse.h
    src/SDCCdebug.c
    src/SDCCdebug.h
    src/SDCCdflow.c
    src/SDCCdflow.h
    src/SDCCdwarf2.c
    src/SDCCdwarf2.h
    src/SDCCerr.c
    src/SDCCerr.h
    src/SDCCgen.c
    src/SDCCgen.h
    src/SDCCglobl.h
    src/SDCCglue.c
    src/SDCCglue.h
    src/SDCChasht.c
    src/SDCChasht.h
    src/SDCCicode.c
    src/SDCCicode.h
    src/SDCClabel.c
    src/SDCClabel.h
    src/SDCCloop.c
    src/SDCCloop.h
    src/SDCClospre.cc
    src/SDCClospre.hpp
    src/SDCClrange.c
    src/SDCClrange.h
    src/SDCCmacro.c
    src/SDCCmacro.h
    src/SDCCmain.c
    src/SDCCmem.c
    src/SDCCmem.h
    src/SDCCnaddr.cc
    src/SDCCnaddr.hpp
    src/SDCCopt.c
    src/SDCCopt.h
    src/SDCCpeeph.c
    src/SDCCpeeph.h
    src/SDCCptropt.c
    src/SDCCptropt.h
    src/SDCCralloc.hpp
    src/SDCCsalloc.hpp
    src/SDCCset.c
    src/SDCCset.h
    src/SDCCsymt.c
    src/SDCCsymt.h
    src/SDCCsystem.c
    src/SDCCsystem.h
    src/SDCCtree_dec.hpp
    src/SDCCutil.c
    src/SDCCutil.h
    src/SDCCval.c
    src/SDCCval.h
    src/SDCCy.h
    support/util/dbuf.c
    support/util/dbuf.h
    support/util/dbuf_string.c
    support/util/dbuf_string.h
    support/util/findme.c
    support/util/findme.h
    support/util/NewAlloc.c
    support/util/newalloc.h
    support/util/system.h
    sdcc_bridge.c
    sdcc_bridge.h
    )

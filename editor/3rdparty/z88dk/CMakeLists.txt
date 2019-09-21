
add_definitions(
    -Derror=copt_error
    )

add_library(COpt STATIC)
set_target_properties(COpt PROPERTIES FOLDER "ThirdParty")

target_include_directories(COpt PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/copt/regex"
    )

set_source_files_properties(
    src/copt/regex/engine.c
    PROPERTIES HEADER_FILE_ONLY TRUE
    )

add_sources(COpt
    src/copt/regex/cclass.h
    src/copt/regex/cname.h
    src/copt/regex/engine.c
    src/copt/regex/engine.h
    src/copt/regex/regcomp.c
    src/copt/regex/regcomp.h
    src/copt/regex/regerror.c
    src/copt/regex/regerror.h
    src/copt/regex/regex.h
    src/copt/regex/regex2.h
    src/copt/regex/regexec.c
    src/copt/regex/regfree.c
    src/copt/regex/utils.h
    src/copt/copt.c
    )

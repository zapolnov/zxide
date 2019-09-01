
if(MSVC)
    add_definitions(
        /wd4018         # signed/unsigned mismatch
        /wd4028         # formal parameter N different from declaration
        /wd4090         # 'function': different 'const' qualifiers
        /wd4101         # unreferenced local variable
        /wd4102         # unreferenced label
        /wd4146         # unary minus operator applied to unsigned type
        /wd4244         # conversion from 'type' to 'type', possible loss of data
        /wd4267         # conversion from 'type' to 'type', possible loss of data
        /wd4715         # not all control paths return a value
        /wd4716         # must return a value
        /wd4804         # unsafe use of type 'bool' in operation
        /wd4805         # unsafe mix of 'type' and 'bool' in operation
        )
    add_definitions(
        -D_WINSOCK_DEPRECATED_NO_WARNINGS
        )
else()
    add_definitions(
        -Wno-multichar
        )
endif()

add_subdirectory(bas2tap)
add_subdirectory(bzip2)
add_subdirectory(fuse)
add_subdirectory(fuse-utils)
add_subdirectory(libaudiofile)
add_subdirectory(libspectrum)
add_subdirectory(lua)
add_subdirectory(scintilla)
add_subdirectory(zlib)

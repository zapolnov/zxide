
if(MSVC)
    add_definitions(
        /wd4018         # signed/unsigned mismatch
        /wd4146         # unary minus operator applied to unsigned type
        /wd4244         # conversion from 'type' to 'type', possible loss of data
        /wd4267         # conversion from 'type' to 'type', possible loss of data
        /wd4805         # unsafe mix of 'type' and 'bool' in operation
        )
else()
    add_definitions(
        -Wno-multichar
        )
endif()

add_subdirectory(bzip2)
add_subdirectory(libaudiofile)
add_subdirectory(scintilla)
add_subdirectory(zlib)

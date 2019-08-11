
if(MSVC)
    add_definitions(
        /wd4244         # conversion from 'type' to 'type', possible loss of data
        /wd4267         # conversion from 'type' to 'type', possible loss of data
        )
endif()

add_subdirectory(bzip2)
add_subdirectory(scintilla)
add_subdirectory(zlib)

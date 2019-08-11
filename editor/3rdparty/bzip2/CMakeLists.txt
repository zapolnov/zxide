
add_library(LibBZ2 STATIC ${src})
set_target_properties(LibBZ2 PROPERTIES FOLDER "ThirdParty" OUTPUT_NAME "BZ2")

add_sources(LibBZ2
    blocksort.c
    bzlib.c
    bzlib.h
    bzlib_private.h
    compress.c
    crctable.c
    decompress.c
    huffman.c
    randtable.c
    )

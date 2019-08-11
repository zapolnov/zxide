
add_library(ZLib STATIC ${src})
set_target_properties(ZLib PROPERTIES FOLDER "ThirdParty")

add_sources(ZLib
    adler32.c
    compress.c
    crc32.c
    crc32.h
    deflate.c
    deflate.h
    infback.c
    inffast.c
    inffast.h
    inffixed.h
    inflate.c
    inflate.h
    inftrees.c
    inftrees.h
    trees.c
    trees.h
    uncompr.c
    zconf.h
    zlib.h
    zutil.c
    zutil.h
    )

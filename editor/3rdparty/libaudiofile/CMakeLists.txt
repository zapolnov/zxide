
include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_definitions(
    -DFile=AFile
    )

if(WIN32)
    add_definitions(-Dssize_t=ptrdiff_t)
endif()

if(NOT MSVC)
    add_definitions(-Wno-unused)
endif()

include(TestBigEndian)
include(CheckIncludeFile)
test_big_endian(WORDS_BIGENDIAN)
check_include_file("unistd.h" HAVE_UNISTD_H)
set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

add_library(LibAudioFile STATIC "${config_h}")
target_include_directories(LibAudioFile PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libaudiofile")
set_target_properties(LibAudioFile PROPERTIES FOLDER "ThirdParty" OUTPUT_NAME "AudioFile")

add_sources(LibAudioFile
    libaudiofile/alac/ALACAudioTypes.h
    libaudiofile/alac/ALACBitUtilities.c
    libaudiofile/alac/ALACBitUtilities.h
    libaudiofile/alac/ALACDecoder.cpp
    libaudiofile/alac/ALACDecoder.h
    libaudiofile/alac/ALACEncoder.cpp
    libaudiofile/alac/ALACEncoder.h
    libaudiofile/alac/EndianPortable.c
    libaudiofile/alac/EndianPortable.h
    libaudiofile/alac/ag_dec.c
    libaudiofile/alac/ag_enc.c
    libaudiofile/alac/aglib.h
    libaudiofile/alac/dp_dec.c
    libaudiofile/alac/dp_enc.c
    libaudiofile/alac/dplib.h
    libaudiofile/alac/matrix_dec.c
    libaudiofile/alac/matrix_enc.c
    libaudiofile/alac/matrixlib.h
    libaudiofile/modules/ALAC.cpp
    libaudiofile/modules/ALAC.h
    libaudiofile/modules/BlockCodec.cpp
    libaudiofile/modules/BlockCodec.h
    libaudiofile/modules/FLAC.cpp
    libaudiofile/modules/FLAC.h
    libaudiofile/modules/FileModule.cpp
    libaudiofile/modules/FileModule.h
    libaudiofile/modules/G711.cpp
    libaudiofile/modules/G711.h
    libaudiofile/modules/IMA.cpp
    libaudiofile/modules/IMA.h
    libaudiofile/modules/MSADPCM.cpp
    libaudiofile/modules/MSADPCM.h
    libaudiofile/modules/Module.cpp
    libaudiofile/modules/Module.h
    libaudiofile/modules/ModuleState.cpp
    libaudiofile/modules/ModuleState.h
    libaudiofile/modules/PCM.cpp
    libaudiofile/modules/PCM.h
    libaudiofile/modules/RebufferModule.cpp
    libaudiofile/modules/RebufferModule.h
    libaudiofile/modules/SimpleModule.cpp
    libaudiofile/modules/SimpleModule.h
    libaudiofile/AIFF.cpp
    libaudiofile/AIFF.h
    libaudiofile/AVR.cpp
    libaudiofile/AVR.h
    libaudiofile/AudioFormat.cpp
    libaudiofile/AudioFormat.h
    libaudiofile/Buffer.cpp
    libaudiofile/Buffer.h
    libaudiofile/CAF.cpp
    libaudiofile/CAF.h
    libaudiofile/Compiler.h
    libaudiofile/FLACFile.cpp
    libaudiofile/FLACFile.h
    libaudiofile/Features.h
    libaudiofile/File.cpp
    libaudiofile/File.h
    libaudiofile/FileHandle.cpp
    libaudiofile/FileHandle.h
    libaudiofile/IFF.cpp
    libaudiofile/IFF.h
    libaudiofile/IRCAM.cpp
    libaudiofile/IRCAM.h
    libaudiofile/Instrument.cpp
    libaudiofile/Instrument.h
    libaudiofile/Loop.cpp
    libaudiofile/Marker.cpp
    libaudiofile/Marker.h
    libaudiofile/NIST.cpp
    libaudiofile/NIST.h
    libaudiofile/NeXT.cpp
    libaudiofile/NeXT.h
    libaudiofile/PacketTable.cpp
    libaudiofile/PacketTable.h
    libaudiofile/Raw.cpp
    libaudiofile/Raw.h
    libaudiofile/SampleVision.cpp
    libaudiofile/SampleVision.h
    libaudiofile/Setup.cpp
    libaudiofile/Setup.h
    libaudiofile/Shared.h
    libaudiofile/Tag.h
    libaudiofile/Track.cpp
    libaudiofile/Track.h
    libaudiofile/UUID.cpp
    libaudiofile/UUID.h
    libaudiofile/VOC.cpp
    libaudiofile/VOC.h
    libaudiofile/WAVE.cpp
    libaudiofile/WAVE.h
    libaudiofile/af_vfs.cpp
    libaudiofile/af_vfs.h
    libaudiofile/afinternal.h
    libaudiofile/audiofile.h
    libaudiofile/aupv.c
    libaudiofile/aupvinternal.h
    libaudiofile/aupvlist.h
    libaudiofile/byteorder.h
    libaudiofile/compression.cpp
    libaudiofile/compression.h
    libaudiofile/data.cpp
    libaudiofile/error.c
    libaudiofile/error.h
    libaudiofile/extended.c
    libaudiofile/extended.h
    libaudiofile/format.cpp
    libaudiofile/g711.c
    libaudiofile/g711.h
    libaudiofile/openclose.cpp
    libaudiofile/pcm.cpp
    libaudiofile/pcm.h
    libaudiofile/units.cpp
    libaudiofile/units.h
    libaudiofile/util.cpp
    libaudiofile/util.h
    )

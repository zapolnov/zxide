
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

if(MSVC)
    set_source_files_properties(Z80Opcodes_parser.cpp PROPERTIES COMPILE_FLAGS "/bigobj")
endif()

add_library(Compiler STATIC)
set_target_properties(Compiler PROPERTIES FOLDER "Compiler")
target_link_libraries(Compiler LibSpectrum LibAudioFile Scripting Tape2Wav Bas2Tap Lua ZSdCPP ZSdCC COpt Zx7 Lzsa)
qt_link_libraries(Compiler Core)

qt_add_sources(Compiler
        ../res/compiler.qrc
        Assembler.cpp
        Assembler.h
        AssemblerContext.cpp
        AssemblerContext.h
        AssemblerLexer.cpp
        AssemblerLexer.h
        AssemblerParser.cpp
        AssemblerParser.h
        AssemblerToken.h
        CodeEmitter.cpp
        CodeEmitter.h
        Compiler.cpp
        Compiler.h
        Compressor.cpp
        Compressor.h
        DiskFileWriter.cpp
        DiskFileWriter.h
        Expression.cpp
        Expression.h
        ExpressionParser.cpp
        ExprEvalContext.cpp
        ExprEvalContext.h
        GfxData.cpp
        GfxData.h
        GfxFile.cpp
        GfxFile.h
        IErrorReporter.h
        IO.cpp
        IO.h
        Linker.cpp
        Linker.h
        LuaBindings.cpp
        LuaBindings.h
        MapData.cpp
        MapData.h
        MapFile.cpp
        MapFile.h
        MusicCompiler.h
        NullOutput.cpp
        NullOutput.h
        Program.cpp
        Program.h
        ProgramBinary.cpp
        ProgramBinary.h
        ProgramDebugInfo.cpp
        ProgramDebugInfo.h
        ProgramLabel.cpp
        ProgramLabel.h
        ProgramOpcode.cpp
        ProgramOpcode.h
        ProgramSection.cpp
        ProgramSection.h
        ProjectSettings.cpp
        ProjectSettings.h
        TapeFileWriter.cpp
        TapeFileWriter.h
        TileSetData.cpp
        TileSetData.h
        TileSetFile.cpp
        TileSetFile.h
        Util.cpp
        Util.h
        Value.cpp
        Value.h
        Z80Opcodes.cpp
        Z80Opcodes_parser.cpp
        Z80Opcodes.h
    )

if(BUILD_COMPILER_TESTS)
    add_subdirectory(tests)
endif()

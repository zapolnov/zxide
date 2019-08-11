
if(MSVC)
    set_source_files_properties(Z80Opcodes_parser.cpp PROPERTIES COMPILE_FLAGS "/bigobj")
endif()

add_library(Compiler STATIC)
set_target_properties(Compiler PROPERTIES FOLDER "Compiler")
qt_link_libraries(Compiler Core)

qt_add_sources(Compiler
        Assembler.cpp
        Assembler.h
        AssemblerLexer.cpp
        AssemblerLexer.h
        AssemblerParser.cpp
        AssemblerParser.h
        AssemblerToken.h
        Compiler.cpp
        Compiler.h
        Expression.cpp
        Expression.h
        ExpressionParser.cpp
        IErrorReporter.h
        Linker.cpp
        Linker.h
        Program.cpp
        Program.h
        ProgramBinary.cpp
        ProgramBinary.h
        ProgramLabel.cpp
        ProgramLabel.h
        ProgramOpcode.cpp
        ProgramOpcode.h
        ProgramSection.cpp
        ProgramSection.h
        Util.cpp
        Util.h
        Z80Opcodes.cpp
        Z80Opcodes_parser.cpp
        Z80Opcodes.h
    )

add_subdirectory(tests)

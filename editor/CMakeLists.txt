
add_subdirectory(3rdparty)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

qt_add_executable(GameEditor USES Core Gui Widgets)
target_link_libraries(GameEditor Scintilla)

qt_add_sources(GameEditor
        code/CodeTab.cpp
        code/CodeTab.h
        code/CodeTab.ui
        code/TextEditor.cpp
        code/TextEditor.h
        compiler/Assembler.cpp
        compiler/Assembler.h
        compiler/AssemblerLexer.cpp
        compiler/AssemblerLexer.h
        compiler/AssemblerParser.cpp
        compiler/AssemblerParser.h
        compiler/AssemblerToken.h
        compiler/Compiler.cpp
        compiler/Compiler.h
        compiler/CompilerDialog.cpp
        compiler/CompilerDialog.h
        compiler/CompilerDialog.ui
        compiler/IErrorReporter.h
        compiler/Program.cpp
        compiler/Program.h
        compiler/ProgramLabel.cpp
        compiler/ProgramLabel.h
        compiler/ProgramOpcode.cpp
        compiler/ProgramOpcode.h
        compiler/ProgramSection.cpp
        compiler/ProgramSection.h
        compiler/Util.cpp
        compiler/Util.h
        compiler/Z80Opcodes.cpp
        compiler/Z80Opcodes.h
        levels/LevelsTab.cpp
        levels/LevelsTab.h
        levels/LevelsTab.ui
        res/resources.qrc
        tiles/TilesTab.cpp
        tiles/TilesTab.h
        tiles/TilesTab.ui
        AboutDialog.cpp
        AboutDialog.h
        AboutDialog.ui
        AbstractEditorTab.cpp
        AbstractEditorTab.h
        FileManager.cpp
        FileManager.h
        FileManager.ui
        IEditorTab.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        Settings.h
        main.cpp
    )

target_sources(GameEditor PRIVATE
    "${config_h}"
    )

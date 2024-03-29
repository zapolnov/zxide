
set(BUILD_FUSE TRUE)
set(BUILD_SCINTILLA TRUE)
add_subdirectory(3rdparty)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

set(BUILD_COMPILER_TESTS TRUE)
add_subdirectory(compiler)
add_subdirectory(scripting)

qt_add_executable(GameEditor USES Core Gui Widgets Multimedia Network)
target_link_libraries(GameEditor Lua Scintilla Compiler Scripting Fuse)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_library(LIBPULSE pulse)
    target_link_libraries(GameEditor ${LIBPULSE})
endif()

qt_add_sources(GameEditor
        debugger/AddBreakpointDialog.cpp
        debugger/AddBreakpointDialog.h
        debugger/AddBreakpointDialog.ui
        debugger/BreakpointsModel.cpp
        debugger/BreakpointsModel.h
        debugger/BreakpointsWindow.cpp
        debugger/BreakpointsWindow.h
        debugger/BreakpointsWindow.ui
        debugger/ControlFlowLogWindow.cpp
        debugger/ControlFlowLogWindow.h
        debugger/ControlFlowLogWindow.ui
        debugger/DisassemblyWidget.cpp
        debugger/DisassemblyWidget.h
        debugger/DisplayWidget.cpp
        debugger/DisplayWidget.h
        debugger/EditMemoryDialog.cpp
        debugger/EditMemoryDialog.h
        debugger/EditMemoryDialog.ui
        debugger/EditRegisterDialog.ui
        debugger/EmulatorCore.cpp
        debugger/EmulatorCore.h
        debugger/MemoryLogWindow.cpp
        debugger/MemoryLogWindow.h
        debugger/MemoryLogWindow.ui
        debugger/MemoryMapDialog.cpp
        debugger/MemoryMapDialog.h
        debugger/MemoryMapDialog.ui
        debugger/MemoryWidget.cpp
        debugger/MemoryWidget.h
        debugger/RegistersWidget.cpp
        debugger/RegistersWidget.h
        debugger/StackWidget.cpp
        debugger/StackWidget.h
        debugger/WatchModel.cpp
        debugger/WatchModel.h
        editor/code/CodeEditorTab.cpp
        editor/code/CodeEditorTab.h
        editor/code/CodeEditorTab.ui
        editor/code/TextEditor.cpp
        editor/code/TextEditor.h
        editor/disasm/DisassemblyTab.cpp
        editor/disasm/DisassemblyTab.h
        editor/disasm/DisassemblyTab.ui
        editor/gfx/GfxEditorTab.cpp
        editor/gfx/GfxEditorTab.h
        editor/gfx/GfxEditorTab.ui
        editor/gfx/GfxEditorWidget.cpp
        editor/gfx/GfxEditorWidget.h
        editor/map/EditEntityDialog.cpp
        editor/map/EditEntityDialog.h
        editor/map/EditEntityDialog.ui
        editor/map/MapEditorTab.cpp
        editor/map/MapEditorTab.h
        editor/map/MapEditorTab.ui
        editor/map/MapEditorWidget.cpp
        editor/map/MapEditorWidget.h
        editor/tileset/TileSetEditorTab.cpp
        editor/tileset/TileSetEditorTab.h
        editor/tileset/TileSetEditorTab.ui
        editor/AbstractEditorTab.cpp
        editor/AbstractEditorTab.h
        editor/DuplicateDialog.cpp
        editor/DuplicateDialog.h
        editor/DuplicateDialog.ui
        editor/EditorTabFactory.cpp
        editor/EditorTabFactory.h
        editor/FileManager.cpp
        editor/FileManager.h
        editor/FileManager.ui
        editor/HighlightManager.cpp
        editor/HighlightManager.h
        editor/NewFileDialog.cpp
        editor/NewFileDialog.h
        editor/NewFileDialog.ui
        editor/Project.cpp
        editor/Project.h
        editor/ProjectSettingsDialog.cpp
        editor/ProjectSettingsDialog.h
        editor/ProjectSettingsDialog.ui
        editor/RenameDialog.cpp
        editor/RenameDialog.h
        editor/RenameDialog.ui
        res/resources.qrc
        util/ClickableLabel.cpp
        util/ClickableLabel.h
        util/ComboBox.cpp
        util/ComboBox.h
        util/FileSelectorMenu.cpp
        util/FileSelectorMenu.h
        util/ImageImport.cpp
        util/ImageImport.h
        util/ScrollBar.cpp
        util/ScrollBar.h
        util/Settings.cpp
        util/Settings.h
        util/SimpleTextPainter.cpp
        util/SimpleTextPainter.h
        AboutDialog.cpp
        AboutDialog.h
        AboutDialog.ui
        CompilerDialog.cpp
        CompilerDialog.h
        CompilerDialog.ui
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        PlayAudioDialog.cpp
        PlayAudioDialog.h
        PlayAudioDialog.ui
        SettingsDialog.cpp
        SettingsDialog.h
        SettingsDialog.ui
        ThirdPartyDialog.cpp
        ThirdPartyDialog.h
        ThirdPartyDialog.ui
        main.cpp
    )

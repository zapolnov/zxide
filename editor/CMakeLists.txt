
add_subdirectory(3rdparty)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

add_subdirectory(compiler)

qt_add_executable(GameEditor USES Core Gui Widgets)
target_link_libraries(GameEditor Scintilla Compiler Fuse)

qt_add_sources(GameEditor
        debugger/DisplayWidget.cpp
        debugger/DisplayWidget.h
        debugger/EditRegisterDialog.ui
        debugger/EmulatorCore.cpp
        debugger/EmulatorCore.h
        debugger/MemoryWidget.cpp
        debugger/MemoryWidget.h
        debugger/RegistersWidget.cpp
        debugger/RegistersWidget.h
        debugger/StackWidget.cpp
        debugger/StackWidget.h
        editor/code/CodeEditorTab.cpp
        editor/code/CodeEditorTab.h
        editor/code/CodeEditorTab.ui
        editor/code/TextEditor.cpp
        editor/code/TextEditor.h
        editor/AbstractEditorTab.cpp
        editor/AbstractEditorTab.h
        editor/EditorTabFactory.cpp
        editor/EditorTabFactory.h
        editor/FileManager.cpp
        editor/FileManager.h
        editor/FileManager.ui
        editor/NewFileDialog.cpp
        editor/NewFileDialog.h
        editor/NewFileDialog.ui
        editor/RenameDialog.cpp
        editor/RenameDialog.h
        editor/RenameDialog.ui
        res/resources.qrc
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
        SettingsDialog.cpp
        SettingsDialog.h
        SettingsDialog.ui
        ThirdPartyDialog.cpp
        ThirdPartyDialog.h
        ThirdPartyDialog.ui
        main.cpp
    )

target_sources(GameEditor PRIVATE
    "${config_h}"
    )

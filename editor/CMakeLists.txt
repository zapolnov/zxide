
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
        code/CodeTab.cpp
        code/CodeTab.h
        code/CodeTab.ui
        code/TextEditor.cpp
        code/TextEditor.h
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
        CompilerDialog.cpp
        CompilerDialog.h
        CompilerDialog.ui
        EmulatorCore.cpp
        EmulatorCore.h
        FileManager.cpp
        FileManager.h
        FileManager.ui
        IEditorTab.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        Settings.cpp
        Settings.h
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


include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
    )

set(config_h "${CMAKE_CURRENT_BINARY_DIR}/config.h")
configure_file(config.h.in "${config_h}")
source_group("Generated Files" FILES "${config_h}")

qt_add_executable(GameEditor USES Core Gui Widgets)
qt_add_sources(GameEditor
        res/resources.qrc
        AboutDialog.cpp
        AboutDialog.h
        AboutDialog.ui
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        main.cpp
    )

target_sources(GameEditor PRIVATE
    "${config_h}"
    )

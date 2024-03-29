
macro(qt_add_sources target)
    set(gen)
    set(moc)
    set(rcc)

    foreach(file ${ARGN})
        get_filename_component(ext "${file}" EXT)
        get_filename_component(path "${file}" DIRECTORY)

        if (path STREQUAL "")
            string(REPLACE "/" "\\" group "Source Files")
        else()
            string(REPLACE "/" "\\" group "Source Files/${path}")
        endif()
        source_group("${group}" FILES "${file}")

        if(ext STREQUAL ".h")
            file(READ "${file}" contents)
            if(contents MATCHES "\n[ \t]*Q_OBJECT[ \t]*\r?\n")
                qt5_wrap_cpp(moc "${file}")
            endif()
        elseif(ext STREQUAL ".ui")
            qt5_wrap_ui(gen "${file}")
        elseif(ext STREQUAL ".qrc")
            qt5_add_resources(rcc "${file}")
        endif()
    endforeach()

    list(LENGTH moc num1)
    list(LENGTH rcc num2)
    if("${num1}" GREATER 0 OR "${num2}" GREATER 0)
        set(out)
        foreach(file ${moc})
            get_filename_component(full "${file}" ABSOLUTE)
            set(out "${out}#include \"${full}\"\n")
        endforeach()

        set(counter 1)
        foreach(file ${rcc})
            get_filename_component(full "${file}" ABSOLUTE)
            set(out "${out}\n")
            set(out "${out}#define qt_resource_name qt_resource_name_${counter}\n")
            set(out "${out}#define qt_resource_data qt_resource_data_${counter}\n")
            set(out "${out}#define qt_resource_struct qt_resource_struct_${counter}\n")
            set(out "${out}#define dummy dummy_${counter}\n")
            set(out "${out}#define initializer initializer_${counter}\n")
            set(out "${out}#include \"${full}\"\n")
            set(out "${out}#undef qt_resource_name\n")
            set(out "${out}#undef qt_resource_data\n")
            set(out "${out}#undef qt_resource_struct\n")
            set(out "${out}#undef dummy\n")
            set(out "${out}#undef initializer\n")
            math(EXPR counter "${counter} + 1")
        endforeach()

        set(gen_cpp "${CMAKE_CURRENT_BINARY_DIR}/generated.cpp")
        set(dowrite TRUE)
        if(EXISTS "${gen_cpp}")
            file(READ "${gen_cpp}" old)
            if("${old}" STREQUAL "${out}")
                set(dowrite FALSE)
            endif()
        endif()
        if(dowrite)
            file(WRITE "${gen_cpp}" "${out}")
        endif()

        set_source_files_properties(${moc} ${rcc} PROPERTIES HEADER_FILE_ONLY TRUE)
        list(APPEND gen "${gen_cpp}")
    endif()

    source_group("Generated Files" FILES ${gen} ${moc} ${rcc})
    target_sources("${target}" PRIVATE ${ARGN} ${gen} ${moc} ${rcc})
endmacro()

macro(qt_install_win32_plugins config targetDir libFile)
    set(suffix)
    string(TOUPPER "${config}" cfg)
    if("${cfg}" STREQUAL "DEBUG")
        set(suffix "d")
    endif()
    get_filename_component(path "${libFile}" DIRECTORY)
    get_filename_component(path "${path}" DIRECTORY)
    foreach(plugin ${ARGN})
        set(name "${plugin}${suffix}.dll")
        set(file "${path}/plugins/${name}")
        if(EXISTS "${file}" AND NOT EXISTS "${targetDir}/${name}")
            message(STATUS "Installing dependency '${name}' (${config})")
            configure_file("${file}" "${targetDir}/${name}" COPYONLY)
        endif()
    endforeach()
endmacro()

macro(_install_library file config targetDir)
    get_filename_component(name "${file}" NAME)
    if(EXISTS "${file}" AND NOT EXISTS "${targetDir}/${name}")
        message(STATUS "Installing dependency '${name}' (${config})")
        configure_file("${file}" "${targetDir}/${name}" COPYONLY)
    endif()
endmacro()

macro(qt_install_library config targetDir lib)
    string(TOUPPER "${config}" cfg)
    get_target_property(file "${lib}" LOCATION_${cfg})
    _install_library("${file}" "${config}" "${targetDir}")
    if(WIN32 AND "${lib}" STREQUAL "Qt5::Gui")
        qt_install_win32_plugins("${config}" "${targetDir}" "${file}"
            platforms/qwindows
            styles/qwindowsvistastyle
            )
    endif()
    if(WIN32 AND "${lib}" STREQUAL "Qt5::Multimedia")
        qt_install_win32_plugins("${config}" "${targetDir}" "${file}"
            audio/qtaudio_wasapi
            audio/qtaudio_windows
            mediaservice/dsengine
            mediaservice/qtmedia_audioengine
            mediaservice/wmfengine
            )
    endif()
endmacro()

macro(qt_link_libraries target)
    find_package(Qt5 COMPONENTS ${ARGN} REQUIRED)
    foreach(name ${ARGN})
        set(lib "Qt5::${name}")
        target_link_libraries("${target}" "${lib}")
    endforeach()
endmacro()

macro(qt_install_libraries target)
    foreach(name ${ARGN})
        set(lib "Qt5::${name}")
        if(MSVC OR MINGW)
            if(MSVC)
                foreach(config ${CMAKE_CONFIGURATION_TYPES})
                    qt_install_library("${config}" "${CMAKE_BINARY_DIR}/${config}" "${lib}")
                endforeach()
            elseif(MINGW)
                qt_install_library("${CMAKE_BUILD_TYPE}" "${CMAKE_BINARY_DIR}" "${lib}")
            endif()
        endif()
        target_link_libraries("${target}" "${lib}")
    endforeach()
endmacro()

macro(qt_add_executable target)
    set(qt_libs ${ARGN})
    list(REMOVE_ITEM qt_libs "USES")

    add_executable("${target}" WIN32)
    set_target_properties("${target}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/PDB"
        )

    find_package(Qt5 COMPONENTS ${qt_libs} REQUIRED)
    qt_install_libraries("${target}" ${qt_libs})
endmacro()

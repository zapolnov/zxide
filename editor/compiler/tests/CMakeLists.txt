
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

qt_add_executable(CompilerTests USES Core)
target_link_libraries(CompilerTests Compiler)
set_target_properties(CompilerTests PROPERTIES FOLDER "Compiler" WIN32_EXECUTABLE FALSE)

add_sources(CompilerTests
    3rdparty/catch.hpp
    helpers/DataBlob.cpp
    helpers/DataBlob.h
    helpers/ErrorConsumer.cpp
    helpers/ErrorConsumer.h
    helpers/TestUtil.cpp
    helpers/TestUtil.h
    helpers/main.cpp
    EquTests.cpp
    ErrorTests.cpp
    ExprTests.cpp
    LabelTests.cpp
    OpcodeTests.cpp
    )

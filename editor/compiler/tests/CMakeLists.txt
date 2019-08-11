
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    )

qt_add_executable(CompilerTests USES Core)
target_link_libraries(CompilerTests Compiler)
set_target_properties(CompilerTests PROPERTIES FOLDER "Compiler" WIN32_EXECUTABLE FALSE)

add_sources(CompilerTests
    3rdparty/catch.hpp
    DataBlob.cpp
    DataBlob.h
    EquTests.cpp
    ErrorConsumer.cpp
    ErrorConsumer.h
    ErrorTests.cpp
    ExpressionTests.cpp
    LabelTests.cpp
    OpcodeTests.cpp
    TestUtil.cpp
    TestUtil.h
    main.cpp
    )

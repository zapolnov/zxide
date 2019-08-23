#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("repeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5\n"
        "db 0x01\n"
        "endrepeat\n"
        ;

    static const unsigned char binary[] = {
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("missing endrepeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "missing 'endrepeat'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

// FIXME: test for repeat inside repeat
// FIXME: test for error if label name is the same as variable name
// FIXME: test for error if variable name is the same as label name
// FIXME: test for global and local labels inside repeat macro
// FIXME: test counter value
// FIXME: test for equ as repeat count

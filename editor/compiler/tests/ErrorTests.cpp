#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("expected opcode", "[errors]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "4\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "expected opcode or directive");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("invalid opcode", "[errors]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "x\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "unknown opcode 'x'");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

#include "3rdparty/catch.hpp"
#include "DataBlob.h"
#include "ErrorConsumer.h"
#include "TestUtil.h"

TEST_CASE("duplicate label", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "label1: nop\n"
        "label1: nop\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate label 'label1'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

#define CATCH_CONFIG_RUNNER
#include "3rdparty/catch.hpp"
#include <QCoreApplication>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    return Catch::Session().run(argc, argv);
}

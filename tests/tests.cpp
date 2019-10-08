/*

    tests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 08/10/2019.

    DESCRIPTION:
    tests sub-project that runs tests on core modules.
*/

#define CATCH_CONFIG_MAIN
#include "Catch2.hpp"
#include <cstdio>

TEST_CASE("SIMPLE", "TEST") {
    REQUIRE(1 == 1);
    printf("JOPA\n");
}

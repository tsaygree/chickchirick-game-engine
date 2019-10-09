/*

    MemoryUnitsTests.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 09/10/2019.

    DESCRIPTION:
    Tests for MemoryUnits module.

*/

#include "Catch2.hpp"
#include "MemoryUnits.hpp"
#include <cassert>

TEST_CASE("MemoryUnits tests", "[MemoryUnits]") {
    static_assert(1_KiB == 1024, "Kibibytes to bytes");
    static_assert(1_MiB == 1048576, "Mibibytes to bytes");
    static_assert(1_GiB == 1073741824, "Gibibytes to bytes");

    REQUIRE(5_KiB == 5120);
    REQUIRE(10_MiB == 10240_KiB);
    REQUIRE(1_GiB == 1024_MiB);
}

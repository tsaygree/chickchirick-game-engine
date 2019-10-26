/*

    StringIDTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 09/10/2019.

    DESCRIPTION:
    Tests for StringID module.
*/

#include "Catch2.hpp"
#include "StringID.hpp"

TEST_CASE("StringID module tests", "[StringID]") {
    SECTION("_sid tests") {
        static_assert("123456789"_sid == 0xCBF43926, "crc32b hash test");
        REQUIRE("TEST"_sid == 0xEEEA93B8);
    }
    SECTION("StringID tests") {
        StringID str = SID("SID TEST");
        REQUIRE(str.getID()  == 0xF5BE303C);
        REQUIRE(str.getStr() == "SID TEST");
    }
    SECTION("concat tests") {
        StringID lhs    = SID("lhs + ");
        StringID rhs    = SID("rhs");
        StringID lhsRhs = lhs + rhs;
        REQUIRE(lhsRhs.getStr() == "lhs + rhs");
    }
}

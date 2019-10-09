/*

    StackAllocTests.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 08/10/2019.

    DESCRIPTION:
    Tests for StackAlloc module.

*/

#include "Catch2.hpp"
#include "StackAlloc.hpp"
#include "MemoryUnits.hpp"

TEST_CASE("StackAlloc tests", "[StackAlloc]") {
    StackAlloc& stackPool = StackAlloc::getInstance();
    stackPool.startUP(100_MiB, 200_MiB);
    SECTION("Big size") {
        int*  ptr1 = (int*)stackPool.stalloc(201_MiB);
        char* ptr2 = (char*)stackPool.LSRalloc(101_MiB);
        REQUIRE(ptr1 == nullptr);
        REQUIRE(ptr2 == nullptr);
    }
}

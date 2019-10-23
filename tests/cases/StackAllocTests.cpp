/*

    StackAllocTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 08/10/2019.

    DESCRIPTION:
    Tests for StackAlloc module.

*/

#include "Catch2.hpp"
#include "StackAlloc.hpp"
#include "MemoryUnits.hpp"

TEST_CASE("StackAlloc tests", "[StackAlloc]") {
    StackAlloc stackPool;
    SECTION("Outer pool tests") {
        SECTION("heap memory") {
            char* pool = new char[300_MiB];
            stackPool.startUP(pool, 100_MiB, 200_MiB);
            SECTION("Big size") {
                int*  ptr1 = (int*)stackPool.stalloc(201_MiB);
                char* ptr2 = (char*)stackPool.LSRalloc(101_MiB);
                REQUIRE(ptr1 == nullptr);
                REQUIRE(ptr2 == nullptr);
            }
            SECTION("Marker tests") {
                uint32_t marker = stackPool.getMarker();
                REQUIRE(marker == 100_MiB);
                int* ptr = (int*)stackPool.stalloc(sizeof(int));
                REQUIRE(stackPool.getMarker() - marker == sizeof(int));
                stackPool.freeToMarker(marker);
                REQUIRE(stackPool.getMarker() == marker);
                for (uint8_t it = 1; it != 11; it++) {
                    stackPool.stalloc(it * sizeof(int));
                }
                uint32_t newMarker = stackPool.getMarker();
                REQUIRE(newMarker - marker == 220);
                stackPool.free();
                newMarker = stackPool.getMarker();
                REQUIRE(newMarker == marker);
            }
            stackPool.shutDown();
            delete[] pool;
        }
        SECTION("static memory") {
            char pool[128];
            stackPool.startUP(pool, 64, 64);
            stackPool.shutDown();
        }
    }
    SECTION("Inner pool tests") {
        stackPool.startUP(100_MiB, 200_MiB);
        SECTION("Big size") {
            int*  ptr1 = (int*)stackPool.stalloc(201_MiB);
            char* ptr2 = (char*)stackPool.LSRalloc(101_MiB);
            REQUIRE(ptr1 == nullptr);
            REQUIRE(ptr2 == nullptr);
        }
        SECTION("Marker tests") {
            uint32_t marker = stackPool.getMarker();
            REQUIRE(marker == 100_MiB);
            int* ptr = (int*)stackPool.stalloc(sizeof(int));
            REQUIRE(stackPool.getMarker() - marker == sizeof(int));
            stackPool.freeToMarker(marker);
            REQUIRE(stackPool.getMarker() == marker);
            for (uint8_t it = 1; it != 11; it++) {
                stackPool.stalloc(it * sizeof(int));
            }
            uint32_t newMarker = stackPool.getMarker();
            REQUIRE(newMarker - marker == 220);
            stackPool.free();
            newMarker = stackPool.getMarker();
            REQUIRE(newMarker == marker);
        }
        stackPool.shutDown();
    }
}

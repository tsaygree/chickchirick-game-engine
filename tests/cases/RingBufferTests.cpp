/*

    RingBufferTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/11/2019.

    DESCRIPTION:

*/

#include "RingBuffer.hpp"
#include "Catch2.hpp"

TEST_CASE("RingBuffer module tests", "[RingBuffer]") {
    SECTION("Constructor test") {
        RingBuffer<int> queue(32);
    }
    SECTION("Push test") {
        RingBuffer<int> queue(10);
        size_t it = 0;
        for (; it != 10; it++) {
            queue.push(it);
        }
        it = 0;
        for (const auto val : queue) {
            REQUIRE(val == it++);
        }
    }
}

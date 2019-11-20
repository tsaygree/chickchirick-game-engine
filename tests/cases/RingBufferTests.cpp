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
    SECTION("Push tests") {
        SECTION("RingBuffer fully loaded") {
            size_t size = 10;
            RingBuffer<int> queue(size);
            size_t it = 0;
            for (; it != size; it++) {
                queue.push(it);
            }
            REQUIRE(queue.size() == size);
            it = 0;
            for (const auto val : queue) {
                REQUIRE(val == it++);
            }
        }
    }
}

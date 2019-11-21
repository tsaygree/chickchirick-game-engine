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
}

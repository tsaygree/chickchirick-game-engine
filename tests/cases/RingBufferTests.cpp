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
            Vector<int> input  = {1, 2, 3, 4, 5};
            Vector<int> output = {1, 2, 3, 4, 5};
            RingBuffer<int> q(5);
            for (auto& val : input) {
                q.push(val);
            }
            for (auto& val : output) {
                int num = q.front();
                REQUIRE(num == val);
                q.pop();
            }
        }
    }
}

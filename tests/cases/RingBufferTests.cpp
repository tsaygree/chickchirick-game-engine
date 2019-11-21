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
    SECTION("Push & Pop tests") {
        SECTION("RingBuffer underflow") {
            Vector<int> input = {1, 2, 3};
            RingBuffer<int> q(5);
            for (auto& val : input) {
                q.push(val);
            }
            REQUIRE(q.front() == input[0]);
            q.pop();
            q.pop();
            REQUIRE(q.front() == input[2]);
            q.pop();
            q.pop();
            q.pop();
            REQUIRE(q.size()  == 0);
            q.push(10);
            REQUIRE(q.size()  == 1);
            REQUIRE(q.front() == 10);
            REQUIRE(q.back()  == 10);
        }
        SECTION("RingBuffer fully loaded") {
            Vector<int> input  = {1, 2, 3, 4, 5};
            Vector<int> output = {1, 2, 3, 4, 5};
            RingBuffer<int> q(5);
            for (auto& val : input) {
                q.push(val);
            }
            REQUIRE(q.size() == output.size());
            for (auto& val : output) {
                int num = q.front();
                REQUIRE(num == val);
                q.pop();
            }
        }
        SECTION("RingBuffer overflow") {
            Vector<int> input  = {1, 2, 3, 4, 5};
            Vector<int> output = {3, 4, 5, 6, 7};
            RingBuffer<int> q(5);
            for (auto& val : input) {
                q.push(val);
            }
            q.push(6);
            q.push(7);
            for (auto& val : output) {
                int num = q.front();
                REQUIRE(num == val);
                q.pop();
            }
        }
    }
}

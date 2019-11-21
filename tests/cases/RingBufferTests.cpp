/*

    RingBufferTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/11/2019.

    DESCRIPTION:

*/

#include "RingBuffer.hpp"
#include "Catch2.hpp"

TEST_CASE("RingBuffer module tests", "[RingBuffer]") {
    // SECTION("Constructor test") {
    //     RingBuffer<int> queue(32);
    // }
    // SECTION("Push tests") {
    //     SECTION("RingBuffer fully loaded") {
    //         size_t size = 10;
    //         RingBuffer<int> queue(size);
    //         size_t it = 0;
    //         for (; it != size; it++) {
    //             queue.push(it);
    //             printf("%d == %d\n", queue.back(), it);
    //         }
    //         REQUIRE(queue.size() == size);
    //         it = 0;
    //         for (const auto val : queue) {
    //             printf("%d == %d\n", val, it);
    //             REQUIRE(val == it++);
    //         }
    //     }
    //     SECTION("RingBuffer overflow") {
    //         size_t size = 5;
    //         Vector<int> input  = {0, 1, 2, 3, 4};
    //         Vector<int> result = {5, 6, 2, 3, 4};
    //         RingBuffer<int> queue(size);
    //         for (auto val : input) {
    //             queue.push(val);
    //         }
    //         queue.push(5);
    //         queue.push(6);
    //         size_t it  = 0;
    //         auto curVal = queue.begin();
    //         while (it != size && curVal != queue.end()) {
    //             REQUIRE(*curVal == result[it]);
    //             curVal++;
    //             it++;
    //         }
    //     }
    // }
    // SECTION("Pop tests") {
    //     SECTION("RingBuffer fully loaded") {
    //         size_t size = 10;
    //         RingBuffer<int> queue(size);
    //         size_t it = 0;
    //         for (; it != size; it++) {
    //             queue.push(it);
    //         }
    //         for (it = 0; it != size; it++) {
    //             int val = queue.pop();
    //             REQUIRE(val == it);
    //         }
    //     }
    //     SECTION("RingBuffer overflow") {
    //         size_t size = 5;
    //         Vector<int> input  = {0, 1, 2, 3, 4};
    //         RingBuffer<int> queue(size);
    //         for (auto val : input) {
    //             queue.push(val);
    //         }
    //
    //         for (auto val : queue) { printf("%d ", val); }
    //         printf("\n");
    //
    //         //WRONG!!!
    //         queue.push(5);
    //         queue.push(6);
    //         int val = queue.pop();
    //         REQUIRE(val == 2);
    //         val = queue.pop();
    //         REQUIRE(val == 3);
    //
    //         for (auto val : queue) { printf("%d ", val); }
    //         printf("\n");
    //
    //         queue.push(7);
    //         queue.push(8);
    //         val = queue.pop();
    //         REQUIRE(val == 4);
    //         val = queue.pop();
    //         REQUIRE(val == 5);
    //
    //         for (auto val : queue) { printf("%d ", val); }
    //         printf("\n");
    //
    //         val = queue.pop();
    //         REQUIRE(val == 6);
    //
    //         // for (auto val : input) {
    //         //     queue.push(val);
    //         // }
    //
    //     }
    // }
}

/*

    BlockAllocTests.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/10/2019.

    DESCRIPTION:
    Tests for BlockAlloc module.

*/

#include "Catch2.hpp"
#include "Allocators/BlockAlloc.hpp"

#define POOLSIZE 32
#define BLOCKSIZE 8

TEST_CASE("type test", "[BlockAlloc]") {
    BlockAlloc blockPool;
    blockPool.poolInit(POOLSIZE, BLOCKSIZE);
    int *intptr = (int*)blockPool.balloc();
    *intptr = INT_MAX;
    char *charptr = (char*)blockPool.balloc();
    *charptr = 'R';
    float *floatptr = (float*)blockPool.balloc();
    *floatptr = 3.5;

    REQUIRE(*intptr == INT_MAX);
    REQUIRE(*charptr == 'R');
    REQUIRE(*floatptr == 3.5);
    blockPool.free(intptr);
    blockPool.free(charptr);
    blockPool.free(floatptr);

    bool *boolptr = (bool*)blockPool.balloc();
    REQUIRE((void*)boolptr == (void*)floatptr);
    blockPool.free(boolptr);
    blockPool.poolShutDown();
}

TEST_CASE("overflow test", "[BlockAlloc]") {
    BlockAlloc blockPool;
    blockPool.poolInit(POOLSIZE, BLOCKSIZE);
    char *ptr1 = (char*)blockPool.balloc();
    char *ptr2 = (char*)blockPool.balloc();
    char *ptr3 = (char*)blockPool.balloc();
    char *ptr4 = (char*)blockPool.balloc();
    *ptr1 = '1';
    *ptr2 = '2';
    *ptr3 = '3';
    *ptr4 = '4';
    char *nptr = (char*)blockPool.balloc();
    REQUIRE(nptr == nullptr);
    blockPool.freeAll();
    blockPool.poolShutDown();
}

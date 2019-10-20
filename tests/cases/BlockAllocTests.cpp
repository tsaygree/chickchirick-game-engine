/*

    BlockAllocTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/10/2019.

    DESCRIPTION:
    Tests for BlockAlloc module.

*/

#include "Catch2.hpp"
#include "BlockAlloc.hpp"
#include <string>

#define POOLSIZE 32
#define BLOCKSIZE 8

class Test {
public:
    Test() {}
    ~Test() {}
    int num = 0;
    bool isTrue = false;
    std::string name = "";
};

TEST_CASE("initialize tests", "[BlockAlloc]") {
    BlockAlloc bPool;
    uint32_t bSize = sizeof(Test);
    uint32_t pSize = 4 * bSize;
    SECTION("initialize inner pool") {
        bPool.startUP(pSize, bSize);
        Test* tptr = CAST(Test*, bPool.balloc());
        tptr->num = 5;
        REQUIRE(tptr->num == 5);
        bPool.shutDown();
    }
    SECTION("initialize outer pool") {
        char* outerPool = new char[pSize];
        bPool.startUP(outerPool, pSize, bSize);
        Test* tptr = CAST(Test*, bPool.balloc());
        tptr->num = 10;
        REQUIRE(tptr->num == 10);
        bPool.shutDown();
    }
}

TEST_CASE("type test", "[BlockAlloc]") {
    BlockAlloc blockPool;
    blockPool.startUP(POOLSIZE, BLOCKSIZE);
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
    blockPool.shutDown();
}

TEST_CASE("overflow test", "[BlockAlloc]") {
    BlockAlloc blockPool;
    blockPool.startUP(POOLSIZE, BLOCKSIZE);
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
    blockPool.shutDown();
}

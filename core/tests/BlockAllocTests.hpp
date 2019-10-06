#pragma once
#include <iostream>
#include <cstdio>
#include "TestRunner.hpp"
#include "BlockAlloc.hpp"

/*
    NOTE:
    Tests expect these parameters to run properly:
    POOLSIZE 32
    BLOCKSIZE 8
*/

void typeTESTS();
void overflowTEST();
void ballocVSmallocTEST();


void runBlockAllocTests() {
    TestRunner tr;
    std::cout << "------------------------\n"
              << "running BlockAlloc tests\n" << std::endl;
    RUN_TEST(tr, typeTESTS);
    RUN_TEST(tr, overflowTEST);
    RUN_TEST(tr, ballocVSmallocTEST);
    std::cout << "------------------------" << std::endl;
}

void typeTESTS() {
    BlockAlloc blockPool;
    blockPool.poolInit(32, 8);
    int *intptr = (int*)blockPool.balloc();
    *intptr = INT_MAX;
    char *charptr = (char*)blockPool.balloc();
    *charptr = 'R';
    float *floatptr = (float*)blockPool.balloc();
    *floatptr = 3.5;

    ASSERT(*intptr == INT_MAX);
    ASSERT(*charptr == 'R');
    ASSERT(*floatptr == 3.5);
    blockPool.free(intptr);
    blockPool.free(charptr);
    blockPool.free(floatptr);

    bool *boolptr = (bool*)blockPool.balloc();
    ASSERT((void*)boolptr == (void*)floatptr);
    blockPool.free(boolptr);
    blockPool.poolShutDown();
}

void overflowTEST() {
    BlockAlloc blockPool;
    blockPool.poolInit(32, 8);
    char *ptr1 = (char*)blockPool.balloc();
    char *ptr2 = (char*)blockPool.balloc();
    char *ptr3 = (char*)blockPool.balloc();
    char *ptr4 = (char*)blockPool.balloc();
    *ptr1 = '1';
    *ptr2 = '2';
    *ptr3 = '3';
    *ptr4 = '4';
    char *nptr = (char*)blockPool.balloc();
    ASSERT(nptr == nullptr);
    blockPool.freeAll();
    blockPool.poolShutDown();
}

void ballocVSmallocTEST() {
    BlockAlloc blockPool;
    blockPool.poolInit(32, 8);
    auto pool_start = std::chrono::system_clock::now();
    for (size_t it = 0; it != 32/8; it++) {
        int *intptr = (int*)blockPool.balloc();
        *intptr = it;
        blockPool.free(intptr);
    }
    auto pool_end = std::chrono::system_clock::now();

    auto malloc_start = std::chrono::system_clock::now();
    for (size_t it = 0; it != 32/8; it++) {
        int *intptr = (int*)malloc(2 * sizeof(int));
        *intptr = it;
        free(intptr);
    }
    auto malloc_end = std::chrono::system_clock::now();

    auto pool_elapsed_seconds = std::chrono::duration<double>(pool_end - pool_start).count();
    auto malloc_elapsed_seconds = std::chrono::duration<double>(malloc_end - malloc_start).count();
    std::cout << "-------------------" << "\n"
              << "balloc vs malloc" << "\n"
              << "pool size (bytes): " << 32 << "\n"
              << "block size (bytes): " << 8 << "\n"
              << "number of allocations: " << 32/8 << "\n"
              << "balloc elapsed time: " << pool_elapsed_seconds << "s\n"
              << "malloc elapsed time: " << malloc_elapsed_seconds << "s\n"
              << "speed up: " << malloc_elapsed_seconds / pool_elapsed_seconds << "\n"
              << "-------------------" << std::endl;
    blockPool.poolShutDown();
}

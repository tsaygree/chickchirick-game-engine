/*

    BlockAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 27/09/2019.

    DESCRIPTION:
    BlockAlloc is a fixed size static memory pool allocator.
    Pool size (bytes) and memory block size (bytes) should be
    configured before compilation. Due to implementation details,
    each memory block size cannot be less than a size of pointer in
    particular system. Pool size should be a multiple of memory
    block size. Compilation errors will occure if size requirements
    won't be followed. It is up to 10 times faster than malloc
    and does not cause memory fragmentation.
    Remember that BlockAlloc is a namespace and memory is allocated
    statically, so block pool cannnot be configured or changed at runtime.
    At least for now :)
    It is also not thread safe in its current state.
*/

#pragma once

/*
    size of pool in bytes
    should not be less than BLOCKSIZE and
    should be multiple of BLOCKSIZE
*/
#define POOLSIZE 32
/*
    size of memory block in bytes
    should be more or equal to size of pointer
*/
#define BLOCKSIZE 8

static_assert(BLOCKSIZE >= sizeof(char*), "Memory block size (bytes) should be more or equal to size of pointer");
static_assert(POOLSIZE >= BLOCKSIZE, "Pool size (bytes) should not be less than size of memory block");
static_assert(POOLSIZE % BLOCKSIZE == 0, "Pool size (bytes) should be multiple of memory block size");

namespace BlockAlloc {
    void poolInit();                                /*  pool initialization                     */
    void *balloc();                                 /*  block allocation                        */
    void free(void *blockptr);                      /*  free allocated block                    */
    #define freeAll() pool_init();                  /*  free all allocated blocks               */
}

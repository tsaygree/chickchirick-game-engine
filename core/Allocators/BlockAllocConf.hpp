/*

    BlockAllocConf.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    Configuration file for BlockAlloc module.

*/

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

/*  compile time assertions to check allocator settings     */
static_assert(BLOCKSIZE >= sizeof(char*), "Memory block size (bytes) should be more or equal to size of pointer");
static_assert(POOLSIZE >= BLOCKSIZE, "Pool size (bytes) should not be less than size of memory block");
static_assert(POOLSIZE % BLOCKSIZE == 0, "Pool size (bytes) should be multiple of memory block size");

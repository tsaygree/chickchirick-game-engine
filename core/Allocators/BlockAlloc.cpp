/*

    BlockAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 27/09/2019.

*/
#include "BlockAlloc.hpp"

static char blockPool[POOLSIZE];            /*  pool of static memory                   */
static char *freeBlockPtr;                  /*  pointer to current free memory block    */

void poolInit() {
    char *cur = Pool;
    char *end = Pool + POOLSIZE - BLOCKSIZE;
    uintptr_t addr = 0;
    while (cur < end) {
        addr = CAST(uintptr_t, (cur + BLOCKSIZE));
        cpyptr(cur, &addr);
        cur += BLOCKSIZE;
    }
    freeBlockPtr = Pool;
}

void* BlockAlloc::balloc() {
    void* result = freeBlockPtr;
    uintptr_t addr = 0;
    if (freeBlockPtr) cpyptr(&addr, freeBlockPtr);
    freeBlockPtr = CAST(char*, addr);
    return result;
}

/*

    BlockAlloc.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 27/09/2019.

*/
#include "BlockAlloc.hpp"

BlockAlloc::BlockAlloc() {}

void BlockAlloc::startUP(uint32_t pSize, uint32_t bSize) {
    /*
        Initialization process:
        Contigious memory blocks are initialized in such way that
        each m.block contains pointer to the one right after it.
        Let's call this area meta data.
        As long as POOLSIZE is multiple of BLOCKSIZE, POOLSIZE/BLOCKSIZE
        iterations are needed to initialize the pool.
        On each step pointer to next m.block is written to the
        next one after it. Last m.block must be filled with NULL pointer.

        Complexity: O(n), where n = POOLSIZE/BLOCKSIZE
        NOTE: implementation using only ptrs may be considered later
        if BlockAlloc will become a bottleneck.
    */
    assert(isInit == false);
    assert(bSize >= sizeof(char*));
    assert(pSize >= bSize);
    assert(pSize % bSize == 0);

    this->initVars(new char[pSize], pSize, bSize);
    this->resetPool();
    isInnerPool = true;
    isInit = true;
}

void BlockAlloc::startUP(char* bPool, uint32_t pSize, uint32_t bSize) {
    /*
        See description in another startUP method.
        The only difference between them is that here
        you are able to pass a pre-allocated memory
        pool and have more control over it.
    */
    assert(isInit == false);
    assert(bPool != nullptr);
    assert(bSize >= sizeof(char*));
    assert(pSize >= bSize);
    assert(pSize % bSize == 0);

    this->initVars(bPool, pSize, bSize);
    this->resetPool();
    isInit = true;
}

void* BlockAlloc::balloc() {
    /*
        Allocation process:
        Address that is written in curent free block
        is saved to freeBlockPtr.
        Current free block's ptr is given to user.
        NOTE: NULL ptr is returned when no blocks are left.

        Complexity: O(n), where n = sizeof(uintptr_t)
        NOTE: implementation using only ptrs may be considered later
        if BlockAlloc will become a bottleneck.
    */
    void* result = freeBlockPtr;
    uintptr_t addr = 0;
    if (freeBlockPtr) cpyptr(&addr, freeBlockPtr);
    freeBlockPtr = CAST(char*, addr);
    return result;
}

void BlockAlloc::free(void* blockptr) {
    /*
        Free memory process:
        Address of current free block is written
        to new free block. Address of new free block
        is written to freeBlockPtr.
        NOTE: If blockptr is out of bounds or somehow changed -
        runtime assertions will happen.

        Complexity: O(n), where n = sizeof(uintptr_t)
        NOTE: implementation using only ptrs may be considered later
        if BlockAlloc will become a bottleneck.
    */
    assert(blockptr != nullptr);
    assert(blockPool <= blockptr);
    assert(blockptr <= blockPool + poolSize - blockSize);
    assert(CAST(uintptr_t, blockptr) % blockSize == 0);

    uintptr_t addr = freeBlockPtr ? CAST(uintptr_t, freeBlockPtr) : 0;
    cpyptr(blockptr, &addr);
    freeBlockPtr = CAST(char*, blockptr);
}

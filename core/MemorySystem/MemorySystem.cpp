/*

    MemorySystem.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 10/10/2019.

*/

#include "MemorySystem.hpp"

MemorySystem::MemorySystem()  {}

MemorySystem& MemorySystem::getInstance() {
    static MemorySystem instance;
    return instance;
}

uint32_t MemorySystem::startUP(uint32_t LSRSize, uint32_t StackPoolSize) {
    assert(isInit == false);
    stackPool.startUP(LSRSize, StackPoolSize);
    isInit = true;
    return 0;
}

uint32_t MemorySystem::shutDown() {
    for (auto& entry : blockPoolList) {
        entry.pool.shutDown();
        delete[] entry.poolPtr;
    }
    blockPoolList.empty();
    stackPool.shutDown();
    isInit = false;
    return 0;
}

void MemorySystem::addBlockPool(uint32_t BlockPoolSize, uint32_t blockSize) {
    for (auto& blockInfo : blockPoolList) {
        assert(blockSize != blockInfo.blockSize);
    }
    char* poolBgn = new char[BlockPoolSize];
    BlockAlloc newPool;
    newPool.startUP(poolBgn, BlockPoolSize, blockSize);
    blockPoolList.push_back({newPool, poolBgn, BlockPoolSize, blockSize});
}

void* MemorySystem::alloc(uint32_t size) {
    void* result = nullptr;                             /*  prepare result                              */
    for (auto& entry : blockPoolList) {                 /*  search for matching block pool              */
        if (size <= entry.blockSize) {
            result = entry.pool.balloc();
            break;
        }
    }
    /*  if size request is too big => deligate      */
    if (!result) { result = new char[size]; }           /*  allocation to general purpose allocator     */
    return result;
}

void MemorySystem::free(void* ptr) {
    bool blockFound = false;
    for (auto& entry : blockPoolList) {                 /*  search for matching block pool              */
        char* begin = entry.poolPtr;
        char* end   = begin + entry.poolSize;
        if (begin <= ptr && ptr < end) {
            entry.pool.free(ptr);
            blockFound = true;
            break;
        }
    }
    if (!blockFound) { delete[] ptr; }                  /*  if not found - free from heap               */
}

void* MemorySystem::stalloc(uint32_t size) {
    void* result    = stackPool.stalloc(size);
    stackPoolMarker = stackPool.getMarker();
    return result;
}

void MemorySystem::stfree() { stackPool.free(); }

void* MemorySystem::galloc(uint32_t size) { return stackPool.LSRalloc(size); }

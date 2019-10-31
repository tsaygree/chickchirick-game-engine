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

uint32_t MemorySystem::startUP(bpt::ptree& config) {
    assert(isInit == false);
    /*  StackAlloc initialization   */
    /*  config stores size in MiB, so conversion to bytes needed    */
    uint32_t LSRSize  = MiBtoB(config.get<uint32_t>("LSRSize"));
    uint32_t poolSize = MiBtoB(config.get<uint32_t>("StackPoolSize"));
    stackPool.startUP(LSRSize, poolSize);
    /*  BlockAlloc initializations  */
    poolSize = MiBtoB(config.get<uint32_t>("BlockAllocPoolSize"));
    uint32_t blockSize = 0;
    for (const auto& item : config.get_child("BlockAllocBlockSizes")) {
        blockSize      = item.second.get_value<uint32_t>();
        char* poolBgn  = new char[poolSize];
        BlockAlloc newPool;
        newPool.startUP(poolBgn, poolSize, blockSize);
        blockPoolList.push_back({newPool, poolBgn, poolSize, blockSize});
    }
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

void* MemorySystem::alloc(uint32_t size) {
    void* result = nullptr;                             /*  prepare result                              */
    for (auto& entry : blockPoolList) {                 /*  search for matching block pool              */
        if (size <= entry.blockSize) {
            result = entry.pool.balloc();
            break;
        }
    }
    if (!result) {                                      /*  if size request is too big => deligate      */
        result = new char[size];                        /*  allocation to general purpose allocator     */
    }
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
    if (!blockFound) {  delete ptr; }                   /*  if not found - free from heap               */
}

void* MemorySystem::stalloc(uint32_t size) {
    void* result    = stackPool.stalloc(size);
    stackPoolMarker = stackPool.getMarker();
    return result;
}

void MemorySystem::stfree() {
    stackPool.free();
}

void* MemorySystem::galloc(uint32_t size) {
    return stackPool.LSRalloc(size);
}

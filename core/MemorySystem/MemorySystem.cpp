/*

    MemorySystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 10/10/2019.

*/

#include "MemorySystem.hpp"

MemorySystem::MemorySystem()  {}

MemorySystem& MemorySystem::getInstance() {
    static MemorySystem instance;
    return instance;
}

uint32_t MemorySystem::startUP(const char* filename) {
    bpt::ptree config =
        (ConfigManager::getInstance().getGlobalConfig(filename)).get_child("MemorySystem");

    /*  StackAlloc initialization   */
    /*  config stores size in MiB, so conversion to bytes needed    */
    uint32_t LSRSize  = MiBtoB(config.get<uint32_t>("LSRSize"));
    uint32_t poolSize = MiBtoB(config.get<uint32_t>("StackPoolSize"));
    stackPool.startUP(LSRSize, poolSize);
    /*  BlockAlloc initializations  */
    poolSize = MiBtoB(config.get<uint32_t>("BlockAllocPoolSize"));
    uint32_t blockSize = 0;
    for (const auto& item : config.get_child("BlockAllocBlockSizes")) {
        blockSize = item.second.get_value<uint32_t>();
        char* poolBgn = new char[poolSize];
        BlockAlloc newPool;
        newPool.startUP(poolBgn, poolSize, blockSize);
        blockPoolList.push_back({newPool, poolBgn, poolSize, blockSize});
    }
    return 0;
}

uint32_t MemorySystem::shutDown() {
    for (auto& entry : blockPoolList) {
        entry.pool.shutDown();
    }
    blockPoolList.empty();
    stackPool.shutDown();
    return 0;
}

StackAlloc& MemorySystem::getStackAlloc() const {
    return stackPool;
}

void* MemorySystem::alloc(uint32_t size) {
    void* result = nullptr;                             /*  prepare result                              */
    for (auto& entry : blockPoolList) {                     /*  search for matching block pool              */
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
    for (auto& entry : blockPoolList) {                     /*  search for matching block pool              */
        char* begin = entry.poolPtr;
        char* end = begin + entry.poolSize;
        if (begin <= ptr && ptr < end) {
            entry.pool.free(ptr);
            blockFound = true;
            break;
        }
    }
    if (!blockFound) {  delete ptr; }                   /*  if not found - free from heap               */
}

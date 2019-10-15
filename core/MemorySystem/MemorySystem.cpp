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
        blockPool.push_back({newPool, poolBgn, poolSize, blockSize});
    }
    return 0;
}

uint32_t MemorySystem::shutDown() {
    for (auto& entry : blockPool) {
        entry.pool.shutDown();
    }
    blockPool.empty();
    stackPool.shutDown();
    return 0;
}

StackAlloc& MemorySystem::getStackAlloc() const {
    return stackPool;
}

void* MemorySystem::alloc(uint32_t size) {
    void* result = nullptr;
    for (auto& entry : blockPool) {
        if (size <= entry.blockSize) {
            result = entry.pool.balloc();
        }
    }
    if (!result) {
        result = new char[size];
    }
    return result;
}

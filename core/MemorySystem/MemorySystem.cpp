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
    uint32_t LSRSize  = config.get<uint32_t>("LSRSize") * power(1024, 2);
    uint32_t poolSize = config.get<uint32_t>("StackPoolSize") * power(1024, 2);
    stackPool.startUP(LSRSize, poolSize);
    /*  BlockAlloc initializations  */
    poolSize = config.get<uint32_t>("BlockAllocPoolSize") * power(1024, 2);
    uint32_t blockSize = 0;
    for (const auto& item : config.get_child("BlockAllocBlockSizes")) {
        blockSize = item.second.get_value<uint32_t>();
        BlockAlloc newPool;
        newPool.startUP(poolSize, blockSize);
        blockPool[blockSize] = newPool;
    }
    return 0;
}

uint32_t MemorySystem::shutDown() {
    for (auto& bpool : blockPool) {
        bpool.second.shutDown();
    }
    stackPool.shutDown();
    return 0;
}

StackAlloc& MemorySystem::getStackAlloc() const {
    return stackPool;
}

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

    /*  config stores size in MiB, so conversion to bytes needed    */
    uint32_t LSRSize  = config.get<uint32_t>("LSRSize") * power(1024, 2);
    uint32_t poolSize = config.get<uint32_t>("StackPoolSize") * power(1024, 2);
    stackPool.startUP(LSRSize, poolSize);
    return 0;
}

uint32_t MemorySystem::shutDown() {
    stackPool.shutDown();
    return 0;
}

StackAlloc& MemorySystem::getStackAlloc() const {
    return stackPool;
}

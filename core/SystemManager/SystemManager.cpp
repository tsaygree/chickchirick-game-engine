/*

    SystemManager.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 13/09/2019.

*/

#include "SystemManager.hpp"

SystemManager::SystemManager() {}

SystemManager& SystemManager::getInstance() {
    static SystemManager instance;
    return instance;
}

uint32_t SystemManager::BigInit() {
    /*  brute force start up ordering */

    fileSys.startUP();
    conMan.startUP();
    bpt::ptree engineconfig = conMan.loadGlobalConfig(SID("engineconfig.json"));
    this->initMemorySystem(engineconfig.get_child("MemorySystem"));
    sdl.startUP(engineconfig.get_child("SDLConfig"));
    assMan.startUP(fileSys.getAssetsPath());
    inputHandler.startUP();
    gloop.startUP(engineconfig.get_child("GameLoop").get<uint8_t>("FPS"));

    return 0;
}

uint32_t SystemManager::BigShutDown() {
    /*  brute force start down ordering is strictly */
    /*  the reverse of BigInit ordering             */

    inputHandler.shutDown();
    assMan.shutDown();
    sdl.shutDown();
    memSys.shutDown();
    fileSys.shutDown();

    return 0;
}

uint32_t SystemManager::initMemorySystem(bpt::ptree& config) {
    uint32_t LSRSize       = MiBtoB(config.get<uint32_t>("LSRSizeMiB"));
    uint32_t StackPoolSize = MiBtoB(config.get<uint32_t>("StackPoolSizeMiB"));
    uint32_t BlockPoolSize = MiBtoB(config.get<uint32_t>("BlockAllocPoolSizeMiB"));
    uint32_t blockSize     = 0;
    memSys.startUP(LSRSize, StackPoolSize);
    for (const auto& item : config.get_child("BlockAllocBlockSizesB")) {
        blockSize = item.second.get_value<uint32_t>();
        memSys.addBlockPool(BlockPoolSize, blockSize);
    }
    return 0;
}

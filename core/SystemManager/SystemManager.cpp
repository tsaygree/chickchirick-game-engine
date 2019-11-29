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
    globalConfPath = fileSys.getGlobalConfPath();
    conMan.startUP();
    bpt::ptree engineconfig = conMan.loadGlobalConfig(SID("engineconfig.json"));
    memSys.startUP(engineconfig.get_child("MemorySystem"));
    sdl.startUP(engineconfig.get_child("SDLConfig"));
    assMan.startUP(fileSys.getAssetsPath());
    inputHandler.startUP();
    gloop.startUP(engineconfig.get_child("GameLoop"));
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

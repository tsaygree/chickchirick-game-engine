/*

    ConfigManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 21/09/2019.

*/

#include "ConfigManager.hpp"

ConfigManager::ConfigManager()  {}

ConfigManager& ConfigManager::getInstance() {
    static ConfigManager instance;
    return instance;
}

uint32_t ConfigManager::startUP() {
    /* find global config path  */
    FileSystem& fileSys = FileSystem::getInstance();
    const StringID& path = fileSys.getBasePath();
    string confPath = string(path.getPtr()) + "configs/";
    globalConfPath = STRINGHASH(confPath);

    /*  find local config path  */
    // path = fileSys.getPrefPath();
    // confPath = string(path.getPtr()) += "configs/";
    // localConfPath = STRINGHASH(confPath);
    return 0;
}

const StringID& ConfigManager::getGlobalConfPath() const {
    return globalConfPath;
}

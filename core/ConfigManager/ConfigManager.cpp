/*

    ConfigManager.cpp
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
    globalConfPath = fileSys.getGlobalConfPath();
    return 0;
}

const bpt::ptree& ConfigManager::loadGlobalConfig(const StringID& filename) {
    StringID filepath = globalConfPath + filename;
    return fileSys.readJSON(filepath.getPtr());
}

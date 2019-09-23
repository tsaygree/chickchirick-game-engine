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
    return 0;
}

/*

    AssetManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

*/

#include "AssetManager.hpp"

AssetManager::AssetManager()  {}

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

int AssetManager::startUP(const StringID& assetsPath_) {
    this->assetsPath = assetsPath_;
    return 0;
}

int AssetManager::shutDown() {  return 0;  }

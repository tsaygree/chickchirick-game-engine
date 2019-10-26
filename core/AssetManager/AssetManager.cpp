/*

    AssetManager.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

*/

#include "AssetManager.hpp"

AssetManager::AssetManager()  {}

SDL_Texture* AssetManager::loadImageToTexture(const char* filepath) {
    auto& fs  = FileSystem::getInstance();
    auto& sdl = SDLModule::getInstance();
    SDL_Surface* surface = fs.loadIMG(filepath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl.getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

int AssetManager::startUP(const StringID& assetsPath_) {
    this->assetsPath = assetsPath_;
    return 0;
}

int AssetManager::shutDown() {  return 0;  }

Texture* AssetManager::loadTexture(const StringID& name) {
    Texture* result = nullptr;
    if (resRegistry.count(name) == 0) {
        string filepath = assetsPath.getStr() + name.getStr();
        SDL_Texture* texture = this->loadImageToTexture(filepath.c_str());
        result  = CAST(Texture*, mem.stalloc(sizeof(Texture)));
        *result = Texture(texture, name);
        resRegistry[name] = STCAST(Asset*, result);
    }
    return result;
}

Asset* AssetManager::getAsset(const StringID& name) {
    Asset* result = nullptr;
    if (resRegistry.count(name) == 1) {
        result = resRegistry.at(name);
    }
    return result;
}

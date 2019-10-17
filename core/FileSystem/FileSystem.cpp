/*

    FileSystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

*/

#include "FileSystem.hpp"

FileSystem::FileSystem()  {}

FileSystem& FileSystem::getInstance() {
    static FileSystem instance;
    return instance;
}

uint32_t FileSystem::startUP() {
    /*  find hidden appdata directory path */
    // string pathStr = SDL_GetLocalPath("", "");
    // localPath = SHID(pathStr.c_str());
    return 0;
}

uint32_t FileSystem::shutDown() {   return 0;  }

const StringID& FileSystem::getBasePath()       const   {   return basePath;        }

// const StringID& FileSystem::getLocalPath()      const   {   return localPath;       }

const StringID& FileSystem::getGlobalConfPath() const   {   return globalConfPath;  }

// const StringID& FileSystem::getLocalConfPath()  const   {   return localConfPath;   }

const StringID& FileSystem::getAssetsPath()     const   {   return assetsPath;      }

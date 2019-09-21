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

int FileSystem::startUP() {
    /*  find engine base directory path */
    std::string PathStr = SDL_GetBasePath();
    size_t pos = PathStr.rfind("bin");
    PathStr = PathStr.substr(0, pos);
    const char* PathPtr = PathStr.c_str();
    basePath = StringID(hashCrc32(PathPtr), PathPtr);

    /*  find hidden appdata directory path */
    // PathStr = SDL_GetPrefPath("", "");
    // prefPath = StringID(hashCrc32(PathStr), PathStr);
    return 0;
}

int FileSystem::shutDown() {}

bpt::ptree& FileSystem::parseJSON(const char* filename) {
    bpt::read_json(filename, pt);
    return pt;
}

StringID& FileSystem::getBasePath() {   return basePath;    }

// StringID& FileSystem::getPrefPath() {}

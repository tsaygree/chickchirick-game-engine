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

int FileSystem::startUP() {}

int FileSystem::shutDown() {}

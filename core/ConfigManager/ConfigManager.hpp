/*

    ConfigManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 21/09/2019.

    DESCRIPTION:
    Tiny singleton module to operate on configuration files.
    It uses FileSystem module to load files and then applies
    changes to different systems in the engine.
*/

#pragma once
#include <SDL.h>
#include "FileSystem.hpp"
#include "StringID.hpp"

class ConfigManager {
private:
    FileSystem& fileSys = FileSystem::getInstance();
    StringID globalConfPath;
    ConfigManager();
public:
    static ConfigManager& getInstance();
    uint32_t startUP();
};

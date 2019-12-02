/*

    ConfigManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 21/09/2019.

    DESCRIPTION:
    Tiny singleton module to operate on configuration files.
    It uses FileSystem module to resolve a full filepath,
    load config file and parse it.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "FileSystem.hpp"
#include "StringID.hpp"
#include <SDL.h>

class ConfigManager {
private:
    FileSystem& fileSys = FileSystem::getInstance();
    StringID    globalConfPath;
    ConfigManager();
public:
    ConfigManager(ConfigManager const&)            = delete;
    ConfigManager& operator=(ConfigManager const&) = delete;
    static ConfigManager& getInstance();                              /*  get singleton object            */
    uint32_t startUP();                                               /*  start up                        */
    const bpt::ptree& loadGlobalConfig(const StringID& filename);     /*  load and parse config file      */
};

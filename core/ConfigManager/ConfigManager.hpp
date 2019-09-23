/*

    ConfigManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 21/09/2019.

    DESCRIPTION:
    Tiny singleton module to operate on configuration files.
*/

#pragma once
#include "FileSystem.hpp"
#include "StringID.hpp"

class ConfigManager {
private:
    /*
        path to global configuration JSON file.
        it includes, but not limited to:
        core engine configuration (SDL & subsystems),
        gameplay configuration (player stats, game design, etc.)
        default game options
    */
    StringID globalConfPath;
    /*
        path to local configuration JSON file.
        it includes, but not limited to:
        user-defined game options
    */
    // StringID localConfPath;
    ConfigManager();
public:
    static ConfigManager& getInstance();
    int startUP();
    const StringID& getGlobalConfPath() const;
};

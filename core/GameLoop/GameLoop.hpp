/*

    GameLoop.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 31/10/2019.

    DESCRIPTION:

*/

#pragma once
#include "PropertyTree.hpp"
#include "AssetManager.hpp"
#include <cstdio>

class GameLoop {
private:
    double      msPerUpdate = 0.0f;
    bool        isRunning   = false;
    GameLoop();
public:
    GameLoop(GameLoop const&)            = delete;
    GameLoop& operator=(GameLoop const&) = delete;
    static GameLoop& getInstance();
    uint32_t startUP(bpt::ptree& config);
    void     run();
    uint32_t shutDown();
    ~GameLoop();
};

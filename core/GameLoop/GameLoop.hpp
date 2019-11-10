/*

    GameLoop.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 31/10/2019.

    DESCRIPTION:
    GameLoop is a singleton class that implements
    game loop design pattern.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "PropertyTree.hpp"
#include "AssetManager.hpp"
#include "InputHandler.hpp"
#include "Timer.hpp"
#include <cstdio>

class GameLoop {
private:
    InputHandler& inputHandler = InputHandler::getInstance();
    Timer         timer;
    double        msPerUpdate  = 0.0f;
    bool          isRunning    = false;
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

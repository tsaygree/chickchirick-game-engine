/*

    GameLoop.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 31/10/2019.

*/

#include "GameLoop.hpp"

GameLoop::GameLoop()  {}

GameLoop::~GameLoop() {}

GameLoop& GameLoop::getInstance() {
    static GameLoop instance;
    return instance;
}

uint32_t GameLoop::startUP(bpt::ptree& config) {
    uint8_t fps = config.get<uint8_t>("FPS");
    msPerUpdate = 1.0f / fps;
    return 0;
}

uint32_t GameLoop::shutDown() { return 0; }

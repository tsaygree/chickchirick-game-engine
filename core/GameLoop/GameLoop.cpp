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
    isRunning = true;
    return 0;
}

void GameLoop::run() {
    uint32_t currentTime  = SDL_GetTicks();
    uint32_t previousTime = currentTime;
    uint32_t elapsedTime  = currentTime - previousTime;
    double lag = 0.0f;
    double interpolation;

    while (isRunning) {
        currentTime  = SDL_GetTicks();
        elapsedTime  = currentTime - previousTime;
        previousTime = currentTime;
        lag += elapsedTime;

        /*  input handling          */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
        }
        /*  update handling         */
        while (lag >= msPerUpdate) {
            lag -= msPerUpdate;
        }
        interpolation = lag / msPerUpdate;
        /*  render handling         */
    }
}

uint32_t GameLoop::shutDown() {
    isRunning = false;
    return 0;
}

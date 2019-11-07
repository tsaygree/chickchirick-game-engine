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
    timer.reset();
    double lag = 0.0f;
    double interpolation;

    /*  for demonstration purposes only, might delete later :P */
    SDL_Renderer* renderer = SDLModule::getInstance().getRenderer();
    Texture* logoTex = AssetManager::getInstance().loadAssetAs<Texture>(SID("logo.png"));
    SDL_Event event;

    while (isRunning) {
        lag += timer.timePassed();
        timer.reset();

        /*  input handling          */
        
        /*  update handling         */
        while (lag >= msPerUpdate) {
            lag -= msPerUpdate;
        }
        interpolation = lag / msPerUpdate;
        /*  render handling         */
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, logoTex->texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
}

uint32_t GameLoop::shutDown() {
    isRunning = false;
    return 0;
}

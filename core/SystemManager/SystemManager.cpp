/*

    SystemManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 13/09/2019.

*/

#include "SystemManager.hpp"

SystemManager::SystemManager() {}

SystemManager& SystemManager::getInstance() {
    static SystemManager instance;
    return instance;
}

uint32_t SystemManager::BigInit() {
    fileSys.startUP();

    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << SDL_GetError() << std::endl;
    }
    if ((IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        return 1;
    }
    window = SDL_CreateWindow("CHANGE ME PLEASE", 100, 100, 1920, 1080, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (renderer == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_SetRenderDrawColor(renderer, 0xAA, 0xFF, 0xFF, 0xFF);
    return 0;
}

uint32_t SystemManager::BigShutDown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

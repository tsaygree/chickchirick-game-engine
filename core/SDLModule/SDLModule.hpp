/*

    SDLModule.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

    DESCRIPTION:

*/

#pragma once
#include <SDL.h>
#include <SDL_image.h>

class SDLModule {
private:
    SDLModule();
public:
    static SDLModule& getInstance();
};

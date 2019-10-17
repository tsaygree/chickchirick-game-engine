/*

    SDLModule.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

    DESCRIPTION:

*/

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Initializers.hpp"
#include "ConfigManager.hpp"
#include "Texture.hpp"
#include <iostream>

class SDLModule {
private:
    SDLModule();
    const SIDTable<uint32_t> SDLFlagLookUp = SDLFLG;                /*  SDL flags lookup table          */
    SDL_Window*     window;
    SDL_Renderer*   renderer;
public:
    static SDLModule& getInstance();
    uint32_t startUP(const char* filename);
    uint32_t shutDown();
    Texture getTextureFromSurface(SDL_Surface* surface, const StringID& id);
    inline SDL_Window*   getWindow()        const { return window;                       }
    inline SDL_Renderer* getRenderer()      const { return renderer;                     }
    inline SDL_Surface*  getWindowSurface() const { return SDL_GetWindowSurface(window); }
};

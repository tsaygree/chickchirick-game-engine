/*

    SDLModule.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

    DESCRIPTION:

*/

#pragma once
#include "SDLInclude.hpp"
#include "Initializers.hpp"
#include "PropertyTree.hpp"
#include "StringID.hpp"
#include <cstdio>
#include <iostream>

class SDLModule {
private:
    SDLModule();
    const SIDTable<uint32_t> SDLFlagLookUp = SDLFLG;                /*  SDL flags lookup table          */
    SDL_Window*              window;
    SDL_Renderer*            renderer;
    SDL_Event                event;
public:
    SDLModule(SDLModule const&)            = delete;
    SDLModule& operator=(SDLModule const&) = delete;
    static SDLModule& getInstance();
    uint32_t startUP(bpt::ptree& config);
    uint32_t shutDown();
    inline SDL_Window*   getWindow()        const { return window;                       }
    inline SDL_Renderer* getRenderer()      const { return renderer;                     }
    inline const SDL_Event&     getEvent()         const { return event;                        }
    inline SDL_Surface*  getWindowSurface() const { return SDL_GetWindowSurface(window); }
};

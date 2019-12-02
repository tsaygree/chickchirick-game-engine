/*

    Timer.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 07/11/2019.

    DESCRIPTION:
    NOTE: This class is not thread safe.

*/

#pragma once
#include "SDLInclude.hpp"
#include <cstdint>

class Timer {
private:
    uint32_t beginTicks = 0;
public:
    Timer() : beginTicks(SDL_GetTicks()) {}
    ~Timer() {}
    uint32_t timePassed() { return SDL_GetTicks() - beginTicks; }
    uint32_t getTime()    { return SDL_GetTicks();              }
    uint32_t reset() {
        beginTicks = SDL_GetTicks();
        return beginTicks;
    }
};

/*

    Timer.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 07/11/2019.

*/

#include "Timer.hpp"

Timer::Timer() : beginTicks(SDL_GetTicks()) {}

Timer::~Timer() {}

uint32_t Timer::getTime() {
    return SDL_GetTicks();
}

uint32_t Timer::reset() {
    beginTicks = SDL_GetTicks();
    return beginTicks;
}

uint32_t Timer::timePassed() {
    return SDL_GetTicks() - beginTicks;
}

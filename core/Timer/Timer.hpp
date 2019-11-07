/*

    Timer.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 07/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "SDLInclude.hpp"
#include <cstdint>

class Timer {
private:
    uint32_t beginTicks = 0;
public:
    Timer();
    ~Timer();
    uint32_t getTime();
    uint32_t reset();
    uint32_t timePassed();
};

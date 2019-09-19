/*

    SystemManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 13/09/2019.

    DESCRIPTION:
    System Manager is a singleton object that
    starts up, controlls and shuts down
    every chickchirik game engine subsystem.

*/

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "StringID.hpp"
#include <iostream>
#include <cstdio>

class SystemManager {
private:
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SystemManager();
public:
    static SystemManager& getInstance();
    int BigInit();
    int BigShutDown();
};

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
#include "FileSystem.hpp"
#include "AssetManager.hpp"
#include "Initializers.hpp"
#include <iostream>
#include <cstdio>


class SystemManager {
private:
    FileSystem&     fileSys = FileSystem::getInstance();
    AssetManager&   assMan  = AssetManager::getInstance();
    const SIDTable<uint32_t> SDLFlagLookUp = SDLFLG;                /*  SDL flags lookup table          */
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SystemManager();
public:
    static SystemManager& getInstance();
    uint32_t BigInit();                                             /*  All subsystems are started here     */
    uint32_t BigShutDown();                                         /*  All subsystems are shutted here     */
    uint32_t SDLInit(const char* filename);                         /*  SDL initialization routine          */
    uint32_t SDLShutDown();                                         /*  SDL clearing routine                */
};

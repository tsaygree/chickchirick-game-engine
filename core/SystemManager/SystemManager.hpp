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
#include "ConfigManager.hpp"
#include <iostream>
#include <cstdio>
#include <unordered_map>

template <typename V>
using SIDTable = std::unordered_map<StringID, V, SIDHashFunc>;

#define SDLFLG {\
    {SID("SDL_INIT_TIMER")                          ,SDL_INIT_TIMER},\
    {SID("SDL_INIT_AUDIO")                          ,SDL_INIT_AUDIO},\
    {SID("SDL_INIT_VIDEO")                          ,SDL_INIT_VIDEO},\
    {SID("SDL_INIT_JOYSTICK")                       ,SDL_INIT_JOYSTICK},\
    {SID("SDL_INIT_HAPTIC")                         ,SDL_INIT_HAPTIC},\
    {SID("SDL_INIT_GAMECONTROLLER")                 ,SDL_INIT_GAMECONTROLLER},\
    {SID("SDL_INIT_EVENTS")                         ,SDL_INIT_EVENTS},\
    {SID("SDL_INIT_EVERYTHING")                     ,SDL_INIT_EVERYTHING},\
    {SID("SDL_INIT_NOPARACHUTE")                    ,SDL_INIT_NOPARACHUTE},\
    {SID("IMG_INIT_JPG")                            ,IMG_INIT_JPG},\
    {SID("IMG_INIT_PNG")                            ,IMG_INIT_PNG},\
    {SID("IMG_INIT_TIF")                            ,IMG_INIT_TIF},\
    {SID("SDL_WINDOW_FULLSCREEN")                   ,SDL_WINDOW_FULLSCREEN},\
    {SID("SDL_WINDOW_FULLSCREEN_DESKTOP")           ,SDL_WINDOW_FULLSCREEN_DESKTOP},\
    {SID("SDL_WINDOW_OPENGL")                       ,SDL_WINDOW_OPENGL},\
    {SID("SDL_WINDOW_VULKAN")                       ,SDL_WINDOW_VULKAN},\
    {SID("SDL_WINDOW_HIDDEN")                       ,SDL_WINDOW_HIDDEN},\
    {SID("SDL_WINDOW_BORDERLESS")                   ,SDL_WINDOW_BORDERLESS},\
    {SID("SDL_WINDOW_RESIZABLE")                    ,SDL_WINDOW_RESIZABLE},\
    {SID("SDL_WINDOW_MINIMIZED")                    ,SDL_WINDOW_MINIMIZED},\
    {SID("SDL_WINDOW_MAXIMIZED")                    ,SDL_WINDOW_MAXIMIZED},\
    {SID("SDL_WINDOW_INPUT_GRABBED")                ,SDL_WINDOW_INPUT_GRABBED},\
    {SID("SDL_WINDOW_ALLOW_HIGHDPI")                ,SDL_WINDOW_ALLOW_HIGHDPI},\
    {SID("SDL_RENDERER_SOFTWARE")                   ,SDL_RENDERER_SOFTWARE},\
    {SID("SDL_RENDERER_ACCELERATED")                ,SDL_RENDERER_ACCELERATED},\
    {SID("SDL_RENDERER_PRESENTVSYNC")               ,SDL_RENDERER_PRESENTVSYNC},\
    {SID("SDL_RENDERER_TARGETTEXTURE")              ,SDL_RENDERER_TARGETTEXTURE},\
}

class SystemManager {
private:
    FileSystem&     fileSys = FileSystem::getInstance();
    ConfigManager&  configMan = ConfigManager::getInstance();
    const SIDTable<uint32_t> SDLFlagLookUp = SDLFLG;                /*  SDL flags lookup table      */
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SystemManager();
public:
    static SystemManager& getInstance();
    uint32_t BigInit();
    uint32_t BigShutDown();
    uint32_t SDLInit(const char* filename);
    uint32_t SDLShutDown();
};

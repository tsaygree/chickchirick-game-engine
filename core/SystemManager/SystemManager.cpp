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
    /*  brute force start up ordering */
    fileSys.startUP();
    this->SDLInit("sdlconfig.json");
    return 0;
}

uint32_t SystemManager::BigShutDown() {
    /*  brute force start down ordering is strictly */
    /*  the reverse of BigInit ordering             */
    this->SDLShutDown();
    fileSys.shutDown();
    return 0;
}

uint32_t SystemManager::SDLInit(const char* filename) {
    string filepath = fileSys.getGlobalConfPath().getStr() + filename;
    bpt::ptree sdlFlags = fileSys.readJSON(filepath.c_str());

    /*  lambda to retrieve SDL flags from property tree data structure  */
    auto getFlags = [&](const auto& flags) {
        uint32_t result = 0;
        for (const auto& flag : flags) {
            uint32_t isSet = flag.second.template get_value<uint32_t>();
            if (isSet) {
                StringID key = SHID(flag.first.c_str());
                result |= SDLFlagLookUp.at(key);
            }
        }
        return result;
    };

    uint32_t flags = getFlags(sdlFlags.get_child("sdl_init.flags"));
    if (SDL_Init(flags)) {
        std::cerr << SDL_GetError() << std::endl;
    }

    flags = getFlags(sdlFlags.get_child("img_init.flags"));
    if((IMG_Init(flags)&flags) != flags) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bpt::ptree& sdlSubSysFlags = sdlFlags.get_child("window");
    window = SDL_CreateWindow(
        sdlSubSysFlags.get<std::string>("title").c_str(),
        sdlSubSysFlags.get<int32_t>("xpos"),
        sdlSubSysFlags.get<int32_t>("ypos"),
        sdlSubSysFlags.get<int32_t>("width"),
        sdlSubSysFlags.get<int32_t>("height"),
        getFlags(sdlSubSysFlags.get_child("flags"))
    );
    if (window == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    sdlSubSysFlags = sdlFlags.get_child("renderer");
    renderer = SDL_CreateRenderer(
        window,
        sdlSubSysFlags.get<int32_t>("index"),
        getFlags(sdlSubSysFlags.get_child("flags"))
    );
    if (renderer == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    sdlSubSysFlags = sdlFlags.get_child("rendererdrawcolor");
    SDL_SetRenderDrawColor(
        renderer,
        sdlSubSysFlags.get<uint32_t>("red"),
        sdlSubSysFlags.get<uint32_t>("green"),
        sdlSubSysFlags.get<uint32_t>("blue"),
        sdlSubSysFlags.get<uint32_t>("alpha")
    );
    return 0;
}

uint32_t SystemManager::SDLShutDown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

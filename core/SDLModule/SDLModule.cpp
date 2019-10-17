/*

    SDLModule.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

*/

#include "SDLModule.hpp"

SDLModule::SDLModule()  {}

SDLModule& SDLModule::getInstance() {
    static SDLModule instance;
    return instance;
}

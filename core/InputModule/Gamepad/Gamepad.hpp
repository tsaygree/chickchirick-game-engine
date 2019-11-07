/*

    Gamepad.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "SDLModule.hpp"
#include <cstdint>

class Gamepad {
private:
    SDL_GameController* controller  = nullptr;
    SDL_JoystickID      id;
    bool                connected   = false;
public:
    Gamepad();
    ~Gamepad();
    inline bool isConnected() const { return connected; }
    uint32_t connect(uint32_t deviceID);
    uint32_t disconnect();
};

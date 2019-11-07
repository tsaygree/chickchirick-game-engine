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
    SDL_JoystickID      instanceID;
    bool                connected   = false;
public:
    Gamepad();
    ~Gamepad();
    inline bool isConnected() const { return connected; }
    inline SDL_JoystickID getInstanceID() const { return instanceID; }
    uint32_t connect(uint32_t deviceID);
    uint32_t disconnect();
};

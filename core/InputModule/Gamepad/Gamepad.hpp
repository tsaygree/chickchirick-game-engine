/*

    Gamepad.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

    DESCRIPTION:
    Gamepad module represents single hardware device
    that is connected to the system and detected by
    the game engine.

*/

#pragma once
#include "SDLModule.hpp"
#include <cstdint>

class Gamepad {
private:
    SDL_GameController* controller  = nullptr;
    SDL_JoystickID      instanceID;
    int32_t             hardwareID;
    bool                connected   = false;
public:
    Gamepad();
    ~Gamepad();
    inline bool isConnected() const { return connected; }                   /*  returns connection status               */
    inline int32_t getHardwareID() const { return hardwareID; }             /*  returns hardware pad id                 */
    inline SDL_JoystickID getInstanceID() const { return instanceID; }      /*  returns virtual engine pad id           */
    uint32_t connect(uint32_t deviceID);                                    /*  attempts to connect the controller      */
    uint32_t disconnect();                                                  /*  attemts to disconnect the controller    */
};

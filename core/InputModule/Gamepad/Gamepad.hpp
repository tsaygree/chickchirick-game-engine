/*

    Gamepad.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

    DESCRIPTION:
    Gamepad module represents single hardware device
    that is connected to the system and detected by
    the game engine. Gamepad class implements InputDevice
    interface.

*/

#pragma once
#include "InputDevice.hpp"
#include "SDLModule.hpp"
#include <cstdint>

class Gamepad : public InputDevice {
private:
    SDL_GameController* controller  = nullptr;
    SDL_JoystickID      instanceID;
    int32_t             hardwareID;
    bool                connected   = false;
public:
    Gamepad();
    ~Gamepad();
    virtual inline DeviceType getType() const { return DeviceType::GAMEPAD; }
    inline bool isConnected() const { return connected; }                   /*  returns connection status               */
    inline int32_t getHardwareID() const { return hardwareID; }             /*  returns hardware pad id                 */
    inline SDL_JoystickID getInstanceID() const { return instanceID; }      /*  returns virtual engine pad id           */
    uint32_t connect(uint32_t deviceID);                                    /*  attempts to connect the controller      */
    uint32_t disconnect();                                                  /*  attemts to disconnect the controller    */
};

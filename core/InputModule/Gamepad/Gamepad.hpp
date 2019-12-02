/*

    Gamepad.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

    DESCRIPTION:
    Gamepad module represents single hardware device
    that is connected to the system and detected by
    the game engine. Gamepad class implements InputDevice
    interface.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "InputDevice.hpp"
#include "SDLModule.hpp"
#include <cstdint>

class Gamepad : public InputDevice {
private:
    SDL_JoystickID      instanceID;
    SDL_GameController* controller  = nullptr;
    int32_t             hardwareID;
    bool                connected   = false;
public:
    Gamepad();
    ~Gamepad();
    inline DeviceType getType()  const override { return DeviceType::GAMEPAD; }
    inline SDL_JoystickID getInstanceID() const { return instanceID; }      /*  returns virtual engine pad id           */
    inline int32_t getHardwareID()        const { return hardwareID; }      /*  returns hardware pad id                 */
    inline bool isConnected()             const { return connected;  }      /*  returns connection status               */
    uint32_t connect(uint32_t deviceID);                                    /*  attempts to connect the controller      */
    uint32_t disconnect();                                                  /*  attemts to disconnect the controller    */
};

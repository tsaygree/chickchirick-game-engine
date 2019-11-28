/*

    InputDevice.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 11/11/2019.

    DESCRIPTION:
    InputDevice is an interface for various I/O devices
    that are supported by the engine (keyboard, mouse, joystick, gamepad).
    It specifies device type.
    TODO: API for user-defined callback for processing input information.
    i.e. gamepad only knows how to connect and disconnect, but not how to
    process input information. That's left for user implementation.

*/

#pragma once
#include "SDLInclude.hpp"
#include "RingBuffer.hpp"
#include "StringID.hpp"
#include <functional>

class InputDevice {
private:
    RingBuffer<StringID> commands{100};
public:
    enum class DeviceType {
        GAMEPAD,
        JOYSTICK,
        KEYBOARD,
        MOUSE
        //MICRO ???
    };
    virtual inline DeviceType getType() const = 0;
    void processInput(SDL_Event& event) {}
    inline  void pushCommand(StringID cmd)   { commands.push(cmd);        }
    inline  Vector<StringID> popCommands()   { return commands.popAll();  }
};

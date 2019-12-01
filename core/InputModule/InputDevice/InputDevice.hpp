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
    std::function<StringID(SDL_Event&)> cmdCB;
    RingBuffer<StringID> commands{100};
public:
    enum class DeviceType {
        GAMEPAD,
        JOYSTICK,
        KEYBOARD,
        MOUSE
        //MICRO ???
    };
    InputDevice() { cmdCB = [](SDL_Event& event) { return SID(""); }; }
    ~InputDevice() { commands.clear(); }
    virtual inline DeviceType getType() const = 0;
    inline void setCmdProcCallBack(std::function<StringID(SDL_Event&)> newCmdCB) { cmdCB = newCmdCB; }
    inline void processInput(SDL_Event& event) { commands.push(cmdCB(event)); }
    inline  Vector<StringID> popCommands()   { return commands.popAll();  }
    inline void clearCommands() { commands.clear(); }
};

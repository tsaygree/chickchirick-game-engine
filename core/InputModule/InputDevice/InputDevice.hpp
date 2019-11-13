/*

    InputDevice.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 11/11/2019.

    DESCRIPTION:

*/

#pragma once


class InputDevice {
private:
public:
    enum class DeviceType {
        GAMEPAD,
        JOYSTICK,
        KEYBOARD,
        MOUSE
        //MICRO ???
    };
    virtual inline DeviceType getType() const = 0;
};

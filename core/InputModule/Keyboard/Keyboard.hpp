/*

    Keyboard.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 26/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "InputDevice.hpp"

class Keyboard : public InputDevice {
private:
public:
    Keyboard ();
    ~Keyboard();
    inline DeviceType getType() const override { return DeviceType::KEYBOARD; }
};

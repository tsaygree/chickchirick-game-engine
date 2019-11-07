/*

    Gamepad.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

*/

#include "Gamepad.hpp"

Gamepad::Gamepad()  {}

Gamepad::~Gamepad() {}

uint32_t Gamepad::connect(uint32_t deviceID) {
    assert(connected == false);
    if (SDL_IsGameController(deviceID)) {
        controller = SDL_GameControllerOpen(deviceID);
        SDL_Joystick* joyStick = SDL_GameControllerGetJoystick(controller);
        instanceID = SDL_JoystickInstanceID(joyStick);
        connected = true;
    }
}

uint32_t Gamepad::disconnect() {
    assert(connected == true);
    SDL_GameControllerClose(controller);
    connected = false;
}

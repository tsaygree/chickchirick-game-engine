/*

    Gamepad.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

*/

#include "Gamepad.hpp"

Gamepad::Gamepad()  {}

Gamepad::~Gamepad() {}

uint32_t Gamepad::connect(uint32_t deviceID) {
    assert(isConnected == false);
    if (SDL_IsGameController(deviceID)) {
        controller = SDL_GameControllerOpen(deviceID);
        SDL_Joystick* joyStick = SDL_GameControllerGetJoystick(controller);
        id = SDL_JoystickInstanceID(joyStick);
        isConnected = true;
    }
}

uint32_t Gamepad::disconnect() {
    assert(isConnected == true);
    SDL_GameControllerClose(controller);
    isConnected = false;
}

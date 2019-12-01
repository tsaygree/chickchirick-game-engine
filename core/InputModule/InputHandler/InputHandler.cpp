/*

    InputHandler.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/11/2019.

*/

#include "InputHandler.hpp"

InputHandler::InputHandler() {}

InputHandler::~InputHandler() {}

InputHandler& InputHandler::getInstance() {
    static InputHandler instance;
    return instance;
}

void InputHandler::addDevice(int32_t deviceID) {
    /*  not very happy with the solution, but gets the job done :D  */
    bool isFound = false;
    for (auto& device : padRegistry) {
        if (device.second->getHardwareID() == deviceID) {
            isFound = true;
        }
    }
    if (isFound == false) {
        Gamepad* newController = new (mem.alloc(sizeof(Gamepad))) Gamepad();
        newController->connect(deviceID);
        padRegistry[newController->getInstanceID()] = newController;
        if (mainDevice == keyboard) { mainDevice = newController; }
    }
}

void InputHandler::removeDevice(SDL_JoystickID instanceID) {
    auto controllerIt = padRegistry.find(instanceID);
    if (controllerIt != padRegistry.end()) {
        Gamepad* pad = controllerIt->second;
        if (pad == mainDevice) { mainDevice = keyboard; }
        pad->disconnect();
        pad->~Gamepad();
        mem.free(pad);
        padRegistry.erase(controllerIt);
    }
}

uint32_t InputHandler::startUP() {
    keyboard = new (mem.alloc(sizeof(Keyboard))) Keyboard();
    uint32_t numOfJoysticks = SDL_NumJoysticks();
    uint32_t deviceID = 0;
    while (deviceID < numOfJoysticks) {
        this->addDevice(deviceID);
        deviceID++;
    }
    if (padRegistry.empty()) { mainDevice = keyboard; }
    return 0;
}

uint32_t InputHandler::shutDown() {
    Gamepad* pad;
    for (auto& device : padRegistry) {
        pad = device.second;
        if (pad) {
            pad->disconnect();
            mem.free(pad);
        }
    }
    padRegistry.clear();
    if (keyboard) {
        keyboard->~Keyboard();
        mem.free(keyboard);
    }
    mainDevice = nullptr;
    return 0;
}

void InputHandler::processInput(SDL_Event& event) {
    switch (event.type) {
        case SDL_CONTROLLERDEVICEADDED: {
            this->addDevice(event.cdevice.which);
            break;
        }
        case SDL_CONTROLLERDEVICEREMOVED: {
            this->removeDevice(event.cdevice.which);
            break;
        }
        case SDL_CONTROLLERBUTTONDOWN: {
            padRegistry[event.cbutton.which]->processInput(event);
            break;
        }
        case SDL_KEYDOWN: {
            keyboard->processInput(event);
            break;
        }
        default: {
            break;
        }
    }
}

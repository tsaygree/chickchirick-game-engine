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
    for (auto& device : deviceRegistry) {
        if (device.second->getHardwareID() == deviceID) {
            isFound = true;
        }
    }
    if (isFound == false) {
        Gamepad* newController = CAST(Gamepad*, mem.alloc(sizeof(Gamepad)));
        newController->connect(deviceID);
        deviceRegistry[newController->getInstanceID()] = newController;
    }
}

void InputHandler::removeDevice(SDL_JoystickID instanceID) {
    auto controllerIt = deviceRegistry.find(instanceID);
    if (controllerIt != deviceRegistry.end()) {
        controllerIt->second->disconnect();
        deviceRegistry.erase(controllerIt);
    }
}

uint32_t InputHandler::startUP() {
    uint32_t numOfJoysticks = SDL_NumJoysticks();
    uint32_t deviceID = 0;

    while (deviceID < numOfJoysticks) {
        this->addDevice(deviceID);
        deviceID++;
    }
}

uint32_t InputHandler::shutDown() {
    Gamepad* pad;
    for (auto& device : deviceRegistry) {
        pad = device.second;
        if (pad) {
            pad->disconnect();
            mem.free(pad);
        }
    }
    deviceRegistry.clear();
}

void InputHandler::processInput(SDL_Event& event) {
    switch (event.type) {
        case SDL_CONTROLLERDEVICEADDED: {
            this->addDevice(event.cdevice.which);
            break;
        }
        default: {
            break;
        }
    }
}

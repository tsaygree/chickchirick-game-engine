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

uint32_t InputHandler::startUP(bpt::ptree& config) {
    uint32_t maxDevice = config.get<uint32_t>("MaxDeviceCount");
    deviceRegistry.resize(maxDevice);
    uint32_t numOfJoysticks = SDL_NumJoysticks();
    uint32_t deviceID = 0;

    while (deviceID < numOfJoysticks && deviceID < maxDevice) {
        Gamepad* newController = CAST(Gamepad*, mem.alloc(sizeof(Gamepad)));
        newController->connect(deviceID);
        deviceRegistry[deviceID] = newController;
        deviceID++;
    }
}

uint32_t InputHandler::shutDown() {
    for (Gamepad* pad : deviceRegistry) {
        if (pad) {
            pad->disconnect();
            mem.free(pad);
        }
    }
    deviceRegistry.clear();
}

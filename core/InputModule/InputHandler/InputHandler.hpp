/*

    InputHandler.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/11/2019.

    DESCRIPTION:
    InputHandler is a singleton class that manages all the
    input coming to the game engine, detects controller connections
    and disconnections, registers and initializes them. It is also
    responsible for routing input to specific devices.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "MemorySystem.hpp"
#include "PropertyTree.hpp"
#include "SDLModule.hpp"
#include "Gamepad.hpp"
#include "HashTable.hpp"
#include <unordered_set>
#include <cstdint>
#include <cstdio>

class InputHandler {
private:
    MemorySystem& mem = MemorySystem::getInstance();
    HashTable<SDL_JoystickID, Gamepad*> padRegistry;
    void addDevice(int32_t deviceID);
    void removeDevice(SDL_JoystickID instanceID);
    InputHandler();
public:
    InputHandler(InputHandler const&)            = delete;
    InputHandler& operator=(InputHandler const&) = delete;
    static InputHandler& getInstance();
    ~InputHandler();
    uint32_t startUP();
    uint32_t shutDown();
    void processInput(SDL_Event& event);
};

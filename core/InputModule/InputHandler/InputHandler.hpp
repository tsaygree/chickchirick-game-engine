/*

    InputHandler.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/11/2019.

    DESCRIPTION:
    InputHandler is a singleton class that manages all the
    input coming to the game engine, detects controller connections
    and disconnections, registers and initializes them. It is also
    responsible for routing input to specific devices.
    InputHandler also knows which device is main at the moment.
    Main device is a device that is currently responsible for
    processing incoming input. InputHandler is designed in a way
    that it gives the priority to gamepad devices and it does not
    segregate different keyboards (meaning that every keyboard
    connected to the PC/console is treated by the engine
    as the same input device).
    NOTE: This class is not thread safe.

*/

#pragma once
#include "MemorySystem.hpp"
#include "PropertyTree.hpp"
#include "SDLModule.hpp"
#include "InputDevice.hpp"
#include "Keyboard.hpp"
#include "Gamepad.hpp"
#include "HashTable.hpp"
#include <unordered_set>
#include <cstdint>
#include <cstdio>

class InputHandler {
private:
    MemorySystem& mem = MemorySystem::getInstance();
    HashTable<SDL_JoystickID, Gamepad*> padRegistry;
    InputDevice* mainDevice = nullptr;
    Keyboard* keyboard = nullptr;
    void addDevice(int32_t deviceID);
    void removeDevice(SDL_JoystickID instanceID);
    InputHandler();
public:
    InputHandler(InputHandler const&)            = delete;
    InputHandler& operator=(InputHandler const&) = delete;
    static InputHandler& getInstance();                                 /*  get singleton object                    */
    ~InputHandler();
    uint32_t startUP();                                                 /*  start up                                */
    uint32_t shutDown();                                                /*  shut down                               */
    void processInput(SDL_Event& event);                                /*  input processing routine                */
    inline InputDevice* getMainDevice() const { return mainDevice; }    /*  main device getter                      */
};

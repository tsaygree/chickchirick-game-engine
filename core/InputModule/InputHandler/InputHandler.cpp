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

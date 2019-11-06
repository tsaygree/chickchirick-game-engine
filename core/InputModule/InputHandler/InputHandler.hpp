/*

    InputHandler.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/11/2019.

    DESCRIPTION:

*/

#pragma once


class InputHandler {
private:
    InputHandler();
public:
    InputHandler(InputHandler const&)            = delete;
    InputHandler& operator=(InputHandler const&) = delete;
    static InputHandler& getInstance();
    ~InputHandler();
};

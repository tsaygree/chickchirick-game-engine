/*

    GameLoop.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 31/10/2019.

    DESCRIPTION:

*/

#pragma once

class GameLoop {
private:
    GameLoop();
public:
    GameLoop(GameLoop const&)            = delete;
    GameLoop& operator=(GameLoop const&) = delete;
    static GameLoop& getInstance();
    ~GameLoop();
};

/*

    EventLoop.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/11/2019.

    DESCRIPTION:

*/

#pragma once


class EventLoop {
private:
    EventLoop();
public:
    EventLoop(EventLoop const&)            = delete;
    EventLoop& operator=(EventLoop const&) = delete;
    static EventLoop& getInstance();
    ~EventLoop();
};

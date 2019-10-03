/*

    StackAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    StackAlloc is a singleton stack memory allocator.

*/

#pragma once


class StackAlloc {
private:
    StackAlloc();
public:
    static StackAlloc& getInstance();
};

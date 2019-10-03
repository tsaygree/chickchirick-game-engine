/*

    StackAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

*/

#include "StackAlloc.hpp"

StackAlloc::StackAlloc()  {}

StackAlloc& getInstance() {
    static StackAlloc instance;
    return instance;
}

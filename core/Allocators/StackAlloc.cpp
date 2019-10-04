/*

    StackAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

*/

#include "StackAlloc.hpp"

StackAlloc::StackAlloc()  {}

StackAlloc& StackAlloc::getInstance() {
    static StackAlloc instance;
    return instance;
}

int StackAlloc::startUP(uint32_t LSRSize_, uint32_t poolSize_) {
    this->LSRSize = LSRSize_;
    realSize = LSRSize_ + poolSize_;
    marker = LSRSize_;
    LSRMarker = 0;
    pool = new char[realSize];
    return 0;
}

int StackAlloc::shutDown() {
    delete[] pool;
    return 0;
}

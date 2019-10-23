/*

    StackAlloc.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

*/

#include "StackAlloc.hpp"

StackAlloc::StackAlloc()  {}

int StackAlloc::startUP(uint32_t LSRSize_, uint32_t poolSize_) {
    assert(isInit == false);
    assert(LSRSize_ + poolSize_ > 0);
    LSRSize = LSRSize_;
    realSize = LSRSize_ + poolSize_;
    marker = LSRSize_;
    LSRMarker = 0;
    pool = new char[realSize];
    isInnerPool = true;
    isInit = true;
    return 0;
}

int StackAlloc::startUP(char* sPool, uint32_t LSRSize_, uint32_t poolSize_) {
    assert(isInit == false);
    assert(sPool != nullptr);
    assert(LSRSize_ + poolSize_ > 0);
    LSRSize = LSRSize_;
    realSize = LSRSize_ + poolSize_;
    marker = LSRSize_;
    LSRMarker = 0;
    pool = sPool;
    isInit = true;
}

int StackAlloc::shutDown() {
    if (isInnerPool) {
        delete[] pool;
        isInnerPool = false;
    }
    isInit = false;
    return 0;
}

void* StackAlloc::stalloc(uint32_t size) {
    void* result = nullptr;
    if (marker + size < realSize) {
        result = CAST(void*, pool + marker);
        marker += size;
    }
    return result;
}

void* StackAlloc::LSRalloc(uint32_t size) {
    void* result = nullptr;
    if (LSRMarker + size < LSRSize) {
        result = CAST(void*, pool + LSRMarker);
        LSRMarker += size;
    }
    return result;
}

void StackAlloc::freeToMarker(uint32_t newMarker) {
    if (newMarker >= LSRSize && newMarker < marker) {
        marker = newMarker;
    }
}

void StackAlloc::free() {
    marker = LSRSize;
}

/*

    RingBuffer.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "Vector.hpp"
#include <cstdint>

template <typename T>
class RingBuffer {
private:
    Vector<T>     buffer;
    uint32_t      bufferSize = 0;
    uint32_t      head = 0;
    uint32_t      tail = 0;
public:
    RingBuffer(uint32_t size);
    ~RingBuffer();
};

template <typename T>
RingBuffer<T>::RingBuffer(uint32_t size) {
    bufferSize = size;
    buffer.resize(size);
    head = 0;
    tail = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer() {
    buffer.clear();
}

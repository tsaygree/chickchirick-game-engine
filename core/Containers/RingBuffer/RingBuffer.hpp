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
    void push(T value);
    T    pop();
    T&   front();
    T&   back();
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

template <typename T>
void RingBuffer<T>::push(T value) {
    buffer[tail] = value;
    tail = (tail + 1) % bufferSize;
}

template <typename T>
T RingBuffer<T>::pop() {
    T value = buffer[head];
    head = (head + 1) % bufferSize;
    return value;
}

template <typename T>
T& RingBuffer<T>::front() {
    return buffer[head];
}

template <typename T>
T& RingBuffer<T>::back() {
    return buffer[tail];
}

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
    uint32_t      bufferSize  = 0;
    uint32_t      numElements = 0;
    uint32_t      head = 0;
    uint32_t      tail = 0;
public:
    RingBuffer(uint32_t size);
    ~RingBuffer();
    void     push(T value);
    T        pop();
    T&       front();
    T&       back();
    void     clear();
    uint32_t capacity() const;
    uint32_t size()     const;
};

template <typename T>
RingBuffer<T>::RingBuffer(uint32_t size) {
    bufferSize = size;
    buffer.resize(size);
    head = 0;
    tail = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer() { buffer.clear(); }

template <typename T>
void RingBuffer<T>::push(T value) {
    tail = (tail + 1) % bufferSize;
    buffer[tail] = value;
    if (tail == head) { head = (head + 1) % bufferSize; }
}

template <typename T>
T RingBuffer<T>::pop() {
    if (head == tail) { tail = (tail + 1) % bufferSize; }
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

template <typename T>
void RingBuffer<T>::clear() {
    buffer.clear();
    head = 0;
    tail = 0;
}

template <typename T>
uint32_t RingBuffer<T>::capacity()  const { return bufferSize;      }

template <typename T>
uint32_t RingBuffer<T>::size()      const { return numElements;     }

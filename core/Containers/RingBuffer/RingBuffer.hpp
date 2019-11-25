/*

    RingBuffer.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/11/2019.

    DESCRIPTION:
    RingBuffer module is custom-designed queue that
    circulates entries. Size of the container (number
    of entries) is set at construction and can't be
    changed at later time. However, when queue overflows
    it removes the very first element in the queue in
    order to write a new one.

*/

#pragma once
#include "Vector.hpp"
#include <cstdint>

template <typename T>
class RingBuffer {
private:
    Vector<T> buffer;
    uint32_t  bufferSize  = 0;
    uint32_t  numElements = 0;
    uint32_t  head = 0;
    uint32_t  tail = 0;
public:
    RingBuffer(uint32_t size);
    ~RingBuffer();
    void      push(T value);
    void      pop();
    Vector<T> popAll();
    T&        front();
    T&        back();
    void      clear();
    uint32_t  capacity() const;
    uint32_t  size()     const;
};

template <typename T>
RingBuffer<T>::RingBuffer(uint32_t size) {
    buffer.resize(size);
    bufferSize  = size;
    numElements = 0;
    head = 0;
    tail = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer() { buffer.clear(); }

template <typename T>
void RingBuffer<T>::push(T value) {
    tail = (tail + 1) % bufferSize;
    buffer[tail] = value;
    if (tail == head)     { head = (head + 1) % bufferSize; }
    if (numElements == 0) { head = (head + 1) % bufferSize; }
    if (numElements != bufferSize) { numElements++; }
}

template <typename T>
void RingBuffer<T>::pop() {
    if (head == tail) { tail = (tail + 1) % bufferSize; }
    head = (head + 1) % bufferSize;
    if (numElements != 0) { numElements--; }
}

template <typename T>
Vector<T> RingBuffer<T>::popAll() {
    Vector<T> result;
    while (numElements > 0) {
        result.push_back(this->front());
        this->pop();
    }
    return result;
}

template <typename T>
T& RingBuffer<T>::front() { return buffer[head]; }

template <typename T>
T& RingBuffer<T>::back()  { return buffer[tail]; }

template <typename T>
void RingBuffer<T>::clear() {
    numElements = 0;
    buffer.clear();
    head = 0;
    tail = 0;
}

template <typename T>
uint32_t RingBuffer<T>::capacity()  const { return bufferSize;  }

template <typename T>
uint32_t RingBuffer<T>::size()      const { return numElements; }

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
    uint32_t      bufferCapacity = 0;
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
    auto     begin()    const;
    auto     end()      const;
    size_t   size()     const;
    uint32_t capacity() const;
};

template <typename T>
RingBuffer<T>::RingBuffer(uint32_t size) {
    bufferCapacity = size;
    buffer.resize(size);
    head = 0;
    tail = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer() { buffer.clear(); }

template <typename T>
void RingBuffer<T>::push(T value) {
    buffer[tail] = value;
    tail = (tail + 1) % bufferCapacity;
}

template <typename T>
T RingBuffer<T>::pop() {
    T value = buffer[head];
    head = (head + 1) % bufferCapacity;
    return value;
}

template <typename T>
T& RingBuffer<T>::front() { return buffer[head]; }

template <typename T>
T& RingBuffer<T>::back()  { return buffer[tail]; }

template <typename T>
void RingBuffer<T>::clear() {
    buffer.clear();
    head = 0;
    tail = 0;
}

template <typename T>
auto RingBuffer<T>::begin()         const { return buffer.begin();  }

template <typename T>
auto RingBuffer<T>::end()           const { return buffer.end();    }

template <typename T>
size_t RingBuffer<T>::size()        const { return buffer.size();   }

template <typename T>
uint32_t RingBuffer<T>::capacity()  const { return bufferCapacity;  }

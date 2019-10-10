/*

    MemorySystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 10/10/2019.

    DESCRIPTION:
    MemorySystem module is a singleton class that
    manages memory usage by the engine and game.
    It provides access to different types of memory
    allocation (block and stack allocators).
    In chickchirick game engine there is only one
    stack allocator that is used for storing
    LSR(Load & Stay Resident) data and level-to-level
    data(maps, textures, sounds, other assets).
    All dynamic memory allocations needed by the engine
    or the game are provided by block allocators.
    MemorySystem module encapsulates several block
    allocators of various block sizes. When allocation
    request is received, MemorySystem chooses the smallest
    pool whose elements are >= to the size of requested
    allocation. Memory for object, whose size is larger
    than the largest pool's block size, is allocated on
    general-purpose heap allocator.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "BlockAlloc.hpp"
#include "StackAlloc.hpp"

class MemorySystem {
private:
    MemorySystem();
public:
    static MemorySystem& getInstance();
};

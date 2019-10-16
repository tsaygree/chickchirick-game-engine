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

    NOTEx2: Current implementation supports loading settings
    from configuration file. This has its impact on
    allocation perfomance. However, such design is helpful
    during development, therefore it's here. Later in the
    development configuration file will be replaced with
    much faster (hopefully) hardcoded solutuion. Please,
    do not stress out if MemorySystem would become
    a bottleneck :)
*/

#pragma once
#include "FileSystem.hpp"
#include "ConfigManager.hpp"
#include "BlockAlloc.hpp"
#include "StackAlloc.hpp"
#include "MemoryUnits.hpp"
#include "Vector.hpp"
#include <cstdio>

class MemorySystem {
private:
    struct BlockAllocInfo {
        BlockAlloc  pool;
        char*       poolPtr;
        uint32_t    poolSize;
        uint32_t    blockSize;
    };
    MemorySystem();
    StackAlloc& stackPool = StackAlloc::getInstance();
    Vector<BlockAllocInfo> blockPoolList;                               /*  block pool registry                     */
public:
    static MemorySystem& getInstance();                                 /*  get singleton object                    */
    uint32_t startUP(const char* filename);                             /*  start up                                */
    uint32_t shutDown();                                                /*  shut down                               */
    StackAlloc& getStackAlloc() const;                                  /*  stack allocator getter                  */
    void* alloc(uint32_t size);                                         /*  allocation from pool or heap            */
    void free(void* ptr);                                               /*  free memory from pool or heap           */
};

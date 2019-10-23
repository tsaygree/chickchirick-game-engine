/*

    BlockAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 27/09/2019.

    DESCRIPTION:
    BlockAlloc is a fixed size heap memory pool allocator.
    Pool size (bytes) and memory block size (bytes) are
    configured at runtime during pool initialization.
    Due to implementation details, each memory block size
    cannot be less than a size of pointer in particular
    system. Pool size should be a multiple of memory block
    size. Run-time assertion errors will occure if size
    requirements won't be followed.
    BlockAlloc also supports outer pool initialization. That
    means that BlockAlloc can work with pre-allocated memory.
    Note that deallocation of outer memory pool is completely
    on the caller. BlockAlloc only clears memory that was
    allocated by itself.
    It is also not thread safe in its current state.

*/

#pragma once
#include <cstring>
#include <cstdint>
#include <cassert>

#define CAST(type, expr) reinterpret_cast<type>(expr)
#define cpyptr(dest, src) std::memcpy(dest, src, sizeof(uintptr_t))

class BlockAlloc {
private:
    char*    blockPool    = nullptr;                        /*  pool of static memory                       */
    char*    freeBlockPtr = nullptr;                        /*  pointer to current free memory block        */
    uint32_t poolSize     = 0;                              /*  size of allocated pool                      */
    uint32_t blockSize    = 0;                              /*  size of single block                        */
    bool     isInit       = false;                          /*  initialization flag                         */
    bool     isInnerPool  = false;                          /*  pool type flag                              */
    inline void initVars(char* bPool, uint32_t pSize, uint32_t bSize) {
        blockPool = bPool;
        poolSize  = pSize;
        blockSize = bSize;
    }
    inline void resetPool() {
        char* cur = blockPool;
        char* end = blockPool + poolSize - blockSize;
        uintptr_t addr = 0;
        while (cur < end) {
            addr = CAST(uintptr_t, (cur + blockSize));
            cpyptr(cur, &addr);
            cur += blockSize;
        }
        addr = CAST(uintptr_t, nullptr);
        cpyptr(cur, &addr);
        freeBlockPtr = blockPool;
    }
public:
    BlockAlloc();
    void  startUP(uint32_t pSize, uint32_t bSize);              /*  inner pool initialization                   */
    void  startUP(char* bPool, uint32_t pSize, uint32_t bSize); /*  outer pool initialization                   */
    void* balloc();                                             /*  block allocation                            */
    void  free(void* blockptr);                                 /*  free allocated block                        */
    inline void freeAll() { this->resetPool(); }                /*  free all allocated blocks                   */
    inline void shutDown() {                                    /*  free allocated memory                       */
        if (isInnerPool) {
            delete[] blockPool;
        }
        isInit = false;
    }
};

/*

    StackAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    StackAlloc is a stack memory allocator that works much like
    stack does. It allocates memory from top of the pool and
    deallocates it from top to bottom up to special marker (see below)
    StackAlloc has two types of initialization:
        1)  initialize and allocate memory
        2)  initialize with pre-allocated memory
            Note that deallocation of outer memory pool is completely
            on the caller. StackAlloc only clears memory that was
            allocated by itself.

    StackAlloc devides memory pool into two sections. The first
    one (LSR - Load and Stay Resident) is used for data that is
    supposed to be in memory during all lifetime of the StackAlloc.
    The second one is used for different dynamic allocations and can
    return a special marker that later is used for deallocation.
    NOTE: This class is not thread safe.

*/

#pragma once
#include <cstdint>
#include <cassert>

#define CAST(type, expr) reinterpret_cast<type>(expr)

class StackAlloc {
private:
    char*       pool;                                       /*  ptr to begining of the pool                             */
    uint32_t    marker      = 0;                            /*  shows the top of stack                                  */
    uint32_t    LSRSize     = 0;                            /*  size of Load&StayResident data                          */
    uint32_t    LSRMarker   = 0;                            /*  marker to top of LSR data                               */
    uint32_t    realSize    = 0;                            /*  size of LSR + size of pool                              */
    bool        isInit      = false;                        /*  initialization flag                                     */
    bool        isInnerPool = false;
public:
    StackAlloc();
    int   startUP(uint32_t LSRSize_, uint32_t poolSize_);   /*  initialize and allocate pool                            */
    int   startUP(char* sPool, uint32_t LSRSize_, uint32_t poolSize_); /* initialize with pre-allocated pool            */
    int   shutDown();                                       /*  shut down routine                                       */
    void* stalloc(uint32_t size);                           /*  allocate size bytes on stack                            */
    void* LSRalloc(uint32_t size);                          /*  allocate size bytes on LSR stack                        */
    void  freeToMarker(uint32_t newMarker);                 /*  free stack to the new marker position                   */
    void  free();                                           /*  free all stack / NOTE: this doesn't free LSR data       */
    inline uint32_t getMarker() const { return marker; }    /*  get top marker                                          */
};

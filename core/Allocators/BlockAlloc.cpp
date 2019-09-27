/*

    BlockAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 27/09/2019.

*/
#include "BlockAlloc.hpp"

static char blockPool[POOLSIZE];            /*  pool of static memory                   */
static char *freeBlockPtr;                  /*  pointer to current free memory block    */

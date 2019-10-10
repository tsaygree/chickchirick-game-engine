/*

    MemorySystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 10/10/2019.

*/

#include "MemorySystem.hpp"

MemorySystem::MemorySystem()  {}

MemorySystem& MemorySystem::getInstance() {
    static MemorySystem instance;
    return instance;
}

/*

    MemoryUnits.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 09/10/2019.

    DESCRIPTION:
    MemoryUnits provides user-defined literals
    as an interface to do byte conversion at
    compile time.

*/

#pragma once
#include <cstdint>

/*  compile time power function */
constexpr uint32_t power(int32_t base, uint32_t exp) {
    uint32_t result = 1;
    while (exp) {
        result *= base;
        exp--;
    }
    return result;
}

constexpr uint32_t operator"" _KiB(unsigned long long val) {
    return val * 1024;
}

constexpr uint32_t operator"" _MiB(unsigned long long val) {
    return val * power(1024, 2);
}

constexpr uint32_t operator"" _GiB(unsigned long long val) {
    return val * power(1024, 3);
}

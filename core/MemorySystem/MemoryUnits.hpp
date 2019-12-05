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
constexpr uint64_t power(int64_t base, uint64_t exp) {
    uint64_t result = 1;
    while (exp) {
        result *= base;
        exp--;
    }
    return result;
}

constexpr uint64_t KiBtoB(unsigned long long val) {
    return val * 1024;
}

constexpr uint64_t MiBtoB(unsigned long long val) {
    return val * power(1024, 2);
}

constexpr uint64_t GiBtoB(unsigned long long val) {
    return val * power(1024, 3);
}

constexpr uint64_t operator"" _KiB(unsigned long long val) {
    return KiBtoB(val);
}

constexpr uint64_t operator"" _MiB(unsigned long long val) {
    return MiBtoB(val);
}

constexpr uint64_t operator"" _GiB(unsigned long long val) {
    return GiBtoB(val);
}

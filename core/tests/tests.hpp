/*

    tests.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 06/10/2019.

    DESCRIPTION:
    Common function to run all tests.

*/

#pragma once
#include "TestRunner.hpp"
#include "BlockAllocTests.hpp"

void runAllTests() {
    runBlockAllocTests();
}

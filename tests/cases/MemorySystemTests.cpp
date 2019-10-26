/*

    MemorySystemTests.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 15/10/2019.

    DESCRIPTION:
    Tests for MemorySystem module.

*/

#include "Catch2.hpp"
#include "SystemManager.hpp"
#include "MemorySystem.hpp"

TEST_CASE("MemorySystem module tests", "[MemorySystem]") {
    SystemManager& systemManager = SystemManager::getInstance();
    systemManager.BigInit();
    MemorySystem& memSys = MemorySystem::getInstance();

    /*  block tests */
    int* iptr = (int*)memSys.alloc(sizeof(int));
    *iptr = 5;
    REQUIRE(*iptr == 5);
    memSys.free(iptr);
    struct TestStruct {
        int     decimal;
        double  floating;
        char    symbol;
        void*   ptr;
    };
    TestStruct* ptr = (TestStruct*)memSys.alloc(sizeof(TestStruct));
    ptr->decimal  = 3;
    ptr->floating = 3.1415;
    ptr->symbol   = 'p';
    ptr->ptr      = nullptr;

    REQUIRE(ptr->decimal  == 3);
    REQUIRE(ptr->floating == 3.1415);
    REQUIRE(ptr->symbol   == 'p');
    REQUIRE(ptr->ptr      == nullptr);
    memSys.free(ptr);
    void* vptr = memSys.alloc(500_MiB);
    memSys.free(vptr);

    /*  stack tests */
    iptr  = (int*)memSys.stalloc(sizeof(int));
    *iptr = 5;
    REQUIRE(*iptr == 5);
    memSys.stfree();
    ptr = (TestStruct*)memSys.stalloc(sizeof(TestStruct));
    ptr->decimal  = 3;
    ptr->floating = 3.1415;
    ptr->symbol   = 'p';
    ptr->ptr      = nullptr;

    REQUIRE(ptr->decimal  == 3);
    REQUIRE(ptr->floating == 3.1415);
    REQUIRE(ptr->symbol   == 'p');
    REQUIRE(ptr->ptr      == nullptr);
    vptr = memSys.stalloc(500_MiB);
    REQUIRE(vptr == nullptr);
    memSys.stfree();
    systemManager.BigShutDown();
}

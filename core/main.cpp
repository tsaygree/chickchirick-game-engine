/*

    main.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 12/09/2019.

*/

#include "SystemManager.hpp"

int main(int argc, char const *argv[]) {
    SystemManager& systemManager = SystemManager::getInstance();
    systemManager.BigInit();
    systemManager.BigShutDown();
    return 0;
}

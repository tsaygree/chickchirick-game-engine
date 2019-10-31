/*

    main.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 12/09/2019.

*/

#include "SystemManager.hpp"

int main(int argc, char const *argv[]) {
    SystemManager& systemManager = SystemManager::getInstance();
    GameLoop& gloop = GameLoop::getInstance();
    systemManager.BigInit();
    gloop.run();
    systemManager.BigShutDown();
    return 0;
}

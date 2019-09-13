#include "SystemManager.hpp"

int  main(int argc, char const *argv[]) {
    SystemManager systemManager = SystemManager::getInstance();
    systemManager.BigInit();
    systemManager.BigShutDown();
    return 0;
}

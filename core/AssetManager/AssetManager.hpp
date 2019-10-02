/*

    AssetManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

    DESCRIPTION:
    AssetManager is a singleton class that loads, stores, manages
    and offloads resources needed by the game. It ensures that
    only one copy of each unique resource is present in memory at
    any given time. It is also responsible for giving the resources
    their unique identifuers which are StringIDs.
    AssetManager usses different types of memory allocations to store
    each resource properly in memory.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "StringID.hpp"

class AssetManager {
private:
    StringID assetsPath;
    AssetManager();
public:
    static AssetManager& getInstance();
    int startUP(const StringID& assetsPath_);
    int shutDown();
};

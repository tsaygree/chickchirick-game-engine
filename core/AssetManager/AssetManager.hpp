/*

    AssetManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

    DESCRIPTION:
    AssetManager is a singleton class that loads, stores, manages
    and offloads resources needed by the game. It ensures that
    only one copy of each unique resource is present in memory at
    any given time. It is also responsible for giving the resources
    their unique identifiers which are StringIDs.
    AssetManager usses different types of memory allocations to store
    each resource properly in memory.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "MemorySystem.hpp"
#include "FileSystem.hpp"
#include "StringID.hpp"
#include "Asset.hpp"
#include "Texture.hpp"
#include "Map.hpp"
#include "HashTable.hpp"
#include <cstdint>

#define STCAST(type, expr) static_cast<type>(expr)

class AssetManager {
private:
    MemorySystem&    mem = MemorySystem::getInstance();
    StringID         assetsPath;
    SIDTable<Asset*> resRegistry;
    AssetManager();
    template <typename T>
    void loadAssetAsType(T* asset, const StringID& name);
public:
    AssetManager(AssetManager const&)            = delete;
    AssetManager& operator=(AssetManager const&) = delete;
    static AssetManager& getInstance();
    int     startUP(const StringID& assetsPath_);
    int     shutDown();
    template <typename T>
    T* loadAssetAs(const StringID& name) {
        T* result = nullptr;
        if (resRegistry.count(name) == 0) {
            result = CAST(T*, mem.stalloc(sizeof(T)));
            this->loadAssetAsType<T>(result, name);
            resRegistry[name] = STCAST(Asset*, result);
        }
        return result;
    }
    template <typename T>
    T* loadGlobalAssetAs(const StringID& name) {
        T* result = nullptr;
        if (resRegistry.count(name) == 0) {
            result = CAST(T*, mem.galloc(sizeof(T)));
            this->loadAssetAsType<T>(result, name);
            resRegistry[name] = STCAST(Asset*, result);
        }
        return result;
    }
    Asset*  getAsset(const StringID& name);
};

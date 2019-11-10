/*

    Asset.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 18/10/2019.

    DESCRIPTION:
    Class that represents a single asset. It has
    its own unique ID (usually the filename or relative
    filepath) and Type enumeration This is a base class
    in asset class hierarchy. All asset-specific classes
    should derive from this one.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "StringID.hpp"

class Asset {
public:
    enum class Type {
        Texture,
        Map
    };

    StringID id;

    Asset() {}
    ~Asset() {}
    virtual Type getType() const = 0;
};

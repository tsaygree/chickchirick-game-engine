/*

    Asset.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 18/10/2019.

    DESCRIPTION:

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

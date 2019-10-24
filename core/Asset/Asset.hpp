/*

    Asset.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 18/10/2019.

    DESCRIPTION:

*/

#pragma once
#include "StringID.hpp"

class Asset {
protected:
    StringID id;
public:
    Asset() {}
    ~Asset() {}
    inline const StringID& getID() { return id; }
};

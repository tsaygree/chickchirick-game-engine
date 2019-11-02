/*

    GameObject.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "StringID.hpp"

class GameObject {
private:
public:
    StringID id;
    GameObject(const StringID& name);
    ~GameObject();
};

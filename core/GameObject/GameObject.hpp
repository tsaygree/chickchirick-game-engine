/*

    GameObject.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/11/2019.

    DESCRIPTION:
    GameObject is a class module that implements component model
    structure pattern. GameObject represents every in-game runtime
    object.
    NOTE: This class is not thread safe.

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

/*

    HashTable.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    Big file of engine defines, c++ aliases and includes.
    Custom implementation may be implemented later.
*/

#pragma once
#include <unordered_map>

/*  alias for unordered_map         */
template<typename K, typename V>
using HashTable = std::unordered_map<K,V>;

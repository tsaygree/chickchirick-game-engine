/*

    HashTable.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    HashTable definition.

*/

#pragma once
#include <unordered_map>

/*  alias for unordered_map         */
template<typename K, typename V>
using HashTable = std::unordered_map<K,V>;

/*

    Vector.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 13/10/2019.

    DESCRIPTION:
    Boost C++ Vector definition

*/

#pragma once
#include <boost/container/vector.hpp>
namespace bcon = boost::container;

/*  alias for boost vector        */
template<typename T>
using Vector = bcon::vector<T>;

/*

    Texture.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

    DESCRIPTION:
    Custom wrapper for SDL_Texture.
*/

#pragma once
#include "SDLModule.hpp"
#include "Asset.hpp"

class Texture : public Asset {
public:
    SDL_Texture* texture;
    Texture() {}
    ~Texture() {}
    inline void destroy() { SDL_DestroyTexture(texture); }
    inline Type getType() const override { return Asset::Type::Texture; }
};

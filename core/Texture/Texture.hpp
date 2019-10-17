/*

    Texture.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

    DESCRIPTION:
    Custom wrapper for SDL_Texture.
*/

#pragma once
#include "SDLInclude.hpp"
#include "StringID.hpp"

class Texture {
private:
    SDL_Texture* texture;
    StringID     id;
public:
    Texture(SDL_Texture* tex, const StringID& id);
    inline void destroy() { SDL_DestroyTexture(texture); }
};

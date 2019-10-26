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
private:
    SDL_Texture* texture;
public:
    Texture(SDL_Texture* tex, const StringID& id);
    ~Texture();
    inline void destroy() { SDL_DestroyTexture(texture); }
    inline SDL_Texture* getSDLTexture() const { return texture; }
};

/*

    Texture.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/10/2019.

*/

#include "Texture.hpp"

Texture::Texture(SDL_Texture* tex, const StringID& texID) {
    texture = tex;
    id = texID;
}

Texture::~Texture() {}

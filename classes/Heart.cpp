//
// Created by Agus on 15/11/2020.
//

#include "Heart.h"
#include <iostream>

Heart::Heart() {

    if (!texture.loadFromFile("../assets/heart.png"))
        std::cout << "HEARTH::No se ha podido cargar la textura del corazon\n";

    sprite.setTexture(texture);
    currentFrame = IntRect(0, 0, 512, 512);
    sprite.setTextureRect(currentFrame);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(0, 0);
}

Sprite Heart::getSprite() {
    return sprite;
}
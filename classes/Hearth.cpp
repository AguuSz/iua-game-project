//
// Created by Agus on 15/11/2020.
//

#include "Hearth.h"
#include <iostream>

Hearth::Hearth() {
    hp = 2;

    if (!texture.loadFromFile("../assets/healthHearth.png"))
        std::cout << "HEARTH::No se ha podido cargar la textura del corazon\n";

    sprite.setTexture(texture);
    currentFrame = IntRect(0, 0, 17, 17);
    sprite.setTextureRect(currentFrame);
    sprite.setPosition(0, 0);
}

Sprite Hearth::getSprite() {
    return sprite;
}
//
// Created by Agus on 22/9/2020.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

using namespace sf;

class Bullet {

public:
    Sprite sprite;
    Texture texture;
    Vector2f currVelocity;
    float maxSpeed;

    Bullet() : currVelocity(0.f, 0.f), maxSpeed(15.f) {
        if(!texture.loadFromFile("../assets/Bullet.png"))
            std::cout << "Error al cargar la textura de la bala";
        sprite.setTexture(texture);
    }

    Bullet(float scaleFactor) : currVelocity(0.f, 0.f), maxSpeed(7.f) {
        if(!texture.loadFromFile("../assets/enemies/Boss/bossBullet.png"))
            std::cout << "Error al cargar la textura de la bala";
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, 17, 17));
        sprite.setScale(scaleFactor, scaleFactor);
    }

    void impact() {
        // Hacer la animacion, y que al final se destruya el objeto.
    }

};

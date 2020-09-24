//
// Created by Agus on 23/9/2020.
//
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Mushroom {
public:
    Sprite sprite;
    Texture texture;
    Vector2f dimension;
    Vector2f initialFramePoint;

    Mushroom() {
        if (!texture.loadFromFile("../assets/Mushroom/Idle.png"))
            std::cout << "ERROR::MUSHROOM No se ha encontrado la textura del mushroom" << std::endl;
        sprite.setTexture(texture);
        dimension = Vector2f(40.f, 45.f);
        initialFramePoint = Vector2f(55.f, 60.f);
    }
};
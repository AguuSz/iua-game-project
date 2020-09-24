//
// Created by Agus on 20/9/2020.
//
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Goblin {
public:
    Sprite sprite;
    Texture texture;
    Vector2f dimension;
    Vector2f initialFramePoint;

    Goblin() {
        if (!texture.loadFromFile("../assets/Goblin/Idle.png"))
            std::cout << "ERROR::GOBLIN No se ha encontrado la textura del goblin" << std::endl;
        sprite.setTexture(texture);
        dimension = Vector2f(40.f, 45.f);
        initialFramePoint = Vector2f(55.f, 60.f);
    }
};
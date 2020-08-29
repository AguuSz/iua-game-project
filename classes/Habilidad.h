//
// Created by Agus on 28/8/2020.
//
#include <SFML/Graphics.hpp>
using namespace sf;

// En progreso...

class Habilidad {

private:

    Sprite sprite;
    Texture texture;

    Vector2f position;

    String name;

    float damage;

    float cooldown;

    float movementSpeed;

public:

    Habilidad();

    Sprite getSprite();

};
//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
using namespace sf;

class Jake {
private:
    Vector2f position;

    Sprite sprite;

    Texture texture;

    bool leftKeyPressed;
    bool rightKeyPressed;

    float movementSpeed;

public:
    // Constructor
    Jake();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    // Mover a la izquierda
    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(float elapsedTime);
};

//
// Created by Agus on 28/8/2020.
//

#include "Jake.h"

// Constructor
Jake::Jake() {

    // Velocidad a la que se va a mover
    movementSpeed = 200;

    // Carga la textura con el sprite
    texture.loadFromFile("../assets/bob.png");
    sprite.setTexture(texture);

    // Posicion inicial en X e Y
    position.x = 200;
    position.y = 200;

}
// Declaracion de funciones

Sprite Jake::getSprite() {
    return sprite;
}

void Jake::moveLeft() {
    leftKeyPressed = true;
}

void Jake::moveRight() {
    rightKeyPressed = true;
}

void Jake::stopLeft() {
    leftKeyPressed = false;
}

void Jake::stopRight() {
    rightKeyPressed = false;
}

// Funcion que va a ser llamada con el input, tiene en cuenta el tiempo transcurrido y la velocidad
void Jake::update(float elapsedTime) {
    if (rightKeyPressed) {
        position.x += movementSpeed * elapsedTime;
    }

    if (leftKeyPressed) {
        position.x -= movementSpeed * elapsedTime;
    }

    // Setea en el sprite la nueva posicion
    sprite.setPosition(position);
}


//
// Created by Agus on 28/8/2020.
//

#include "Personaje.h"

// Constructor
Personaje::Personaje() {

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

Sprite Personaje::getSprite() {
    return sprite;
}

void Personaje::moveLeft() {
    leftKeyPressed = true;
}

void Personaje::moveRight() {
    rightKeyPressed = true;
}

void Personaje::stopLeft() {
    leftKeyPressed = false;
}

void Personaje::stopRight() {
    rightKeyPressed = false;
}

// Funcion que va a ser llamada con el input, tiene en cuenta el tiempo transcurrido y la velocidad
void Personaje::update(float elapsedTime) {
    if (rightKeyPressed) {
        position.x += movementSpeed * elapsedTime;
    }

    if (leftKeyPressed) {
        position.x -= movementSpeed * elapsedTime;
    }

    // Setea en el sprite la nueva posicion
    sprite.setPosition(position);
}


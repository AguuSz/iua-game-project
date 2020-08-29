//
// Created by Agus on 28/8/2020.
//

#include "Jefe.h"

Jefe::Jefe() {

    // Seteo de parametros basicos
    vida = 1500;
    damage = 1;
    projectileSpeed = 300;
    damageMultiplier = 1;
    movementSpeed = 300;

    // Seteamos posicion inicial
    position.x = 0;
    position.y = 0;

    // Seteamos atributos para la habilidad
    ability();

    texture.loadFromFile("assets/ability1.jpg");
    sprite.setTexture(texture);

}

// Declaramos las funciones

Sprite Jefe::getSprite() {
    return sprite;
}

void Jefe::belowHalfLife() {
    damageMultiplier *= 3;
    projectileSpeed *= 2;
}

void Jefe::update(float elapsedTime) {
    // Movimiento random del boss
    // Modificar position.x y position.y acorde a lo querramos
    //    sprite.setPosition(position);

    // Si esta a menos de la mitad de vida..
    if (vida < vida / 2) {
        belowHalfLife();
        sprite.setColor(Color::Red);
    }
}



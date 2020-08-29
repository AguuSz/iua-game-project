#include "Jefe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

Jefe::Jefe(String name, float health, float damage, float projectileSpeed, float damageMultiplier, float movementSpeed) {

    // Seteo de parametros basicos
    Jefe::name = name;
    Jefe::health = health;
    Jefe::damage = damage;
    Jefe::projectileSpeed = projectileSpeed;
    Jefe::damageMultiplier = damageMultiplier;
    Jefe::movementSpeed = movementSpeed;

    // Seteamos posicion inicial
    Jefe::position.x = position.x
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
    sprite.setPosition(position);

    // Si esta a menos de la mitad de vida..
    if (health <= health / 2) {
        belowHalfLife();
        sprite.setColor(Color::Red);
    }
}

void Jefe::randomMovement(Vector2f nextPosition){  //movimiento random

    srand(time(NULL));

    int direction = rand() % 4 + 1 //Obtengo numeros aleatorios entre 1 y 4, 1=arriba, 2=abajo, 3=izquierda, 4=derecha
    int movementQuantity = rand() % 11 + 20  // numeros entre 20 y 30
    int checkPosition = 0;

    while(checkPosition != movementQuantity) {
        if (direction == 1) {
            position.y++;
            checkPosition++;
        }
        if (direction == 2) {
            position.y--;
            checkPosition++;
        }
        if (direction == 3) {
            position.x--;
            checkPosition++;
        } else {
            position.x++;
            checkPosition++;
        }
    }
}



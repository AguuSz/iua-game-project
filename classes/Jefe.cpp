#include "Jefe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Jefe::Jefe(float currentHp, float maxHp, bool isInvincible, float projectileSpeed, float damageMultiplier, float movementSpeed) {

    // Seteo de parametros basicos
    Jefe::currentHp = currentHp;
    Jefe::maxHp = maxHp;
    Jefe::isInvincible = isInvincible;
    Jefe::projectileSpeed = projectileSpeed;
    Jefe::damageMultiplier = damageMultiplier;
    Jefe::movementSpeed = movementSpeed;

    // Seteamos posicion inicial
    Jefe::position.x = position.x;
    Jefe::position.y = position.y;

    // Inicializacion de variables
    initTexture();
    initSprite();
    initAnimations();
    initPhysics();

    // Seteamos atributos para la habilidad
//    ability();

//    texture.loadFromFile("assets/ability1.jpg");


}

// Declaramos las funciones

void Jefe::setAsset(String directory){
    if(!texture.loadFromFile(directory))
        std::cout << "ERROR::JEFE:: No se ha podido cargar la textura del jefe." << std::endl;

}
void Jefe::initTexture(){
    if(!texture.loadFromFile(directory))
        std::cout << "ERROR::JEFE:: No se ha podido cargar la textura del jeje." << std::endl;
}

void Jefe::initSprite(){
    //Cargamos la textura como sprite
    sprite.setTexture(texture);
}

void Jefe::initAnimations() {
    animationTimer.restart();
    animationSwitch = true;
}

void Jefe::initPhysics(){

    velocity.x = 5.f;
    velocity.y = 0.f;
};
Sprite Jefe::getSprite() {
    return sprite;
}

void Jefe::updatePhysics(){
    sprite.setPosition(position);
}

void Jefe::updateMovement(){
    //movimiento random
}

void Jefe::updateAnimations() {
    //animaciones del jefe
}

void Jefe::attack(){
    //ataque del boss
}
void Jefe::belowHalfLife() {
    damageMultiplier *= 3;
    projectileSpeed *= 2;
}

void Jefe::update() {

    updateMovement();
    updateAnimations();
    updatePhysics();

}

void Jefe::resetVelocityY() {
    velocity.y = 0.f;
}

void Jefe::resetVelocityX() {
    velocity.x = 0.f;

}

RectangleShape Jefe::jefeBox(){
    //setear hitbox del jefe
}




#include "Jefe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Jefe::Jefe(String name, float maxHp) {

    // Seteo de parametros basicos
    Jefe::maxHp = maxHp;

    // Inicializacion de variables
    initAnimations();
    initPhysics();
    initVariables();

    // Seteamos atributos para la habilidad
//    ability();

//    texture.loadFromFile("assets/ability1.jpg");


}

// Declaramos las funciones

void Jefe::setAsset(String directory){
    if(!texture.loadFromFile(directory))
        std::cout << "ERROR::JEFE:: No se ha podido cargar la textura del jefe." << std::endl;

}


void Jefe::setTexture(String directory){
    if(!texture.loadFromFile(directory))
        std::cout << "ERROR::JEFE:: No se ha podido cargar la textura del jeje." << std::endl;

    sprite.setTexture(texture);

}

void Jefe::initVariables() {
    currentHp = maxHp;
    projectileSpeed = 2.0;
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

void Jefe::setPosition(const float x, const float y) {
    Jefe::position.x = x;
    Jefe::position.y = y;
}

void Jefe::moveX(const float dir_x) {
    // Movimiento en X
    position.x += dir_x * velocity.x;
}
void Jefe::moveY(const float dir_y) {
    // Movimiento en X
    position.y += dir_y * velocity.y;
}

void Jefe::updatePhysics(){
    sprite.setPosition(position);
}

void Jefe::updateMovement(){

    //animState = JEFE_ANIMATION_STATES::IDLE;
    int movementQuantity, movementSense;
    srand(time(NULL));
    while(currentHp != 0){
        movementSense = rand() % 3 + 0;
        movementQuantity = rand() % 10 + 20;
        if(movementSense == 0) {
            for (int i = 0; i < movementQuantity; i++) {
                moveX(-1.f);
                //animState = JEFE_ANIMATION_STATES::MOVING_LEFT;
            }
        }
        if(movementSense == 1){
            for(int j = 0; j < movementQuantity; j++){
                moveX(1.f);
                //animState = JEFE_ANIMATION_STATES::MOVING_RIGHT;
            }
        }
        if(movementSense == 2){
            for(int k = 0; k < movementQuantity; k++){
                moveY(1.f);
                //animState = JEFE_ANIMATION_STATES::MOVING_UP;
            }
        }
        if(movementSense == 3){
            for(int l = 0; l < movementQuantity; l++){
                moveY(-1.f);
                //animState = JEFE_ANIMATION_STATES::MOVING_DOWN;
            }
        }
    }
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

// RectangleShape Jefe::jefeBox(){
//setear hitbox del jefe





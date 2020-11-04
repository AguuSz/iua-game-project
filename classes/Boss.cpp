#include "Boss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Boss::Boss() {

    // Inicializacion de variables
    initVariables();
    initTexture();
    initSprite();
    initAnimations();
    initPhysics();

}

// Declaramos las funciones

void Boss::initVariables(){
    //vida
    maxHp = 100;
    currentHp = 100;
    isInvincible = false;

    scaleFactor = 6;
    animState = IDLE1;

    sprite.setPosition(0, 0);
    middlePoint.x = getGlobalBounds().left + getGlobalBounds().width / 2;
    middlePoint.y = getGlobalBounds().top + getGlobalBounds().height / 2;
}

void Boss::initTexture() {
    // Se carga la textura, y si tira error, que nos muestre el error
    if(!texture.loadFromFile("../assets/player_sheet.png"))
        std::cout << "ERROR::BOSS:: No se ha podido cargar la textura del boss." << std::endl;
}

void Boss::initSprite() {
    // Cargamos la textura como sprite
    sprite.setTexture(texture);
    currentFrame = IntRect(0, 0, 40, 50);

    sprite.setTextureRect(currentFrame);

    // Reescalando la textura
    sprite.scale(scaleFactor, scaleFactor);
}

void Boss::initAnimations() {
    animationTimer.restart();
}

void Boss::initPhysics(){

    speed.x = 5.f;
    speed.y = 0.f;

    gravity = 1.f;

};
Sprite Boss::getSprite() {
    return sprite;
}

void Boss::moveX(const float dir_x) {
    // Movimiento en X
    position.x += dir_x * speed.x;
}
void Boss::moveY(const float dir_y) {
    // Movimiento en Y
    position.y += dir_y * speed.y;
}

void Boss::updateMovement(){

    animState = BOSS_ANIMATION_STATES::IDLE1;
    int movementQuantity, movementSense;
    srand(time(NULL));
    while(currentHp != 0){
        movementSense = rand() % 3 + 0;
        movementQuantity = rand() % 10 + 20;
        if(movementSense == 0) {
            for (int i = 0; i < movementQuantity; i++) {
                moveX(-1.f);
                animState = BOSS_ANIMATION_STATES::MOVING_LEFT1;
            }
        }
        if(movementSense == 1){
            for(int j = 0; j < movementQuantity; j++){
                moveX(1.f);
                animState = BOSS_ANIMATION_STATES::MOVING_RIGHT1;
            }
        }
        if(movementSense == 2){
            for(int k = 0; k < movementQuantity; k++){
                moveY(1.f);
                animState = BOSS_ANIMATION_STATES::MOVING_UP1;
            }
        }
        if(movementSense == 3){
            for(int l = 0; l < movementQuantity; l++){
                moveY(-1.f);
                animState = BOSS_ANIMATION_STATES::MOVING_DOWN1;
            }
        }
    }
}

void Boss::updateAnimations() {
    // Animacion IDLE
    if (animState == BOSS_ANIMATION_STATES::IDLE1) {
        // Cuando pasa medio segundo, ahi recien que empieze a animar
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            // Hacemos que vuelva arriba, debido a nuestro boss sheet
            currentFrame.top = 0;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 160.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

        }
    }
        // Animacion hacia la derecha
    else if (animState == BOSS_ANIMATION_STATES::MOVING_RIGHT1) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 50.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 360.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            setBossLookingRight(true);
        }
    }

    else if (animState == BOSS_ANIMATION_STATES::MOVING_LEFT1) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 50.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 360.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            setBossLookingRight(false);
        }
    }

    else if(animState == BOSS_ANIMATION_STATES::MOVING_DOWN1) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 200.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 40.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }

    }
    else
        animationTimer.restart();
}

void Boss::attack(){
    //ataque del boss
}
void Boss::belowHalfLife() {
    damageMultiplier *= 3;
    projectileSpeed *= 2;
}

void Boss::update() {

    updateMovement();
    updateAnimations();
    updateMiddlePoint();
}

const FloatRect Boss::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Boss::resetVelocityY() {
    speed.y = 0.f;
}

void Boss::resetVelocityX() {
    speed.x = 0.f;

}

const Vector2f Boss::getMiddlePoint() const {
    return middlePoint;
}

void Boss::updateMiddlePoint() {
    middlePoint.x = getGlobalBounds().left + getGlobalBounds().width / 2;
    middlePoint.y = getGlobalBounds().top + getGlobalBounds().height / 2;
}

RectangleShape Boss::bossBox() {
    // Funcion solo utilizada para el desarrollo del juego
    // Nos devuelve un rectangulo con el tamanio del sprite del boss
    box.setSize(Vector2f(getGlobalBounds().width, getGlobalBounds().height));
    box.setOutlineColor(Color::Red);
    box.setOutlineThickness(2);
    box.setFillColor(Color::Transparent);
    box.setPosition(getGlobalBounds().left, getGlobalBounds().top);

    return box;
}

Vector2f Boss::getPosition() {
    return this->position;
}

void Boss::setBossLookingRight(bool lookRight) {
    if (lookRight) {
        sprite.setScale(scaleFactor, scaleFactor);
        sprite.setOrigin(0.f, 0.f);
    } else {
        sprite.setScale(-scaleFactor, scaleFactor);
        sprite.setOrigin(sprite.getGlobalBounds().width / scaleFactor, 0.f);
    }
}

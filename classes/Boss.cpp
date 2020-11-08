#include "Boss.h"
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iostream>

Boss::Boss() {

    // Inicializacion de variables
    initVariables();
    initTexture();
    initSprite();
    initAnimations();
    //initPhysics();

}

// Declaramos las funciones

void Boss::initVariables(){
    //vida
    maxHp = 100;
    currentHp = 100;
    isInvincible = false;

    scaleFactor = 5;
    animState = IDLE1;

    position.x = 300;
    position.y = 200;
    middlePoint.x = getGlobalBounds().left + getGlobalBounds().width / 2;
    middlePoint.y = getGlobalBounds().top + getGlobalBounds().height / 2;
}

void Boss::initTexture() {
    // Se carga la textura, y si tira error, que nos muestre el error
    if(!texture.loadFromFile("../assets/enemies/Boss/bossSheet.png"))
        std::cout << "ERROR::BOSS:: No se ha podido cargar la textura del boss." << std::endl;
}

void Boss::initSprite() {
    // Cargamos la textura como sprite
    sprite.setTexture(texture);
    currentFrame = IntRect(0, 0, 40, 60);

    sprite.setTextureRect(currentFrame);

    // Reescalando la textura
    sprite.scale(scaleFactor, scaleFactor);
}

void Boss::initAnimations() {
    animationTimer.restart();
}

Sprite Boss::getSprite() {
    return sprite;
}

void Boss::move(const float dir_x, const float dir_y) {
    position.x += dir_x * speed;
    position.y += dir_y * speed;
    sprite.setPosition(position);
}
void Boss::setPosition(const float x, const float y) {
    position.x = x;
    position.y = y;
}

void Boss::updateMovement(){

    if(timeout-- <= 0) {
        direction = rand() % 4 + 1;
        timeout = rand() % 100;
    }
        animState = BOSS_ANIMATION_STATES::IDLE1;
        if (direction == 1) {
            move(0, 2);
//            animState = BOSS_ANIMATION_STATES::MOVING_DOWN1;

        }
        if (direction == 2) {
            move(0, -2);
//            animState = BOSS_ANIMATION_STATES::MOVING_UP1;

        }
        if (direction == 3) {
            move(-2, 0);
//            animState = BOSS_ANIMATION_STATES::MOVING_LEFT1;

        }
        if (direction == 4) {
            move(2, 0);
            // sprite.setTextureRect(currentFrame);
//            animState = BOSS_ANIMATION_STATES::MOVING_RIGHT1;

        }
}

void Boss::updateAnimations() {
    IntRect tempFrame;
    // Animacion IDLE
    if (animState == BOSS_ANIMATION_STATES::IDLE1) {
        // Cuando pasa medio segundo, ahi recien que empieze a animar
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            // Hacemos que vuelva arriba, debido a nuestro boss sheet
            currentFrame.top = 0;
            currentFrame.left += 80.f;

            if (currentFrame.left >= 760.f)
                currentFrame.left = 400.f;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

        }
    }
    else if (animState == BOSS_ANIMATION_STATES::MOVING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.3f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 80.f;
            currentFrame.left += 80.f;

            if (currentFrame.left == 240.f) {
                // Aumenta el tamanio del sprite
                // Cargamos la textura como sprite
                tempFrame = IntRect(currentFrame.left, currentFrame.top, 70, 60);
                currentFrame = tempFrame;
            }
            else if (currentFrame.left == 320.f) {
                tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                currentFrame = tempFrame;
            }
            else if (currentFrame.left == 440.f ) {
                tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                currentFrame = tempFrame;
            }
             else if (currentFrame.left >= 560.f) {
                // Reinicio de animacion
                animState = BOSS_ANIMATION_STATES::IDLE1;
                currentFrame = IntRect(0, 0, 40, 60);
            }

            std::cout << currentFrame.left << std::endl;
            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            setBossLookingRight(true);
        }
    }
    else
        animationTimer.restart();
}

void Boss::attack(){
    //ataque del boss
}

void Boss::attackAnimation(){

    IntRect tempFrame;
    if (animState == BOSS_ANIMATION_STATES::MOVING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.3f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 80.f;
            currentFrame.left += 80.f;

            if (currentFrame.left == 240.f) {
                // Aumenta el tamanio del sprite
                // Cargamos la textura como sprite
                tempFrame = IntRect(currentFrame.left, currentFrame.top, 70, 60);
                currentFrame = tempFrame;
            }
            else if (currentFrame.left == 320.f) {
                tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                currentFrame = tempFrame;
            }
            else if (currentFrame.left == 440.f ) {
                tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                currentFrame = tempFrame;
            }
            else if (currentFrame.left >= 560.f) {
                // Reinicio de animacion
                animState = BOSS_ANIMATION_STATES::IDLE1;
                currentFrame = IntRect(0, 0, 40, 60);
            }

            std::cout << currentFrame.left << std::endl;
            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            setBossLookingRight(true);
        }
    }
    else
        animationTimer.restart();
}
void Boss::resetSpeed() {
    speed = 0;
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

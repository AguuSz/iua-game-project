//
// Created by Agus on 14/9/2020.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(String name, int maxHp) {

    this->maxHp = maxHp;
    currentHp = maxHp;

    initVariables();
    initAnimations();
}

void Enemy::initVariables() {
    animState = ENEMY_ANIMATION_STATES::INACTIVE;
    scaleFactor = 3;
    movementTimer.restart();
}

void Enemy::initAnimations() {
    animationTimer.restart();
    animationSwitch = true;
}

void Enemy::update() {

    updateMovement();
    updateAnimations();
}

void Enemy::updateAnimations() {
    if (animState == ENEMY_ANIMATION_STATES::INACTIVE) {
        // Animacion IDLE (35x36)
        if (animationTimer.getElapsedTime().asSeconds() >= 0.3f) {
            currentFrame.top = 60.f;
            currentFrame.left += 150.f;

            if (currentFrame.left >= 505.f)
                currentFrame.left = 55.f;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
}

Sprite Enemy::getSprite() {
    return this->sprite;
}

void Enemy::setTexture(String directory) {
    if(!this->texture.loadFromFile(directory))
        std::cout << "Se ha producido un error";
    this->sprite.setTexture(texture);

    currentFrame = IntRect(55, 60, 40, 45);
    sprite.setTextureRect(currentFrame);

    this->sprite.setScale(scaleFactor, scaleFactor);
}

void Enemy::setPosition(int x, int y) {
    this->position.x = x;
    this->position.y = y;

    sprite.setPosition(position);
}

RectangleShape Enemy::getEnemyHitbox() {
    box.setSize(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    box.setOutlineColor(Color::Red);
    box.setOutlineThickness(2);
    box.setFillColor(Color::Transparent);
    box.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);

    return box;
}

void Enemy::updateMovement() {
    if (movementTimer.getElapsedTime().asSeconds() > 3) {
        // Moverse despues de 3 segundos
        // Falta la logica del movimiento y direccion de movimiento
        // this->move();
    }

}

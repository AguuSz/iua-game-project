//
// Created by Agus on 14/9/2020.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(String name, int maxHp) {

    this->maxHp = maxHp;
    currentHp = maxHp;


}

void Enemy::initVariables() {
    scaleFactor = 2;
}

void Enemy::initAnimations() {

}

void Enemy::updateAnimations() {
    if (animState == ENEMY_ANIMATION_STATES::IDLEE) {
        // Animacion IDLE (35x36)
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 65.f;
            currentFrame.left += 58.f;
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
    this->sprite.setScale(scaleFactor, scaleFactor);
}

void Enemy::setPosition(int x, int y) {
    this->position.x = x;
    this->position.y = y;

    sprite.setPosition(position);
}

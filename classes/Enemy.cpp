//
// Created by Agus on 14/9/2020.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
    maxHp = 10;
    currentHp = maxHp;
    isMoving = false;
    isInvincible = false;

    animState = ENEMY_ANIMATION_STATES::INACTIVE;
    scaleFactor = 2.5f;
    movementTimer.restart();

    animationTimer.restart();
}

Enemy::Enemy(std::string directory, Vector2f initialPosition):Enemy() {
    setTexture(directory);
    setPosition(initialPosition.x, initialPosition.y);
}

void Enemy::setTexture(String directory) {
    if(!this->texture.loadFromFile(directory))
        std::cout << "Se ha producido un error";
    this->sprite.setTexture(texture);

    currentFrame = IntRect(55, 60, 40, 45);
    sprite.setTextureRect(currentFrame);

    this->sprite.setScale(scaleFactor, scaleFactor);
}

void Enemy::update() {

    updateMovement();
    updateAnimations();
    updateLife();
}

void Enemy::updateAnimations() {
    if (animState == ENEMY_ANIMATION_STATES::INACTIVE) {
        // Animacion IDLE (35x36)
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            currentFrame.top = 60.f;
            currentFrame.left += 150.f;

            if (currentFrame.left >= 505.f)
                currentFrame.left = 55.f;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == ENEMY_ANIMATION_STATES::TOOKDAMAGE) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 360.f; // 60 + 150 * linea en la que esta (en este caso 2)
            currentFrame.left += 150.f;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 540.f) {
                isInvincible = false;
                currentFrame.left = 55.f;
                animState = ENEMY_ANIMATION_STATES::INACTIVE;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }

    sprite.setScale(-scaleFactor, scaleFactor);
    sprite.setOrigin(sprite.getGlobalBounds().width / scaleFactor, 0.f);
}

Sprite Enemy::getSprite() const {
    return this->sprite;
}

void Enemy::setPosition(int x, int y) {
    this->position.x = x;
    this->position.y = y;

    sprite.setPosition(position);
}

RectangleShape Enemy::getEnemyHitbox() {
    box.setSize(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    box.setOutlineColor(Color::Red);
    box.setOutlineThickness(1);
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

void Enemy::updateLife() {

}

void Enemy::damage() {
    isInvincible = true;
    currentFrame.left = 55.f;
    animState = ENEMY_ANIMATION_STATES::TOOKDAMAGE;

    // Luego de 5 balas, el enemigo muere
    currentHp -= 2;
    if (currentHp <= 0) {
        // Muere
        // Aca iria la animacion de muerte, la destruccion del objeto, contadorEnemigosLvl--;
    }
}

void Enemy::setEnemyLookingRight(bool lookRight) {
    if (lookRight) {
        sprite.setScale(scaleFactor, scaleFactor);
        sprite.setOrigin(0.f, 0.f);
    } else {
        sprite.setScale(-scaleFactor, scaleFactor);
        sprite.setOrigin(sprite.getGlobalBounds().width / scaleFactor, 0.f);
    }
}


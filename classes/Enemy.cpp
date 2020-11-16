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
    ignorePlayerPosition = false;
    cannotMove = false;
    isDead = false;
    isAttacking = false;
    attacked = false;

    animState = ENEMY_ANIMATION_STATES::INACTIVE;
    scaleFactor = 2.5f;
    movementTimer.restart();

    animationTimer.restart();
}

Enemy::Enemy(std::string directory, Vector2f initialPosition, bool doesFly):Enemy() {
    setTexture(directory);
    setPosition(initialPosition.x, initialPosition.y);
    this->doesFly = doesFly;
}

void Enemy::setTexture(String directory) {
    if(!this->texture.loadFromFile(directory))
        std::cout << "Se ha producido un error";
    this->sprite.setTexture(texture);

    currentFrame = IntRect(55, 60, 40, 45);
    sprite.setTextureRect(currentFrame);

    this->sprite.setScale(scaleFactor, scaleFactor);
}

void Enemy::setScaleFactor(float sf) {
    scaleFactor = sf;
}

void Enemy::update() {

    updateMovement();
    updateAnimations();
}

void Enemy::meleeAttack() {
    isAttacking = true;
    cannotMove = true;
    currentFrame.left = 55.f;
    animState = ENEMY_ANIMATION_STATES::ATTACKING;
}

void Enemy::updateAnimations() {
    if (animState == ENEMY_ANIMATION_STATES::INACTIVE) {
        // Animacion IDLE (35x36)
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            currentFrame.top = 60.f;
            currentFrame.left += 150.f;
            attacked = false;

            if (currentFrame.left >= 540.f)
                currentFrame.left = 55.f;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            // Una vez termine de correr, que vuelva a tener en cuenta la posicion del jugador
            ignorePlayerPosition = false;
        }
    }
    else if (animState == ENEMY_ANIMATION_STATES::RUNNING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 210.f; // 60 + 150 * linea en la que esta (en este caso 1)
            currentFrame.left += 150.f;
            attacked = false;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 1080.f) {
                currentFrame.left = 55.f;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == ENEMY_ANIMATION_STATES::TOOKDAMAGE) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 360.f; // 60 + 150 * linea en la que esta (en este caso 2)
            currentFrame.left += 150.f;
            attacked = false;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 540.f) {
                isInvincible = false;
                cannotMove = false;
                attacked = true;
                currentFrame.left = 55.f;
                animState = ENEMY_ANIMATION_STATES::INACTIVE;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == ENEMY_ANIMATION_STATES::ATTACKING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.10f) {
            currentFrame.top = 510.f; // 60 + 150 * linea en la que esta (en este caso 1)
            currentFrame.left += 150.f;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 1080.f) {
                cannotMove = false;
                isAttacking = false;
                attacked = true;
                currentFrame.left = 55.f;
                animState = ENEMY_ANIMATION_STATES::INACTIVE;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == ENEMY_ANIMATION_STATES::DEATH) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 660.f; // 60 + 150 * linea en la que esta (en este caso 4)
            currentFrame.left += 150.f;
            attacked = false;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 540.f) {
                isInvincible = false;
                isDead = true;
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
    box.setOutlineThickness(2);
    box.setFillColor(Color::Transparent);
    box.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);

    return box;
}

void Enemy::move(const float dir_x, const float dir_y) {
    position.x += dir_x * speed;
    position.y += dir_y * speed;

    animState = ENEMY_ANIMATION_STATES::RUNNING;

    sprite.setPosition(position);
}

void Enemy::updateMovement() {
    if(timeout-- <= 0) {
        direction = rand() % 6 + 1;
        timeout = rand() % 120;
    }
    if (!cannotMove) {
        if (doesFly) {
            switch (direction) {
                case 1:
                    move(0, 2);
                    break;
                case 2:
                    move(0, -2);
                    break;
                case 3:
                    move(-2, 0);
                    break;
                case 4:
                    move(2, 0);
                    break;
                default:
                    animState = ENEMY_ANIMATION_STATES::INACTIVE;
                    break;
            }
        } else {
            switch (direction) {
                case 1:
                    ignorePlayerPosition = true;
                    setEnemyLookingRight(false);
                    move(-2, 0);
                    break;
                case 2:
                    ignorePlayerPosition = true;
                    setEnemyLookingRight(true);
                    move(2, 0);
                    break;
                default:
                    animState = ENEMY_ANIMATION_STATES::INACTIVE;
                    break;
            }
        }
    }
}

void Enemy::damage() {
    isInvincible = true;
    cannotMove = true;
    currentFrame.left = 55.f;
    animState = ENEMY_ANIMATION_STATES::TOOKDAMAGE;

    // Luego de 5 balas, el enemigo muere
    currentHp -= 2;
    if (currentHp <= 0) {
        // Muere
        animState = ENEMY_ANIMATION_STATES::DEATH;
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

Vector2f Enemy::getPosition() {
    return position;
}

bool Enemy::dead() {
    return isDead;
}



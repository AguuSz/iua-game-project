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
    bossShootingTimer.restart();

}

// Declaramos las funciones

void Boss::initVariables(){
    //vida
    maxHp = 100;
    currentHp = 20;
    invincible = false;
    moving = false;
    isGoing = true;
    isDead =  false;
    cannotMove = false;
    speed = 1;
    canAttack = true;

    scaleFactor = 4;
    animState = BOSS_ANIMATION_STATES::IDLE1;
    position = Vector2f(50, 50);

    bossShootingTimer.restart();
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
    sprite.setScale(scaleFactor, scaleFactor);

    sprite.setPosition(position);
}

void Boss::initAnimations() {
    animationTimer.restart();
}

Sprite Boss::getSprite() {
    return sprite;
}

Vector2f Boss::getPosition() {
    return this->position;
}

bool Boss::isBossDead() {
    return isDead;
}

bool Boss::isInvincible() {
    return invincible;
}

bool Boss::isMoving(){
    return moving;
}

Vector2<float> Boss::getMiddlePoint() {

    Vector2f middlePoint;
    middlePoint.x = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2;
    middlePoint.y = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2;
    return middlePoint;
}

void Boss::setPosition(int x, int y) {
    this->position.x = x;
    this->position.y = y;

    sprite.setPosition(position);
}

void Boss::update(Player &player) {
    updateMovement();
    updateShooting(player);
    updateAnimations();
}

void Boss::updateMovement(){

    if(timeout-- <= 0) {
        direction = rand() % 6 + 1;
        timeout = rand() % 100;
    }
    if (!cannotMove) {
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
                animState = BOSS_ANIMATION_STATES::IDLE1;
                break;
        }
    }
    sprite.setPosition(position);
}

void Boss::updateShooting(Player &player) {
    bossDir = player.getMiddlePoint() - getMiddlePoint();
    bossDirNormalized = bossDir / static_cast<float>(sqrt(pow(bossDir.x, 2) + pow(bossDir.y, 2)));

    if (bossShootingTimer.getElapsedTime().asSeconds() >= 3.f) {
        cannotMove = true;
        if (animState != BOSS_ANIMATION_STATES::SHOOTING)
            currentFrame.left = 0;
        animState = BOSS_ANIMATION_STATES::SHOOTING;
    }
}

void Boss::updateAnimations() {
    IntRect tempFrame;
    // Animacion IDLE
    if (animState == BOSS_ANIMATION_STATES::IDLE1) {
        moving = false;
        invincible = false;
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
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 80.f;
            moving = true;
            if (isGoing) {
                currentFrame.left += 80.f;

                if (currentFrame.left == 240.f) {
                    // Aumenta el tamanio del sprite
                    // Cargamos la textura como sprite
                    tempFrame = IntRect(currentFrame.left, currentFrame.top, 70, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left == 320.f) {
                    tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left == 440.f) {
                    tempFrame = IntRect(currentFrame.left + 40, currentFrame.top, 76, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left >= 560.f) {
                    // Reinicio de animacion
                    isGoing = false;
                    currentFrame.left = 480.f;
                }
            } else {
                if (currentFrame.left == 480.f) {
                    // Aumenta el tamanio del sprite
                    // Cargamos la textura como sprite
                    tempFrame = IntRect(360.f, currentFrame.top, 70, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left == 360.f) {
                    tempFrame = IntRect(240.f, currentFrame.top, 76, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left == 240.f) {
                    tempFrame = IntRect(160.f, currentFrame.top, 76, 60);
                    currentFrame = tempFrame;
                } else if (currentFrame.left <= 160.f) {
                    // Reinicio de animacion
                    currentFrame = IntRect(0, 0, 40, 60);
                    animState = BOSS_ANIMATION_STATES::IDLE1;
                    isGoing = true;
                    moving = false;
                }
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == BOSS_ANIMATION_STATES::TAKEHIT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.30f) {
            currentFrame.top = 160.f; // 60 + 150 * linea en la que esta (en este caso 2)
            currentFrame.left += 80.f;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 120.f) {
                invincible = false;
                cannotMove = false;
                currentFrame.left = 0.f;
                animState = BOSS_ANIMATION_STATES::IDLE1;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == BOSS_ANIMATION_STATES::SHOOTING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.10f) {
            currentFrame.top = 239.f; // 60 + 150 * linea en la que esta (en este caso 2)
            currentFrame.left += 80.f;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 760.f) {
                cannotMove = false;
                attack();
                currentFrame.left = 0.f;
                animState = BOSS_ANIMATION_STATES::IDLE1;
                bossShootingTimer.restart();
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == BOSS_ANIMATION_STATES::DEAD) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.25f) {
            currentFrame.top = 321.f; // 60 + 150 * linea en la que esta (en este caso 4)
            currentFrame.left += 80.f;

            // Cuando llega al final de la sheet vuelve al estado inactivo
            if (currentFrame.left >= 720.f) {
                isDead = true;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
}

void Boss::attack(){
    //Ataque boss
    boss1.sprite.setPosition(getMiddlePoint());
    boss1.currVelocity = bossDirNormalized * (boss1.maxSpeed + 10);
    bossBullets.emplace_back(boss1);
};

void Boss::move(const float dir_x, const float dir_y) {
    this->position.x += dir_x * speed;
    this->position.y += dir_y * speed;
    sprite.setPosition(position);
}

void Boss::damage() {
    invincible = true;
    cannotMove = true;
    currentFrame.left = 0;
    animState = BOSS_ANIMATION_STATES::TAKEHIT;

    // Luego de 5 balas, el enemigo muere
    currentHp -= 2;
    if (currentHp <= 0) {
        // Muere
        this->position.y += 2;
        animState = BOSS_ANIMATION_STATES::DEAD;
    }
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

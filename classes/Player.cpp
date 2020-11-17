//
// Created by Agus on 28/8/2020.
//
#include <iostream>
#include "Player.h"

// Constructor
Player::Player() {
    // Inicializa las variables del jake
    initVariables();
    initTexture();
    initSprite();
    initAnimations();
    initPhysics();
}

// Declaracion de funciones

void Player::initVariables() {
    // Vida
    maxHp = 10;
    currentHp = 10;
    isInvincible = false;

    scaleFactor = 2.5;
    animState = IDLE;
    
    sprite.setPosition(0, 0);
    middlePoint.x = getGlobalBounds().left + getGlobalBounds().width / 2;
    middlePoint.y = getGlobalBounds().top + getGlobalBounds().height / 2;
}

void Player::initTexture() {
    // Se carga la textura, y si tira error, que nos muestre el error
    if(!texture.loadFromFile("../assets/player_sheet.png"))
        std::cout << "ERROR::PLAYER:: No se ha podido cargar la textura del jake." << std::endl;
}

void Player::initSprite() {
    // Cargamos la textura como sprite
    sprite.setTexture(texture);
    currentFrame = IntRect(0, 0, 40, 50);

    sprite.setTextureRect(currentFrame);

    // Reescalando la textura
    sprite.scale(scaleFactor, scaleFactor);
}

void Player::initAnimations() {
    animationTimer.restart();
}

void Player::initPhysics() {

    speed.x = 5.f;
    speed.y = 0.f;

    gravity = 1.f;

    isJumping = false;

}

Sprite Player::getSprite() {
    return sprite;
}

void Player::move(const float dir_x) {
    // Movimiento en X
    position.x += dir_x * speed.x;
}

void Player::jump() {
    isJumping = true;
    speed.y = -30.f;
}

void Player::updatePhysics() {
    // Hace que la gravedad siempre le haga efecto
    speed.y += gravity;

    position.y += speed.y;

    // Mueve el sprite
    sprite.setPosition(position);
}

void Player::updateMovement() {
    animState = PLAYER_ANIMATION_STATES::IDLE;
    // Maneja el movimiento del jugador
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        move(-1.f);
        animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (!isJumping)
                jump();
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        move(1.f);
        animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (!isJumping)
                jump();
        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (!isJumping)
            jump();
    }

    else if (std::abs(speed.y) > 0.f) {
        animState = PLAYER_ANIMATION_STATES::FALLING;
    }

    else if (isPlayerInvincible()) {
        animState = PLAYER_ANIMATION_STATES::DAMAGED;
    }
}

void Player::updateAnimations() {
    // Animacion IDLE
    if (animState == PLAYER_ANIMATION_STATES::IDLE) {
        // Cuando pasa medio segundo, ahi recien que empieze a animar
        if (animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            // Hacemos que vuelva arriba, debido a nuestro jake sheet
            currentFrame.top = 0;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 160.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            ignoreMouseDirection = false;
        }
    }
    // Animacion hacia la derecha
    else if (animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 50.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 360.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            ignoreMouseDirection = true;
            setPlayerLookingRight(true);
        }
    }

    else if (animState == PLAYER_ANIMATION_STATES::MOVING_LEFT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
            // Hacemos que se posicione en la 2da fila de nuestro sheet
            currentFrame.top = 50.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 360.f)
                currentFrame.left = 0;

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            ignoreMouseDirection = true;
            setPlayerLookingRight(false);
        }
    }

    else if(animState == PLAYER_ANIMATION_STATES::FALLING) {
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
    else if (animState == PLAYER_ANIMATION_STATES::DAMAGED) {
        // Cuando pasa medio segundo, ahi recien que empieze a animar
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            // Hacemos que vuelva arriba, debido a nuestro jake sheet
            currentFrame.top = 300.f;
            currentFrame.left += 40.f;

            if (currentFrame.left >= 80.f) {
                currentFrame.left = 0;
                isInvincible = false;
            }

            // Una vez haya puedo un nuevo frame, que reinicie el timer para esperar otros 0.5s
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

            ignoreMouseDirection = false;
        }
    }
    else
        animationTimer.restart();
}

// Funcion que va a ser llamada para updatear los valores
void Player::update() {
    updateMovement();
    updateAnimations();
    updatePhysics();
    updateMiddlePoint();
    updateHp();
}

void Player::damage() {
    animState = PLAYER_ANIMATION_STATES::DAMAGED;
    currentFrame.left = 0;
    isInvincible = true;
    currentHp -= 2;
}

void Player::updateHp() {
    if (currentHp <= 0) {
        // El player muere
        //std::cout << "El player ha muerto.\n";
    }
}

const FloatRect Player::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

bool Player::isPlayerInvincible() {
    return isInvincible;
}

void Player::resetVelocityY() {
    speed.y = 0.f;
}

void Player::resetVelocityX() {
    speed.x = 0.f;
}

void Player::setPosition(const float x, const float y) {
    position.x = x;
    position.y = y;
}

const Vector2f Player::getMiddlePoint() const {
    return middlePoint;
}

void Player::updateMiddlePoint() {
    middlePoint.x = getGlobalBounds().left + getGlobalBounds().width / 2;
    middlePoint.y = getGlobalBounds().top + getGlobalBounds().height / 2;
}

RectangleShape Player::playerBox() {
    // Funcion solo utilizada para el desarrollo del juego
    // Nos devuelve un rectangulo con el tamanio del sprite del jugador
    box.setSize(Vector2f(getGlobalBounds().width, getGlobalBounds().height));
    box.setOutlineColor(Color::Red);
    box.setOutlineThickness(2);
    box.setFillColor(Color::Transparent);
    box.setPosition(getGlobalBounds().left, getGlobalBounds().top);

    return box;
}

void Player::allowJumping() {
    isJumping = false;
}

Vector2f Player::getPosition() {
    return this->position;
}

void Player::setPlayerLookingRight(bool lookRight) {
    if (lookRight) {
        sprite.setScale(scaleFactor, scaleFactor);
        sprite.setOrigin(0.f, 0.f);
    } else {
        sprite.setScale(-scaleFactor, scaleFactor);
        sprite.setOrigin(sprite.getGlobalBounds().width / scaleFactor, 0.f);
    }
}

Sprite Player::getHearthSprite() {
    return sprite;
}


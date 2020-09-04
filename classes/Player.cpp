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

    scaleFactor = 3;
    animState = IDLE;
    
    sprite.setPosition(0, 1000);
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
    animationSwitch = true;
}

void Player::initPhysics() {
    velocityMax = 7.f;
    velocityMin = 1.f;
    acceleration = 3.f;
    drag = 0.7f;
    gravity = 3.f;
    velocityMaxY = 2.f;
}

Sprite Player::getSprite() {
    return sprite;
}

void Player::move(const float dir_x, const float dir_y) {
    // Aceleracion
    velocity.x += dir_x * acceleration;
    // Limitando la velocidad
    if (std::abs(velocity.x) > velocityMax) {
        // Esto hace que el limite de la velocidad sea velocityMax
        // Comprueba si va en direccion negativa o positiva para asignarle un valor acorde
        velocity.x = velocityMax * ((velocity.x < 0) ? -1.f : 1.f);
    }
}

void Player::updatePhysics() {

    // Gravedad
    velocity.y += 1.0f * gravity;
    // Limitando la velocidad vertical por la gravedad
    if (std::abs(velocity.y) < velocityMaxY) {
        // Esto hace que el limite de la velocidad sea velocityMax
        // Comprueba si va en direccion negativa o positiva para asignarle un valor acorde
        velocity.y = velocityMaxY * ((velocity.y < 0) ? -1.f : 1.f);
    }

    // Desaceleracion
    // Multiplica la velocidad por la desaceleracion
    velocity *= drag;
    // Limita la desaceleracion
    if (std::abs(velocity.x) < velocityMin)
        velocity.x = 0.f;
    if (std::abs(velocity.y) < velocityMin)
        velocity.y = 0.f;

    // Mueve el sprite
    sprite.move(velocity);
}

void Player::updateMovement() {
    animState = PLAYER_ANIMATION_STATES::IDLE;
    // Maneja el movimiento del jugador
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        move(-1.f, 0.f);
        animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        move(1.f, 0.f);
        animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
    }
    else if (velocity.y > 0.f) {
        animState = PLAYER_ANIMATION_STATES::FALLING;
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
        }

        sprite.setScale(scaleFactor, scaleFactor);
        sprite.setOrigin(0.f, 0.f);
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
        }

        sprite.setScale(-scaleFactor, scaleFactor);
        sprite.setOrigin(sprite.getGlobalBounds().width / scaleFactor, 0.f);
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
    else
        animationTimer.restart();
}

// Funcion que va a ser llamada para updatear los valores
void Player::update() {

    updateMovement();
    updateAnimations();
    updatePhysics();
    updateMiddlePoint();
}

const FloatRect Player::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Player::resetVelocityY() {
    velocity.y = 0.f;
}

void Player::resetVelocityX() {
    velocity.x = 0.f;
}

void Player::setPosition(const float x, const float y) {
    sprite.setPosition(x, y);
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

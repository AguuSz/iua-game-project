#include <SFML/Graphics.hpp>
#include <string>
#include "Bullet.h"

#pragma once

enum BOSS_ANIMATION_STATES {IDLE1 = 0, MOVING, TAKEHIT, SHOOTING, DEAD};

using namespace sf;

class Boss {

private:

    // Vida del jefe
    int currentHp;
    int maxHp;
    bool invincible;
    bool isDead;

    // Animaciones
    Clock animationTimer;
    short animState;
    IntRect currentFrame;
    float scaleFactor;
    bool isGoing;
    bool cannotMove;

    // Texturas
    Sprite sprite;
    Texture texture;

    //Fisicas
    Vector2f position;
    int speed;
    int direction = 0;
    int timeout = 0;
    int timeoutHability = 0;
    bool moving;

    //Ataque
    Bullet bossHability;
    std::vector<Bullet> bossProyectiles;
    float bossShootingDelay;
    Clock bossShootingTimer;

    // Nucleo
    void initVariables();
    void initSprite();
    void initTexture();
    void initAnimations();

public:
    // Constructor
    Boss();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();
    Vector2f getPosition();
    bool isBossDead();
    bool isInvincible();
    bool isMoving();

    //Modificadores
    void setPosition(int x, int y);

    //Funciones
    void update();
    void updateMovement();
    void updateAnimations();
    void updateShooting(Vector2f &playerPosition);
    void move(const float dir_x, const float dir_y);
    void damage();
    void setBossLookingRight(bool lookRight);
};

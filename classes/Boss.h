#include <SFML/Graphics.hpp>
#include <string>
#include "Bullet.h"
#include "Player.h"
#include <math.h>

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
    bool moving;
    bool canAttack;

    //Ataque
    Clock bossShootingTimer;
    Bullet boss1 = 7;
    Vector2f bossDir;
    Vector2f bossDirNormalized;

    // Nucleo
    void initVariables();
    void initSprite();
    void initTexture();
    void initAnimations();
    void initSounds();

public:

    //Sonidos
    SoundBuffer bossAttackBuffer;
    Sound bossAttack;
    SoundBuffer bossDiesBuffer;
    Sound bossDies;
    SoundBuffer bossTakeDamageBuffer;
    Sound bossTakeDamage;

    // Constructor
    std::vector<Bullet> bossBullets;
    Boss();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();
    Vector2f getPosition();
    bool isBossDead();
    bool isInvincible();
    bool isMoving();
    Vector2<float> getMiddlePoint();

    //Modificadores
    void setPosition(int x, int y);

    //Funciones
    void update(Player &player);
    void updateMovement();
    void updateAnimations();
    void updateShooting(Player &player);
    void attack();
    void move(const float dir_x, const float dir_y);
    void damage();
    void setBossLookingRight(bool lookRight);
};

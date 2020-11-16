//
// Created by Agus on 14/9/2020.
//

#ifndef IUAPROJECT_ENEMY_H
#define IUAPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include <math.h>

using namespace sf;

enum ENEMY_ANIMATION_STATES {INACTIVE = 0, RUNNING, TOOKDAMAGE, ATTACKING, DEATH};


class Enemy {
public:
    String name;

    // Vida
    int maxHp;
    int currentHp;
    bool isInvincible;
    bool isDead;

    // Animaciones
    Clock animationTimer;
    short animState;
    IntRect currentFrame;
    float scaleFactor;

    // Timers
    Clock movementTimer;

    // Texturas
    Sprite sprite;
    Texture texture;

    // Fisicas
    int speed = 1;
    Vector2f position;
    bool isMoving;
    int direction = 0;
    int timeout = 0;
    bool doesFly;
    bool ignorePlayerPosition;
    bool cannotMove;
    bool isAttacking;
    bool attacked;

    //Ataque
    Clock enemyShootingTimer;
    Bullet enemy1 = 7;
    Vector2f enemyDir;
    Vector2f enemyDirNormalized;

    // Dev
    RectangleShape box;

    // Nucleo
    void initVariables();
    void initAnimations();


    // Actualizaciones por frame
    void updateAnimations();
    void updateMovement();
    void updateLife();
    void updateShooting(Player &player);

    // Constructor
    std::vector<Bullet> enemyBullets;
    Enemy();

    Enemy(std::string directory, Vector2f initialPosition, bool doesFly);

    // Sprite para dibujar
    Sprite getSprite() const;
    Vector2f getPosition();
    bool dead();
    Vector2<float> getMiddlePoint() const;

    // Setters
    void setTexture(String directory);
    void setPosition(int x, int y);

    // Funciones
    void update(Player &player);
    void damage();
    void meleeAttack();
    void distanceAttack();
    void move(const float dir_x, const float dir_y);
    RectangleShape getEnemyHitbox();

    void setEnemyLookingRight(bool lookRight);

    void setScaleFactor(float scaleFactor);
};


#endif //IUAPROJECT_ENEMY_H

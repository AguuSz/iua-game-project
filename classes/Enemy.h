//
// Created by Agus on 14/9/2020.
//

#ifndef IUAPROJECT_ENEMY_H
#define IUAPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>
using namespace sf;

enum ENEMY_ANIMATION_STATES {INACTIVE = 0, RUNNING, TOOKDAMAGE, ATTACKING, DEATH};

class Enemy {
public:
    String name;

    // Vida
    int maxHp;
    int currentHp;
    bool isInvincible;

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
    Vector2f speed;
    Vector2f position;
    bool isMoving;

    // Dev
    RectangleShape box;

    // Nucleo
    void initVariables();
    void initAnimations();

    // Actualizaciones por frame
    void updateAnimations();
    void updateMovement();
    void updateLife();

    // Constructor
    Enemy();

    Enemy(std::string directory, Vector2f initialPosition);

    // Sprite para dibujar
    Sprite getSprite() const;

    // Setters
    void setTexture(String directory);
    void setPosition(int x, int y);

    // Funciones
    void update();
    void damage();
    void move();
    RectangleShape getEnemyHitbox();

    void setEnemyLookingRight(bool lookRight);

    void setScaleFactor(float scaleFactor);
};


#endif //IUAPROJECT_ENEMY_H

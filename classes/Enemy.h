//
// Created by Agus on 14/9/2020.
//

#ifndef IUAPROJECT_ENEMY_H
#define IUAPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>
using namespace sf;

enum ENEMY_ANIMATION_STATES {INACTIVE = 0, RUNNING, TOOKDAMAGE, ATTACKING, DEATH};

class Enemy {

private:

    String name;

    // Vida
    int maxHp;
    int currentHp;

    // Animaciones
    Clock animationTimer;
    short animState;
    IntRect currentFrame;
    bool animationSwitch;
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

public:
    // Constructor
    Enemy(String name, int maxHp);

    // Sprite para dibujar
    Sprite getSprite();

    // Setters
    void setTexture(String directory);
    void setPosition(int x, int y);

    // Funciones
    void update();
    void move();
    RectangleShape getEnemyHitbox();
};


#endif //IUAPROJECT_ENEMY_H

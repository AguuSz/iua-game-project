//
// Created by Agus on 14/9/2020.
//

#ifndef IUAPROJECT_ENEMY_H
#define IUAPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>
using namespace sf;

enum ENEMY_ANIMATION_STATES {IDLEE = 0, RUNNING, TOOKDAMAGE, ATTACKING ,DEATH};

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

    // Texturas
    Sprite sprite;
    Texture texture;

    // Fisicas
    Vector2f speed;
    Vector2f position;

    // Dev
    RectangleShape box;

    // Nucleo
    void initVariables();
    void initAnimations();

public:
    // Constructor
    Enemy(String name, int maxHp);

    // Sprite para dibujar
    Sprite getSprite();
    const FloatRect getGlobalBounds() const;

    // Setters
    void setTexture(String directory);
    void setPosition(int x, int y);

    // Funciones
    void update();
    void move();
    void getEnemyHitbox();
    void updateAnimations();

};


#endif //IUAPROJECT_ENEMY_H

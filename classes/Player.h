//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>

using namespace sf;

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player {
private:
    // Vida del jugador
    int currentHp;
    int maxHp;

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
    Vector2f position;
    Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;
    float gravity;
    float velocityMaxY;

    // Nucleo
    void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    // Constructor
    Player();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();
    const FloatRect getGlobalBounds() const;

    // Modificadores
    void setPosition(const float x, const float y);
    void resetVelocityY();

    // Funciones
    void update();
    void move(const float dir_x, const float dir_y);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();

};

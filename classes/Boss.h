#include <SFML/Graphics.hpp>
#include <string>
#include "Bullet.h"


enum BOSS_ANIMATION_STATES {IDLE1 = 0, MOVING};

using namespace sf;

class Boss {

private:

    String name;
    // Vida del jefe
    int currentHp;
    int maxHp;
    bool isInvincible;

    //Propiedades de los ataques del jefe
    float projectileSpeed;
    float damageMultiplier;

    // Animaciones
    Clock animationTimer;
    short animState;
    IntRect currentFrame;
    float scaleFactor;
    bool isGoing;

    // Texturas
    Sprite sprite;
    Texture texture;

    //Fisicas
    Vector2f position;
    int speed = 1;
    int movementLenght = 100;
    int direction = 0;
    int timeout = 0;
    int timeoutHability = 0;
    bool moving;

    //Ataque
    Bullet bossHability;
    std::vector<Bullet> bossProyectiles;
    float bossShootingDelay;
    Clock bossShootingTimer;

    //Extras
    Vector2f middlePoint;

    // Dev
    RectangleShape box;

    // Nucleo
    void initVariables();
    void initSprite();
    void initTexture();
    void initAnimations();
    void initPhysics();

public:
    // Constructor
    Boss();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();
    const Vector2f getMiddlePoint() const;
    const FloatRect getGlobalBounds() const;

    //Modificadores
    void setPosition(const float x, const float y);
    void resetVelocityY();
    void resetVelocityX();

    //Funciones
    void attackAnimation();
    void move(const float dir_x, const float dir_y);
    void resetSpeed();
    bool isMoving();
    void belowHalfLife();
    void update();
    void updateMiddlePoint();
    void updateMovement();
    void updateAnimations();
    void updateShooting(Vector2f playerPosition);
    void setBossLookingRight(bool lookRight);

    // Dev
    RectangleShape bossBox();

    Vector2f getPosition();
};

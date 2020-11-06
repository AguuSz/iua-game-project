#include <SFML/Graphics.hpp>
#include <string>
//#include "Habilidad.h"

enum BOSS_ANIMATION_STATES {IDLE1 = 0, MOVING_LEFT1, MOVING_RIGHT1, MOVING_DOWN1, MOVING_UP1};

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

    // Texturas
    Sprite sprite;
    Texture texture;

    //Fisicas
    Vector2f position;
    int speed = 1;
    int movementLenght = 100;
    int direction = 0;
    int timeout = 0;

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
    void attack();
    void move(const float dir_x, const float dir_y);
    void belowHalfLife();
    void update();
    void updateMiddlePoint();
    void updateMovement();
    void updateAnimations();
    void setBossLookingRight(bool lookRight);

    // Dev
    RectangleShape bossBox();

    Vector2f getPosition();
};

#include <SFML/Graphics.hpp>
#include <string>
//#include "Habilidad.h"

//enum JEFE_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_DOWN, MOVING_UP};

using namespace sf;

class Jefe {

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
    bool animationSwitch;
    float scaleFactor;

    // Texturas
    Sprite sprite;
    Texture texture;
    String directory;

    //Fisicas
    Vector2f position;
    Vector2f velocity;

    // Dev
    RectangleShape box;

    // Nucleo
    void initVariables();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    // Constructor
    Jefe(String name, float maxHp);

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    // Setters
    void setTexture(String directory);


    //Seteo de imagen
    void setAsset(String directory);
    //Modificadores
    void setPosition(const float x, const float y);
    void resetVelocityY();
    void resetVelocityX();

    //Funciones
    void attack();
    void moveX(const float dir_x);
    void moveY(const float dir_y);
    void belowHalfLife();
    void update();
    void updatePhysics();
    void updateMovement();
    void updateAnimations();

    // Dev
    // RectangleShape jefeBox();
};

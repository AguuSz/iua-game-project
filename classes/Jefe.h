#include <SFML/Graphics.hpp>
#include <string>
//#include "Habilidad.h"

using namespace sf;

class Jefe {

private:

    // Vida del jefe
    int currentHp;
    int maxHp;

    //Propiedades de los ataques del jefe
    float projectileSpeed;
    float damageMultiplier;
    float movementSpeed;



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
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    // Constructor
    Jefe(float currentHp, float maxHp, float projectileSpeed, float damageMultiplier, float movementSpeed);

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();


    //Seteo de imagen
    void setAsset(String directory);
    //Modificadores
    void resetVelocityY();
    void resetVelocityX();

    //Funciones
    void attack();
    void belowHalfLife();
    void update();
    void updatePhysics();
    void updateMovement();
    void updateAnimations();

    // Dev
    RectangleShape jefeBox();
};

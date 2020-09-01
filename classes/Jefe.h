#include <SFML/Graphics.hpp>
#include <string>
//#include "Habilidad.h"

using namespace sf;

class Jefe {

private:

    Vector2f position;

//    Habilidad ability;

    Sprite sprite;
    Texture texture;

    float vida;

    int damage;

    int projectileSpeed;

    int damageMultiplier;

    float movementSpeed;

public:
    // Constructor
    Jefe();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    void move(Vector2f nextPosition);

    void attack();

    void belowHalfLife();

    void update(float elapsedTime);

};

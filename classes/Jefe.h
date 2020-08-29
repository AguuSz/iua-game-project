#include <SFML/Graphics.hpp>
#include <string>
#include "Habilidad.h"

using namespace sf;

class Jefe {

private:

    Vector2f position;

    Habilidad ability;

    Sprite sprite;
    Texture texture;

    String name;

    float health;

    float damage;

    float projectileSpeed;

    float damageMultiplier;

    float movementSpeed;

public:
    // Constructor
    Jefe(String name, float health, float damage, float projectileSpeed, float damageMultiplier, float movementSpeed);

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    void randomMovement(Vector2f nextPosition);

    void attack();

    void belowHalfLife();

    void update(float elapsedTime);


    void randomMovement(Vector2f nextPosition, float health);
};

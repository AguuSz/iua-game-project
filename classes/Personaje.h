//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>

using namespace sf;

class Personaje {
private:
    Vector2f position;

    Sprite sprite;

    Texture texture;

    bool esHombre; // true = hombre ; false = mujer

    bool leftKeyPressed;
    bool rightKeyPressed;

    float movementSpeed;

public:
    // Constructor
    Personaje();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    // Mover a la izquierda
    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(float elapsedTime);

    void setGenero(bool genero){
        Personaje::esHombre = genero;
    }

    bool getGenero(){
        return Personaje::esHombre;
    }
};

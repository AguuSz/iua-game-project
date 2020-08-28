//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
#include "Jake.h"

using namespace sf;

class Engine {
private:
    RenderWindow window;

    Sprite bkgSprite;
    Texture bkgTexture;

    // Instancia de Jake
    Jake jake;

    // Funciones para el funcionamiento
    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    Engine();

    // Inicia el juego llamando a todas las funciones privadas
    void start();

};

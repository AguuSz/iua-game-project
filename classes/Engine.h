//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Engine {
private:
    RenderWindow window;

    Sprite bkgSprite;
    Texture bkgTexture;

    // Instancia de Jake
    Player player;

    // Funciones para el funcionamiento
    void input(Event event);
    void update();
    void updateCollision();
    void draw();

public:
    Engine();

    // Inicia el juego llamando a todas las funciones privadas
    void start();

};

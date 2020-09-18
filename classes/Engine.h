//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

using namespace sf;

class Engine {
private:
    // Ventana del juego
    RenderWindow window;

    // Vista del jugador
    View view;

    // Instancia del jugador
    Player player;

    // Nivel
    Level level;

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

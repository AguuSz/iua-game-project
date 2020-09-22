//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include "Bullet.h"
#include <vector>

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

    // Bala
    Bullet b1;
    std::vector<Bullet> bullets;

    // Mouse
    Mouse mouse;
    Vector2i pixelPos;
    Vector2f worldPos;
    RectangleShape rectangle;
    Vector2f aimDir;
    Vector2f aimDirNormalized;

    // Funciones para el funcionamiento
    void input(Event event);
    void updateMousePosition();
    void update();
    void updateCollision();
    void draw();

public:
    Engine();

    // Inicia el juego llamando a todas las funciones privadas
    void start();

};

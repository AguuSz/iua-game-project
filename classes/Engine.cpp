//
// Created by Agus on 28/8/2020.
//

#include "Engine.h"
using namespace sf;

Engine::Engine() {
    // Setea la resolucion con la que se va a jugar
    Vector2f resolution;
    resolution.x = 1366;
    resolution.y = 768;

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Default);

    window.setFramerateLimit(60);

    // Setea el fondo del nivel
    level.setBackground("../assets/background2.jpg");
    level.setBackgroundScale(0.7);

    // Enemy para borrar dsp
    level.setEnemyTexture("../assets/enemies/Goblin/Idle.png");
    level.setEnemyPosition(0, 0);

    // Datos del rectangulo para ver donde esta el mouse, que luego se eliminara
    rectangle.setSize(Vector2f(50, 50));
    rectangle.setOutlineColor(Color::Blue);
    rectangle.setOutlineThickness(3);
    rectangle.setFillColor(Color::Transparent);
    // ------------------------------------------------------------

    view.reset(FloatRect(300, 300, 1400, 800));

}

void Engine::start() {
    while(window.isOpen()) {
        Event event;
        input(event);
        update();
        updateCollision();
        draw();
        while(window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}
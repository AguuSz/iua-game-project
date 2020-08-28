//
// Created by Agus on 28/8/2020.
//

#include "Engine.h"
using namespace sf;

Engine::Engine() {
    // Setea la resolucion con la que se va a jugar
    Vector2f resolution;
    resolution.x = 1350;
    resolution.y = 600;

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Default);

    window.setFramerateLimit(144);

    // Carga la textura del fondo en una textura
    bkgTexture.loadFromFile("../assets/background1.jpg");

    // Setea el sprite en base a la textura
    bkgSprite.setTexture(bkgTexture);

}

void Engine::start() {
    // Timing
    Clock clock;

    while(window.isOpen()) {
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
        Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}
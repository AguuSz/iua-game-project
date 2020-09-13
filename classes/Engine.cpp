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

    // Carga la textura del fondo en una textura
    bkgTexture.loadFromFile("../assets/background2.jpg");

    // Setea el sprite en base a la textura
    bkgSprite.setTexture(bkgTexture);
    bkgSprite.scale(0.7f, 0.7f);

    view.reset(FloatRect(300, 300, 1800, 1200));

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
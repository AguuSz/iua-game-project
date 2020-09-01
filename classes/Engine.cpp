//
// Created by Agus on 28/8/2020.
//

#include "Engine.h"
using namespace sf;

Engine::Engine() {
    // Setea la resolucion con la que se va a jugar
    Vector2f resolution;
    resolution.x = 1920;
    resolution.y = 1080;

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Fullscreen);

    window.setFramerateLimit(60);

    // Carga la textura del fondo en una textura
    bkgTexture.loadFromFile("../assets/background2.jpg");

    // Setea el sprite en base a la textura
    bkgSprite.setTexture(bkgTexture);
    bkgSprite.scale(0.8f, 0.75f);

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
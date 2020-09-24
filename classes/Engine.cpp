//
// Created by Agus on 28/8/2020.
//

#include "Engine.h"
using namespace sf;

Engine::Engine() {
    // Setea la resolucion con la que se va a jugar
    Vector2f resolution;
    resolution.x = VideoMode().getDesktopMode().width;
    resolution.y = VideoMode().getDesktopMode().height;
//    resolution.x = 1366;
//    resolution.y = 768;

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Fullscreen);

    window.setFramerateLimit(60);

    // Datos del rectangulo para ver donde esta el mouse, que luego se eliminara
    setMouseHitbox();

    view.reset(FloatRect(300, 300, 1400, 800));

    player.setPosition(1, 500);

}

void Engine::start() {
    while(window.isOpen()) {
        Event event;
        input(event);
        update();
        checkForCollisions();
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


void Engine::setMouseHitbox() {
    rectangle.setSize(Vector2f(50, 50));
    rectangle.setOutlineColor(Color::Blue);
    rectangle.setOutlineThickness(3);
    rectangle.setFillColor(Color::Transparent);
}

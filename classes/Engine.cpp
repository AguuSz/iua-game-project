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

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Fullscreen);

    window.setFramerateLimit(60);

    // Datos del rectangulo para ver donde esta el mouse, que luego se eliminara
    window.setMouseCursorVisible(false);
    setMouseSprite();
    setMouseHitbox();

    view.reset(FloatRect(300, 300, 900, 800));

    shootingDelay = 0.1f;
    shootingTimer.restart();

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
            if (event.type == Event::Closed)
                window.close();
        }
    }
}


void Engine::setMouseHitbox() {
    mouseHitbox.setSize(Vector2f(50, 50));
    mouseHitbox.setOutlineColor(Color::Blue);
    mouseHitbox.setOutlineThickness(3);
    mouseHitbox.setFillColor(Color::Transparent);
}

void Engine::setMouseSprite() {
    if (!mouseTexture.loadFromFile("../assets/mouseSprite.png"))
        std::cout << "ERROR::MOUSE No se ha podido cargar el sprite.";
    mouseSprite.setTexture(mouseTexture);
    mouseSprite.scale(0.10f, 0.10f);
}

Sprite Engine::drawMouse() {
    return mouseSprite;
}
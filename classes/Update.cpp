//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"
using namespace sf;

void Engine::update() {
    player.update();

    level.update();

    updateMousePosition();
    rectangle.setPosition(worldPos.x - 25, worldPos.y - 20);

    // Falta la deteccion de colision...
}

void Engine::updateMousePosition() {
    pixelPos = mouse.getPosition(window);
    worldPos = window.mapPixelToCoords(pixelPos);
}
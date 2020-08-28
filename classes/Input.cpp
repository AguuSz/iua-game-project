//
// Created by Agus on 28/8/2020.
//
#include "classes/Engine.h"

void Engine::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    // Maneja el movimiento del jugador
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        jake.moveLeft();
    } else {
        jake.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        jake.moveRight();
    } else {
        jake.stopRight();
    }
}
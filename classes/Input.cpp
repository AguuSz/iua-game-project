//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"
#include <iostream>

void Engine::input(Event event) {

    // Aca se manejan las teclas que sean aparte del jugador
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

}
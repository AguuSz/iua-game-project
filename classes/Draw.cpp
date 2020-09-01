//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"

void Engine::draw() {
    // Limpia la pantalla
    window.clear();

    // Dibuja el fondo
    window.draw(bkgSprite);
    window.draw(player.getSprite());

    // Mostrar lo que hemos dibujado
    window.display();
}


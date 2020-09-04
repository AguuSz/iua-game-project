//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"

void Engine::draw() {
    // Limpia la pantalla
    window.clear();

    // Vista que sigue al jugador
    view.setCenter(player.getMiddlePoint().x, player.getMiddlePoint().y - 200);
    window.setView(view);

    // Dibuja el fondo
    window.draw(bkgSprite);
    window.draw(player.getSprite());
    window.draw(player.playerBox());

    // Mostrar lo que hemos dibujado
    window.display();
}


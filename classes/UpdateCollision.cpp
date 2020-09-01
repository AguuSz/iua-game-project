//
// Created by Agus on 1/9/2020.
//

#include "Engine.h"

void Engine::updateCollision() {
    // Colision dada al tocar el fondo de la pantalla
    if(player.getGlobalBounds().top + player.getGlobalBounds().height >= window.getSize().y - 35) {
        player.resetVelocityY();
        player.setPosition(player.getGlobalBounds().left,
                           window.getSize().y - player.getGlobalBounds().height - 35);
    }
}

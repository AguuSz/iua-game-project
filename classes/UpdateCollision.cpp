//
// Created by Agus on 1/9/2020.
//

#include "Engine.h"

void Engine::updateCollision() {
    // Colision dada al tocar el fondo de la pantalla
    if(player.getGlobalBounds().top + player.getGlobalBounds().height >= window.getSize().y - 85) {
        player.resetVelocityY();
        player.setPosition(player.getGlobalBounds().left,
                           window.getSize().y - player.getGlobalBounds().height - 85);
    }
    if(player.getGlobalBounds().left + player.getGlobalBounds().width >= window.getSize().x + 20){
        player.resetVelocityX();
        player.setPosition(window.getSize().x - player.getGlobalBounds().width + 20, player.getGlobalBounds().top);
    }
    if(player.getGlobalBounds().left <= 0 - 20){
        player.resetVelocityX();
        player.setPosition(0 - 20, player.getGlobalBounds().top);
    }
}

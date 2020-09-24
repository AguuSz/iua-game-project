//
// Created by Agus on 1/9/2020.
//

#include "Engine.h"

void Engine::checkForCollisions() {

    // Colision dada al tocar el fondo de la pantalla
    if(player.getGlobalBounds().top + player.getGlobalBounds().height >= window.getSize().y - 85) {
        player.resetVelocityY();
        player.allowJumping();
        player.setPosition(player.getGlobalBounds().left,
                           window.getSize().y - player.getGlobalBounds().height - 85);
    }
    // Colision al tocar la parte derecha
//    if(player.getGlobalBounds().left + player.getGlobalBounds().width >= 1240){
//        player.resetVelocityX();
//        player.setPosition(1240 - player.getGlobalBounds().width, player.getGlobalBounds().top);
//    }
//    // Colision al tocar la parte izquierda
//    if(player.getGlobalBounds().left < 0){
//        player.setPosition(0, player.getGlobalBounds().top);
//    }

}

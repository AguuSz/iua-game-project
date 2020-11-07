//
// Created by Agus on 1/9/2020.
//

#include "Engine.h"

void Engine::checkForCollisions() {
    // Colision al tocar la parte de abajo
     if(player.getGlobalBounds().top + player.getGlobalBounds().height >= window.getSize().y - 25) {
        player.resetVelocityY();
        player.allowJumping();
        player.setPosition(player.getGlobalBounds().left,
                           window.getSize().y - player.getGlobalBounds().height - 25);
    }

     //Colision al tocar la parte derecha
    if(player.getGlobalBounds().left + player.getGlobalBounds().width >= 1360*level.getInstance()){
        if(player.getPosition().x >= 1360*level.getInstance()){
            player.setPosition(1360*level.getInstance(), player.getPosition().y);
        }else {
            player.setPosition(1360 * level.getInstance() - player.getGlobalBounds().width,
                               player.getPosition().y);
        };
    }
    // Colision al tocar la parte izquierda
    if(player.getGlobalBounds().left < (1360*level.getInstance() - 1360)){
        if(player.getPosition().x < (1360*level.getInstance() - 1360)){
            player.setPosition(1360*level.getInstance() - 1360, player.getPosition().y);
        }else {
            player.setPosition(0, player.getPosition().y);
        }
    }

    // Bala impactando al enemigo
    for (size_t i = 0; i < bullets.size(); i++) {
        // Checkea si impacta con el goblin
        for (auto &e: level.enemies) {
            if (bullets[i].sprite.getGlobalBounds().intersects(e.getSprite().getGlobalBounds())) {
                // Impacto con el enemigo
                bullets.erase(bullets.begin() + i);
                if (!e.isInvincible) {
                    e.damage();
                    break;
                }
            }
        }

    }

    for (auto &e: level.enemies) {
        if (player.getGlobalBounds().intersects(e.getSprite().getGlobalBounds())) {
            // Si el player choca con alguno de los enemigos

        }
    }
}

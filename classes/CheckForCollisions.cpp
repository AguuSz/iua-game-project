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

    for (size_t i = 0; i < level.boss->bossBullets.size(); i++) {
        // loopea las balas del jefe, y comprobamos si alguna impacta con el jugador
        if (level.boss->bossBullets[i].sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
            // Si impacta con el player
            level.boss->bossBullets.erase(level.boss->bossBullets.begin() + i);
            if (!player.isPlayerInvincible()) {
                player.damage();
                break;
            }
        }

        // Si las balas del enemigo se salen de la pantalla, que las borre
        if (isOutOfScreen(level.boss->bossBullets[i].sprite.getGlobalBounds(), window, level)) {
            level.boss->bossBullets.erase(level.boss->bossBullets.begin() + i );
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

            // Checkea si alguna bala disparada por el enemigo impacta con el player
            for (int j = 0; j < e.enemyBullets.size(); j++) {
                if (e.enemyBullets[j].sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
                    // Impacta con el player
                    e.enemyBullets.erase(e.enemyBullets.begin() + j);
                    if (!player.isPlayerInvincible()) {
                        player.damage();
                        break;
                    }
                }

                // Si las balas del enemigo se salen de la pantalla, que las borre
                if (isOutOfScreen(e.enemyBullets[j].sprite.getGlobalBounds(), window, level)) {
                    e.enemyBullets.erase(e.enemyBullets.begin() + i );
                }
            }
        }
        if (bullets[i].sprite.getGlobalBounds().intersects(level.boss->getSprite().getGlobalBounds())) {
            if (!level.boss->isInvincible()) {
                bullets.erase(bullets.begin() + i);
                level.boss->damage();
            }
        }

        // Si las balas del player se salen de la pantalla, que las borre
        if (isOutOfScreen(bullets[i].sprite.getGlobalBounds(), window, level)) {
            bullets.erase(bullets.begin() + i );
        }

    }

    for (auto &e: level.enemies) {
        if (player.getGlobalBounds().intersects(e.getSprite().getGlobalBounds())) {
            // Si el player choca con alguno de los enemigos
            if (!e.isAttacking) {
                e.meleeAttack();
            }

            // Hace que si el jugador no es invencible, que le haga danio
            if (!player.isPlayerInvincible() && e.attacked) {
                player.damage();
            }
        }

        // El enemigo se choco con la parte izquierda de la pantalla o instancia
        if (e.getSprite().getGlobalBounds().left <= (1360*level.getInstance() - 1360)) {
            e.setPosition(1360*level.getInstance() - 1360, e.getSprite().getGlobalBounds().top);
        }

        // El enemigo se choco con la parte derecha de la pantalla o instancia
        if (e.getSprite().getGlobalBounds().left + e.getSprite().getGlobalBounds().width >= 1360*level.getInstance()) {
            e.setPosition(1360*level.getInstance() - e.getSprite().getGlobalBounds().width, e.getSprite().getGlobalBounds().top);
        }

        // El enemigo se choco con el techo de la pantalla o instancia
        if (e.getSprite().getGlobalBounds().top <= 0) {
            e.setPosition(e.getSprite().getGlobalBounds().left, 0);
        }

        // El enemigo se choco con el piso de la pantalla o instancia
        if (e.getSprite().getGlobalBounds().top + e.getSprite().getGlobalBounds().height >= window.getSize().y - 15) {
            e.setPosition(e.getSprite().getGlobalBounds().left, window.getSize().y - 15 - e.getSprite().getGlobalBounds().height);
        }
    }

    // Jefe colisionando con nivel
    // El jefe se choco con la parte izquierda de la pantalla o instancia
    if (level.boss->getSprite().getGlobalBounds().left <= (1360*level.getInstance() - 1360)) {
        level.boss->setPosition(1360*level.getInstance() - 1360, level.boss->getSprite().getGlobalBounds().top);
    }

    // El jefe se choco con la parte derecha de la pantalla o instancia
    if (level.boss->getSprite().getGlobalBounds().left + level.boss->getSprite().getGlobalBounds().width >= 1360*level.getInstance()) {
        level.boss->setPosition(1360*level.getInstance() - level.boss->getSprite().getGlobalBounds().width, level.boss->getSprite().getGlobalBounds().top);
    }

    // El jefe se choco con el techo de la pantalla o instancia
    if (level.boss->getSprite().getGlobalBounds().top <= 0) {
        level.boss->setPosition(level.boss->getSprite().getGlobalBounds().left, 0);
    }

    // El jefe se choco con el piso de la pantalla o instancia
    if (level.boss->getSprite().getGlobalBounds().top + level.boss->getSprite().getGlobalBounds().height >= window.getSize().y - 25) {
        level.boss->setPosition(level.boss->getSprite().getGlobalBounds().left, window.getSize().y - 25 - level.boss->getSprite().getGlobalBounds().height);
    }
}

bool Engine::isOutOfScreen(Rect<float> element, Window &screen, Level &level) {
    if (element.left <= (1360*level.getInstance() - 1360)) {
        return true;
    }

    // El jefe se choco con la parte derecha de la pantalla o instancia
    if (element.left + element.width >= 1360*level.getInstance()) {
        return true;
    }

    // El jefe se choco con el techo de la pantalla o instancia
    if (element.top <= 0) {
        return true;
    }

    // El jefe se choco con el piso de la pantalla o instancia
    if (element.top + element.height >= screen.getSize().y - 25) {
        return true;
    }

    return false;
}
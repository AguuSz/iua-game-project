//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"

void Engine::draw() {
    // Limpia la pantalla
    window.clear();

    if(!level.boss->isDead){

        //Texto muerte
        // Vista que sigue al jugador
        view.setCenter(player.getMiddlePoint().x, window.getSize().y / 2 +40);
        window.setView(view);

        // Dibuja el fondo
        level.draw(window);
        window.draw(player.getSprite());

        for (int i = 0; i < player.hp.size(); i++) {
            Sprite hpSprite = player.hp.top().getSprite();
            hpSprite.setPosition(player.getPosition().x - 540 + (i * 55), hpSprite.getPosition().y + 5);
            window.draw(hpSprite);

        }
        // Dibuja las balas que haya en el array bullets
        for (auto & bullet : bullets) {
            window.draw(bullet.sprite);
        }
        for (auto & bossBullet : level.boss->bossBullets) {
            window.draw(bossBullet.sprite);
        }

        // Dibujando la textura del mouse
        window.draw(drawMouse());
    }else{
        window.draw(winningText);
        window.draw(winningText2);
    }

    if(player.didPlayerDie){
        window.draw(player.deadText);
    }
    // Mostrar lo que hemos dibujado
    window.display();
}
//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"

void Engine::draw() {
    // Limpia la pantalla
    window.clear();

    // Vista que sigue al jugador
    view.setCenter(player.getMiddlePoint().x, window.getSize().y / 2 +40);
    window.setView(view);

    // Dibuja el fondo
    level.draw(window);
    window.draw(player.getSprite());

    while (!player.hp.empty()) {
        window.draw(player.hp.top().getSprite());
        std::cout << "Vida del player: " << player.hp.size() << std::endl;
        player.hp.pop();
    }

    //Texto muerte
    if(player.didPlayerDie){
        window.draw(player.deadText);
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

    // Mostrar lo que hemos dibujado
    window.display();
}
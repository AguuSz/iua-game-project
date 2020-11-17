//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"
#include <iostream>

void Engine::input(Event& event) {

    // Aca se manejan las teclas que sean aparte del jugador
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (gameState == 2) {
            gameState = 1;
            menuIsOpen = true;
            std::cout << "GameState: " << gameState << std::endl;
            std::cout << "IsOpen: " << menuIsOpen << std::endl;
        }
    }



    // Disparo
    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (shootingTimer.getElapsedTime().asSeconds() >= shootingDelay) {
            b1.sprite.setPosition(player.getMiddlePoint().x, player.getMiddlePoint().y - 15);
            b1.currVelocity = aimDirNormalized * b1.maxSpeed;

            bullets.emplace_back(b1);
            shootingTimer.restart();
        }

    }

    if (Keyboard::isKeyPressed(Keyboard::O)) {
        // Que active el hitbox del mouse como si fuera un enemigo, asi lo podemos posicionar
    }

}
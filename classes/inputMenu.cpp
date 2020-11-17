//
// Created by Gaston on 16/11/2020.
//

#ifndef IUAPROJECT_INPUTMENU_H
#define IUAPROJECT_INPUTMENU_H

#endif //IUAPROJECT_INPUTMENU_H
#include <iostream>
#include "Engine.h"

void Engine::inputMenu(Event& event) {

    while(window.pollEvent(event)) {

        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if(event.type == sf::Event::KeyPressed){
            if(Keyboard::isKeyPressed(Keyboard::Escape)) {
                if (gameState == 1) {
                    gameState = 2;
                    menuIsOpen = false;


                }
            }
            if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (Engine::index < 3) {
                    Engine::index++;

                }
            }

            if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (Engine::index > 0) {
                    Engine::index--;

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter)){
                menu();
            }
        }
    }
}
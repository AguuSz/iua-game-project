//
// Created by Gaston on 16/11/2020.
//

#ifndef IUAPROJECT_INPUTMENU_H
#define IUAPROJECT_INPUTMENU_H

#endif //IUAPROJECT_INPUTMENU_H
#include <iostream>
#include "Engine.h"

void Engine::inputMenu(Event& event) {

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                switch (gameState) {
                    case 0:
                        window.close();
                        break;
                    case 1:
                        gameState = 2;
                        menuIsOpen = false;
                        break;
                    case 3:
                        gameState = 0;
                        break;

                }
            }
            if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                switch (gameState) {
                    case 0:
                    case 1:
                        if (Engine::index < 3) {
                            Engine::index++;
                        }
                        break;
                    case 3:
                        if (Engine::optionsMenuIndex < 2) {
                            Engine::optionsMenuIndex++;
                        }


                }
            }

            if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                switch (gameState) {
                    case 0:
                    case 1:
                        if (Engine::index > 0) {
                            Engine::index--;
                        }
                        break;
                    case 3:
                        if (Engine::optionsMenuIndex > 0) {
                            Engine::optionsMenuIndex--;
                        }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                switch (gameState) {
                    case 0:
                        mainMenu();
                        break;
                    case 1:
                        menu();
                        break;
                    case 3:
                        optionsMenu();

                }
            }
            if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                switch (gameState) {
                    case 3:
                        switch (optionsMenuIndex) {
                            case 0:
                                if (Engine::backgroundMusic.getVolume() > 1) {
                                    Engine::backgroundMusic.setVolume(Engine::backgroundMusic.getVolume() - 1);
                                    break;
                                    case 1:
                                        if (level.enemies.front().effectsVolume > 1) {
                                            int actualVolume = level.enemies.front().effectsVolume;
                                            for(auto &e:level.enemies){
                                                e.updateSounds(actualVolume-1);;
                                            };
                                        }

                                }

                        }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                switch (gameState) {
                    case 3:
                        switch (optionsMenuIndex) {
                            case 0:
                                if (Engine::backgroundMusic.getVolume() < 100) {
                                    Engine::backgroundMusic.setVolume(Engine::backgroundMusic.getVolume() + 1);
                                    break;
                                }
                            case 1:
                                if (level.enemies.front().effectsVolume < 100) {
                                    for(auto &e:level.enemies){
                                        int actualVolume = level.enemies.front().effectsVolume;
                                        e.updateSounds(actualVolume+1);
                                    };
                                }
                                break;
                        }
                }

            }
        }
    }
}

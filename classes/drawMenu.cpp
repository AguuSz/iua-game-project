//
// Created by Gaston on 17/11/2020.
//
#include "Engine.h"
#include <iostream>
void Engine::drawMenu() {


    menuTexture.loadFromFile("../assets/Menu1.jpg");
    if(!menuTexture.loadFromFile("../assets/Menu1.jpg"))
        std::cout << "ERROR::MENU:: No se ha podido cargar la textura del menu" << std::endl;
    menuSprite.setTexture(menuTexture);
    menuSprite.setPosition(player.getPosition().x-250,200);
    window.draw(menuSprite);
    selectedOption.setOutlineColor(Color(63, 47, 39, 255));
    selectedOption.setOutlineThickness(3);
    selectedOption.setFillColor(Color::Transparent);
    switch(index){
        case 0:
            selectedOption.setSize(Vector2f(291, 50));
            selectedOption.setPosition(player.getPosition().x-60, 267);
            break;
        case 1:
            selectedOption.setSize(Vector2f(253, 53));
            selectedOption.setPosition(player.getPosition().x-38, 321);
            break;
        case 2:
            selectedOption.setSize(Vector2f(253, 48));
            selectedOption.setPosition(player.getPosition().x-38, 380);
            break;
        case 3:
            selectedOption.setSize(Vector2f(147, 48));
            selectedOption.setPosition(player.getPosition().x+11, 437);

    }
    window.draw(selectedOption);
    window.display();
}

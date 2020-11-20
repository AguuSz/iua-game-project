//
// Created by Gaston on 17/11/2020.
//
#include "Engine.h"
#include <iostream>
#include <string>


void Engine::drawMenu() {

    sf::Font fuente;
    if (!fuente.loadFromFile("../assets/SourceSerifPro-Bold.ttf")) {
        std::cout << "ERROR::DRAWMENU_FONT no se ha podido cargar la fuente del menu.";
    }
    sf::Text volMusica, volEfectos;
    std::string vol_Musica, vol_Efectos;
    volM = round(backgroundMusic.getVolume());
    


    vol_Musica = std::to_string(volM);
    vol_Efectos = std::to_string(volE);

    volEfectos.setString(vol_Efectos);
    volMusica.setString(vol_Musica);

    volMusica.setFont(fuente);
    volEfectos.setFont(fuente);
    volMusica.setCharacterSize(40);
    volEfectos.setCharacterSize(40);

    volMusica.setColor(Color());
    volEfectos.setColor(Color());
    optionsMenuTexture.loadFromFile("../assets/menuOpciones.jpg");
    if (!optionsMenuTexture.loadFromFile("../assets/menuOpciones.jpg"))
        std::cout << "ERROR::MENU:: No se ha podido cargar la textura del menu de opciones" << std::endl;
    optionsMenuSprite.setTexture(optionsMenuTexture);




    switch(gameState) {
        case 0:
            //Menu principal
            window.clear();
            mainMenuTexture.loadFromFile("../assets/MenuPrincipal.jpg");
            if (!mainMenuTexture.loadFromFile("../assets/MenuPrincipal.jpg"))
                std::cout << "ERROR::MENU:: No se ha podido cargar la textura del menu principal" << std::endl;
            mainMenuSprite.setTexture(mainMenuTexture);
            mainMenuSprite.setPosition((level.getInstance()-1)*1360, 0);

            window.draw(mainMenuSprite);
            selectedOption.setOutlineColor(Color(63, 47, 39, 255));
            selectedOption.setOutlineThickness(3);
            selectedOption.setFillColor(Color::Transparent);
            switch (index) {
                case 0:
                    selectedOption.setSize(Vector2f(359, 61));
                    selectedOption.setPosition((level.getInstance()-1)*1360+507, 247);
                    break;
                case 1:
                    selectedOption.setSize(Vector2f(458, 62));
                    selectedOption.setPosition((level.getInstance()-1)*1360+453, 303);
                    break;
                case 2:
                    selectedOption.setSize(Vector2f(291, 61));
                    selectedOption.setPosition((level.getInstance()-1)*1360+531, 373);
                    break;
                case 3:
                    selectedOption.setSize(Vector2f(185, 62));
                    selectedOption.setPosition((level.getInstance()-1)*1360+583, 427);
                    break;
            }
            window.draw(selectedOption);
            window.display();
            break;
        case 1:
            // Menu ingame
            menuTexture.loadFromFile("../assets/Menu1.jpg");
            if (!menuTexture.loadFromFile("../assets/Menu1.jpg"))
                std::cout << "ERROR::MENU:: No se ha podido cargar la textura del menu ingame" << std::endl;
            menuSprite.setTexture(menuTexture);
            menuSprite.setPosition(player.getPosition().x - 250, 200);
            window.draw(menuSprite);
            selectedOption.setOutlineColor(Color(63, 47, 39, 255));
            selectedOption.setOutlineThickness(3);
            selectedOption.setFillColor(Color::Transparent);
            switch (index) {
                case 0:
                    selectedOption.setSize(Vector2f(291, 50));
                    selectedOption.setPosition(player.getPosition().x - 60, 267);
                    break;
                case 1:
                    selectedOption.setSize(Vector2f(253, 53));
                    selectedOption.setPosition(player.getPosition().x - 38, 321);
                    break;
                case 2:
                    selectedOption.setSize(Vector2f(253, 48));
                    selectedOption.setPosition(player.getPosition().x - 38, 380);
                    break;
                case 3:
                    selectedOption.setSize(Vector2f(147, 48));
                    selectedOption.setPosition(player.getPosition().x + 11, 437);

            }
            window.draw(selectedOption);
            window.display();
            break;
        case 6:
            // Menu opciones
            window.clear();
            optionsMenuSprite.setPosition((level.getInstance()-1)*1360, 0);
            window.draw(optionsMenuSprite);

            volMusica.setPosition((level.getInstance()-1)*1360+670, 330);
            volEfectos.setPosition((level.getInstance()-1)*1360+670, 435);

            window.draw(volMusica);
            window.draw(volEfectos);

            selectedOption.setOutlineColor(Color(63, 47, 39, 255));
            selectedOption.setOutlineThickness(3);
            selectedOption.setFillColor(Color::Transparent);
            switch (optionsMenuIndex) {
                case 0:
                    selectedOption.setSize(Vector2f(80, 40));
                    selectedOption.setPosition((level.getInstance()-1)*1360+650, 335);
                    break;
                case 1:
                    selectedOption.setSize(Vector2f(80, 40));
                    selectedOption.setPosition((level.getInstance()-1)*1360+650, 440);
                    break;
                case 2:
                    selectedOption.setSize(Vector2f(200, 55));
                    selectedOption.setPosition((level.getInstance()-1)*1360+585, 545);
                    break;


            }
            window.draw(selectedOption);
            window.display();
            break;
        case 3:
            // Menu opciones
            window.clear();
            window.draw(optionsMenuSprite);

            volMusica.setPosition(670, 330);
            volEfectos.setPosition(670, 435);

            window.draw(volMusica);
            window.draw(volEfectos);

            selectedOption.setOutlineColor(Color(63, 47, 39, 255));
            selectedOption.setOutlineThickness(3);
            selectedOption.setFillColor(Color::Transparent);
            switch (optionsMenuIndex) {
                case 0:
                    selectedOption.setSize(Vector2f(80, 40));
                    selectedOption.setPosition(650, 335);
                    break;
                case 1:
                    selectedOption.setSize(Vector2f(80, 40));
                    selectedOption.setPosition(650, 440);
                    break;
                case 2:
                    selectedOption.setSize(Vector2f(200, 55));
                    selectedOption.setPosition(585, 545);
                    break;


            }
            window.draw(selectedOption);
            window.display();
            break;

    }
}

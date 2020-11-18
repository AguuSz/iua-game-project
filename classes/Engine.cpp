//
// Created by Agus on 28/8/2020.
//

#include "Engine.h"
#include <fstream>

using namespace sf;

Engine::Engine() {
    // Setea la resolucion con la que se va a jugar
    Vector2f resolution;
    /*resolution.x = VideoMode().getDesktopMode().width;
    resolution.y = VideoMode().getDesktopMode().height;*/
    resolution.x = 1360;
    resolution.y = 766;

    window.create(VideoMode(resolution.x, resolution.y),
                  "IUA Game project",
                  Style::Default);

    window.setFramerateLimit(60);

    // Datos del rectangulo para ver donde esta el mouse, que luego se eliminara
    window.setMouseCursorVisible(false);
    setMouseSprite();
    setMouseHitbox();

    view.reset(FloatRect(300, 300, (resolution.x / 16) * 14, (resolution.y / 9) * 10));

    shootingDelay = 0.2f;
    shootingTimer.restart();

    player.setPosition(1, 500);

}

void Engine::start() {

    Event event;
    bool bandera = false;
    menuIsOpen = true;

    //Musica de fondo
    if(!level.doPlayBossMusic()) {
        if (!backgroundMusic.openFromFile("../assets/sounds/backgroundMusic.ogg")) {
            std::cout << "ERROR::BACKGROUND_MUSIC no se ha podido cargar el archivo";
        }
        backgroundMusic.setVolume(10);
        backgroundMusic.setLoop(true);
        backgroundMusic.play();
    }


    while(window.isOpen()) {

    if(!bandera){
        index = 0;
        bandera = true;
    }

        switch(gameState){
            case 0:
                inputMenu(event);
                drawMenu();
                break;

            case 1:
                inputMenu(event);
                drawMenu();
                break;
            case 2:

                input(event);
                update();
                checkForCollisions();
                draw();
                while(window.pollEvent(event)){
                    if (event.type == Event::Closed)
                        window.close();
                }
                break;
        case 3:
            std::cout << "Opciones" << std::endl;
            break;
        case 4:
            std::cout << "Nueva partida" << std::endl;
            break;
        case 5:
            std::cout << "Guardar" << std::endl;
            break;

            default:
                gameState = 0;
                break;
        }

    }
}


void Engine::setMouseHitbox() {
    mouseHitbox.setSize(Vector2f(50, 50));
    mouseHitbox.setOutlineColor(Color::Blue);
    mouseHitbox.setOutlineThickness(3);
    mouseHitbox.setFillColor(Color::Transparent);
}

void Engine::setMouseSprite() {
    if (!mouseTexture.loadFromFile("../assets/mouseSprite.png"))
        std::cout << "ERROR::MOUSE No se ha podido cargar el sprite.";
    mouseSprite.setTexture(mouseTexture);
    mouseSprite.scale(0.10f, 0.10f);
}

Sprite Engine::drawMouse() {
    return mouseSprite;
}

// Menu

void Engine::menu() {
    if(Engine::menuIsOpen){
        switch(index){
            case 0:
                gameState = 2;
                break;
            case 1:
                gameState = 5;
                break;
            case 2:
                gameState = 3;
                break;
            case 3:
                window.close();
                break;
        }

    }
}

void Engine::mainMenu() {
    if(Engine::menuIsOpen){
        switch(index){
            case 0:
                gameState = 2;
                break;
            case 1:
                gameState = 4;
                break;
            case 2:
                gameState = 3;
                break;
            case 3:
                window.close();


        }

    }
}
//
// Created by Agus on 14/9/2020.
//

#include "Level.h"

Level::Level() {
    setInitialValues();
    setDmgMultiplier(3);

    levelFinished = false;
}

// Seccion valores iniciales
void Level::setInitialValues() {
    setBackground("../assets/background2.jpg");
    setBackgroundScale(0.7f);

    enemies.emplace_back("../assets/enemies/Goblin/goblinSheet.png", Vector2f(250, 550));
    enemies.emplace_back("../assets/enemies/Goblin/goblinSheet.png", Vector2f(400, 550));



}

void Level::setBackground(String directory) {
    bkgTexture.loadFromFile(directory);
    bkgSprite.setTexture(bkgTexture);
}

void Level::setBackgroundScale(float scaleFactor) {
    bkgSprite.scale(scaleFactor, scaleFactor);
}

void Level::setDmgMultiplier(float multiplier) {
    this->dmgMultiplier = multiplier;
}

void Level::endLevel() {
    levelFinished = true;
}

// Seccion game-loop
void Level::draw(RenderWindow &window) {
    // Dibuja el fondo
    window.draw(bkgSprite);

    // Dibuja enemigos
    for (auto &e : enemies) {
        window.draw(e.getSprite());
    }
}

void Level::update() {
    for (auto &e : enemies) {
        e.update();
    }
}

void Level::spawnEnemies() {
    
}
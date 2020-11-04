//
// Created by Agus on 14/9/2020.
//

#include "Level.h"

Level::Level() {
    setInitialValues();
    setDmgMultiplier(3);

    levelFinished = false;
}

// Seccion valores inicialesaaa
void Level::setInitialValues() {
    int scale = 1;
    setBackground("../assets/FondoCompleto1.png");
    setBackgroundScale(scale);

    totalEnemies = 20;

    int totalGoblins = 8;
    int totalMushrooms = 6;
    int totalFlyingEye = 6;

    for (int i = 0; i < totalGoblins; i++) {
        enemies.emplace_back("../assets/enemies/Goblin/goblinSheet.png", Vector2f(250 + 110 * i, 550));
    }

    for (int i = 0; i < totalMushrooms; i++) {
        enemies.emplace_back("../assets/enemies/Mushroom/mushroomSheet.png", Vector2f(250 + 110 * i, 410));
    }

    for (int i = 0; i < totalFlyingEye; i++) {
        enemies.emplace_back("../assets/enemies/Flying Eye/flyingEyeSheet.png", Vector2f(250 + 110 * i, 270));
    }

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
        window.draw(e.getEnemyHitbox());
    }
}

void Level::update() {
    for (auto &e : enemies) {
        e.update();
    }
}

void Level::spawnEnemies() {
    
}
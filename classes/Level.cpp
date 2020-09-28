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

    // Spawn de enemigos
    goblin.setPosition(1000, 575);
    mushroom.setPosition(700, 575);
    flyingEye.setPosition(850, 300);
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
    window.draw(bkgSprite);
    window.draw(goblin.getSprite());
    window.draw(goblin.getEnemyHitbox());

    window.draw(mushroom.getSprite());
    window.draw(mushroom.getEnemyHitbox());

    window.draw(flyingEye.getSprite());
    window.draw(flyingEye.getEnemyHitbox());
}

void Level::update() {
    goblin.update();
    mushroom.update();
    flyingEye.update();
}
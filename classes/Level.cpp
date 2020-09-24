//
// Created by Agus on 14/9/2020.
//

#include "Level.h"

Level::Level() {
    setInitialValues();
    setDmgMultiplier(3);

    levelFinished = false;
}

void Level::setBackground(String directory) {
    bkgTexture.loadFromFile(directory);
    bkgSprite.setTexture(bkgTexture);
}

void Level::setDmgMultiplier(int dmgMultiplier) {
    this->dmgMultiplier = dmgMultiplier;
}

void Level::endLevel() {
    levelFinished = true;
}

void Level::draw(RenderWindow &window) {
    window.draw(drawMap());
    window.draw(enemy.getSprite());
    window.draw(enemy.getEnemyHitbox());
}

void Level::update() {
    enemy.update();
}

Sprite Level::drawMap() {
    return bkgSprite;
}

void Level::setBackgroundScale(float scaleFactor) {
    bkgSprite.scale(scaleFactor, scaleFactor);
}

// Seccion enemigo

void Level::setEnemyTexture(String directory) {
    enemy.setTexture(directory);
}

void Level::setEnemyPosition(float x, float y) {
    enemy.setPosition(x, y);
}

void Level::setInitialValues() {
    setBackground("../assets/background2.jpg");
    setBackgroundScale(0.7f);

    // Spawn de enemigos
    enemy.setTexture("../assets/enemies/Goblin/Idle.png");
    enemy.setPosition(1000, 575);
}
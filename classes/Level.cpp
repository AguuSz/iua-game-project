//
// Created by Agus on 14/9/2020.
//

#include "Level.h"
#include <fstream>
#include <iostream>

Level::Level() {
    setInitialValues();
    setDmgMultiplier(3);
    instance = 1;
    levelFinished = false;

    int tmp;

    std::ifstream lectura;
    lectura.open("../assets/Mapa.txt");


    tileMapTexture.loadFromFile("../assets/AssetsPiso1.png");

    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 476; i++) {
            lectura >> tmp;
            int fil, col;
            col = tmp % 3;
            fil = tmp / 3;

            tileMapSprite[i][j].setTexture(tileMapTexture);
            tileMapSprite[i][j].setTextureRect({col * 20, fil * 20, 20, 20});
            tileMapSprite[i][j].setPosition(i * 20, (j * 20)+746);
        }
    }
    lectura.close();
}


// Seccion valores iniciales
void Level::setInitialValues() {
    int scale = 1;
    setBackground("../assets/FondoCompleto1.png");
    setBackgroundScale(scale);
    spawnEnemies();
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
    for (int i = 0; i < 476; i++) {
        for (int j = 0; j < 8; ++j) {
            window.draw(tileMapSprite[i][j]);
        }
    }

    // Dibuja enemigos
    for (auto &e : enemies) {
        window.draw(e.getSprite());
        window.draw(e.getEnemyHitbox());
    }

    window.draw(boss.getSprite());
}

void Level::update() {
    // Actualizan los enemigos
    for (auto &e : enemies) {
        e.update();
        e.setEnemyLookingRight(true);
    }
    boss.update();
}

void Level::spawnEnemies() {
    int totalGoblins = 8;
    int totalMushrooms = 6;
    int totalFlyingEye = 20;

//    for (int i = 0; i < totalGoblins; i++) {
//        enemies.emplace_back("../assets/enemies/Goblin/goblinSheet.png", Vector2f(250 + 110 * i, 550));
//    }
//
//    for (int i = 0; i < totalMushrooms; i++) {
//        enemies.emplace_back("../assets/enemies/Mushroom/mushroomSheet.png", Vector2f(250 + 110 * i, 410));
//    }

    for (int i = 0; i < totalFlyingEye; i++) {
        enemies.emplace_back("../assets/enemies/Flying Eye/flyingEyeSheet.png", Vector2f(250 + 110 * i, 270));
    }
    for(auto &e : enemies) {
        e.setEnemyLookingRight(true);
        e.setScaleFactor(2);
    }
}

void Level::setInstance(int instance) {
    Level::instance = instance;
}

int Level::getInstance(){
    return instance;
}

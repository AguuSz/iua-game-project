//
// Created by Agus on 14/9/2020.
//

#include "Level.h"
#include <fstream>
#include <iostream>
#include <time.h>

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
    setBackground("../assets/FondoCompleto1.png");
    setBackgroundScale(1);
    spawnEnemies(3, 2, 1);
    spawnBoss = false;
    // Inserta la instancia 1
    newInstanceAllowed = false;
    instances.push(1);
    srand(time(NULL));
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
//        window.draw(e.getEnemyHitbox());
        for (auto &enemyBullet : e.enemyBullets) {
            window.draw(enemyBullet.sprite);
        }
    }

    if (!boss->isBossDead() && spawnBoss)
        window.draw(boss->getSprite());
}

void Level::update(Player &player) {

    // Actualizan los enemigos
    for (auto e = enemies.begin(); e != enemies.end();) {

        e->update(player);

        if (!e->ignorePlayerPosition) {
            // Si no esta ignorando la posicion del jugador, el enemigo mirara hacia el jugador
            if (player.getPosition().x < e->getPosition().x) {
                // Player a la izquierda del enemigo
                e->setEnemyLookingRight(false);
            } else {
                // Player a la derecha del enemigo
                e->setEnemyLookingRight(true);
            }
        }

        if (e->isDead) {
            enemies.erase(e);
            break;
        } else {
            ++e;
        }
    }

    if (enemies.empty() && !newInstanceAllowed) {
        // Mataron a todos los enemigos, por lo que pasamos de instancia
        instances.push(instances.back() + 1);
        newInstanceAllowed = true;
    }

    if (instance == instances.back() && newInstanceAllowed) {
        // Significa que ya entro a otra instancia
        spawnEnemies(2, 2, 3);
        newInstanceAllowed = false;
    }

    if (spawnBoss && !boss->isBossDead()) {
        if (player.getPosition().x < boss->getPosition().x) {
            boss->setBossLookingRight(true);
        } else {
            boss->setBossLookingRight(false);
        }

        boss->update(player);
    }
}

void Level::spawnEnemies(int goblins, int mushrooms, int flyingEyes) {
    int totalGoblins = goblins;
    int totalMushrooms = mushrooms;
    int totalFlyingEye = flyingEyes;

    int x;

    for (int i = 0; i < totalGoblins; i++) {
        x = 1360 * (instance - 1) + rand() % 700;
        enemies.emplace_back("../assets/enemies/Goblin/goblinSheet.png", Vector2f(x - 200 * i, 1450), false);
    }

    for (int i = 0; i < totalMushrooms; i++) {
        x = 1360 * (instance - 1) + rand() % 700;
        enemies.emplace_back("../assets/enemies/Mushroom/mushroomSheet.png", Vector2f(x - 200 * i, 1450), false);
    }

    for (int i = 0; i < totalFlyingEye; i++) {
        x = 1360 * (instance - 1) + rand() % 700;
        enemies.emplace_back("../assets/enemies/Flying Eye/flyingEyeSheet.png", Vector2f(x - 300 * i, 200), true);
    }

    for(auto &e : enemies) {
        e.setScaleFactor(2);
    }
}

void Level::setInstance(int instance) {
    this->instance = instance;
}

int Level::getInstance(){
    return instance;
}

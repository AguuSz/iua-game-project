//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"
using namespace sf;

void Engine::update() {

    if (level.boss->isDead && !playWinningMusic) {
        playWinningMusic = true;
        if (!winningMusic.openFromFile("../assets/sounds/winningMusic.ogg")) {
            std::cout << "ERROR::WINNING_MUSIC no se ha podido cargar el archivo";
        }
        bossMusic.stop();
        winningMusic.setVolume(10);
        winningMusic.setLoop(false);
        winningMusic.play();
    }

    if(!player.didPlayerDie) {
        player.update();
        level.update(player);
    }
    updateMousePosition();
    mouseHitbox.setPosition(worldPos.x - 25, worldPos.y - 20);

    // Vectors
    aimDir = worldPos - player.getMiddlePoint();
    aimDirNormalized = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].sprite.move(bullets[i].currVelocity);
    }

    for (size_t i = 0; i < level.boss->bossBullets.size(); i++) {
        level.boss->bossBullets[i].sprite.move(level.boss->bossBullets[i].currVelocity);
    }

    for (auto &enemy : level.enemies) {
        for (auto & enemyBullet : enemy.enemyBullets) {
            enemyBullet.sprite.move(enemyBullet.currVelocity);
        }
    }

    if (level.getInstance() == 6 && level.doPlayBossMusic()) {
        // Llego a la instancia donde spawnea el boss
        if (!bossMusic.openFromFile("../assets/sounds/bossMusic.ogg")) {
            std::cout << "ERROR::BOSS_MUSIC no se ha podido cargar el archivo";
        }
        backgroundMusic.stop();
        bossMusic.setVolume(5);
        bossMusic.setLoop(true);
        bossMusic.play();
        level.setPlayBossMusic(false);
    }
}

void Engine::updateMousePosition() {
    pixelPos = Mouse::getPosition(window);
    worldPos = window.mapPixelToCoords(pixelPos);

    if (!player.ignoreMouseDirection) {
        if (pixelPos.x > window.getSize().x / 2) {
            player.setPlayerLookingRight(true);
        } else {
            player.setPlayerLookingRight(false);
        }
    }

    mouseSprite.setPosition(worldPos.x - 25, worldPos.y - 20);
}
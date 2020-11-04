//
// Created by Agus on 28/8/2020.
//
#include "Engine.h"
using namespace sf;

void Engine::update() {
    player.update();
    level.update();
    updateMousePosition();
    mouseHitbox.setPosition(worldPos.x - 25, worldPos.y - 20);

    // Vectors
    aimDir = worldPos - player.getMiddlePoint();
    aimDirNormalized = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].sprite.move(bullets[i].currVelocity);

        // Eliminando las que estan out of frame
        if (bullets[i].sprite.getPosition().x < 0 || bullets[i].sprite.getPosition().x  > window.getSize().x
            || bullets[i].sprite.getPosition().y < 0 || bullets[i].sprite.getPosition().y > window.getSize().y) {
            bullets.erase(bullets.begin() + i);
        }
    }

//    for (auto &b : bullets) {
//        b.sprite.move(b.currVelocity);
//
//        // Eliminamos las que esten out of frame
//        if (b.sprite.getPosition().x < 0 ||
//            b.sprite.getPosition().x > window.getSize().x ||
//            b.sprite.getPosition().y < 0 ||
//            b.sprite.getPosition().y > window.getSize().y ) {
//            bullets.remove(b);
//        }
//    }
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
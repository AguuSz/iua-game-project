//
// Created by Agus on 15/11/2020.
//

#ifndef IUAPROJECT_HEARTH_H
#define IUAPROJECT_HEARTH_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Hearth {
private:
    Sprite sprite;
    Texture texture;
    IntRect currentFrame;

    int hp;

public:

    Hearth();

    int getCurrentHP();
    bool isVisible();

    Sprite getSprite();
};


#endif //IUAPROJECT_HEARTH_H

#ifndef IUAPROJECT_HEART_H
#define IUAPROJECT_HEART_H

#include <SFML/Graphics.hpp>
#include <stack>

using namespace sf;

class Heart {
private:
    Sprite sprite;
    Texture texture;
    IntRect currentFrame;

    int hp;

public:

    Heart();

    int getCurrentHP();
    bool isVisible();

    Sprite getSprite();

    void generarPila();
};


#endif //IUAPROJECT_HEART_H

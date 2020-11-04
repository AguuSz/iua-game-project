//
// Created by Gaston on 17/9/2020.
//

#ifndef IUAPROJECT_MAPA_H
#define IUAPROJECT_MAPA_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Mapa {
private:
    Sprite sprite[475][75];
    Texture tex_mapa;
public:
    Mapa(char archivo[]);
    Sprite getSprite();

};


#endif //IUAPROJECT_MAPA_H

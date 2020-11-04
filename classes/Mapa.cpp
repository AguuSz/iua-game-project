#include "Mapa.h"
#include <fstream>

using namespace std;

Mapa::Mapa(char archivo[]) {
    string vectorMapa;
    int tmp;

    ifstream lectura;
    lectura.open(archivo);

    lectura >> vectorMapa;

    tex_mapa.loadFromFile(vectorMapa);

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 10; i++) {
            lectura >> tmp;
            int fil, col;
            col = tmp % 3;
            fil = tmp / 3;

            sprite[i][j].setTexture(tex_mapa);
            sprite[i][j].setTextureRect({col * 20, fil * 20, 20, 20});
            sprite[i][j].setPosition(i * 20, j * 20);
        }
    }
    lectura.close();
}

/*void Mapa::dibujar(RenderWindow &window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; ++j) {
            window.draw(sprite[i][j]);
        }
    }
}*/
Sprite Mapa::getSprite() {
    return sprite;
}
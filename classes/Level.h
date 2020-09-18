//
// Created by Agus on 14/9/2020.
//
#include "Enemy.h"
#include "Jefe.h"

class Level {
private:
    // Jefe boss
    Enemy enemy = {"Sangu", 50};

    // Fondo
//    Mapa mapa; Fdlta crear la clase, pero por ahora utilizaremos un fondo estatico
    Sprite bkgSprite;
    Texture bkgTexture;

    bool levelFinished;

    // El multiplicador de dano que va a tener cada nivel
    float dmgMultiplier;

    // Item item;

public:
    // Constructor
    Level();

    void draw(RenderWindow &window);

    void setBackground(String directory);
    void setDmgMultiplier(int dmgMultiplier);
    void endLevel();

    Sprite drawMap();

    void setEnemyTexture(String directory);
    void setEnemyPosition(float x, float y);
    void setBackgroundScale(float scaleFactor);

};
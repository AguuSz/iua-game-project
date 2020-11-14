//
// Created by Agus on 14/9/2020.
//
#include "Enemy.h"
#include <list>
#include "Boss.h"
#include "Player.h"

class Level {
private:
    Sprite tileMapSprite[476][8];
    Texture tileMapTexture;
    Sprite bkgSprite;
    Texture bkgTexture;
    int instance;

    bool levelFinished;

    // El multiplicador de dano que va a tener cada nivel
    float dmgMultiplier;

    // Item item;

public:
    // Seccion enemigos
    std::list<Enemy> enemies;
    Boss boss;

    // Constructor
    Level();

    //Instancia define la parte del nivel en la que estamos

    void setInstance(int instance);
    int getInstance();

    /// Funciones para el motor
    void draw(RenderWindow &window);
    void update(Player &player);

    void setBackground(String directory);
    void setDmgMultiplier(float dmgMultiplier);
    void endLevel();


    // Funciones que luego eliminaremos ya que estaran interiorizadas
    void setBackgroundScale(float scaleFactor);

    void getEnemies();

    void setInitialValues();

    void spawnEnemies();
};
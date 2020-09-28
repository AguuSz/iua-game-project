//
// Created by Agus on 14/9/2020.
//
#include "Enemy.h"
#include "Jefe.h"
#include "Goblin.h"
#include "Mushroom.h"
#include "FlyingEye.h"

class Level {
private:
    // Jefe boss

    // Fondo
    // Mapa mapa; Fdlta crear la clase, pero por ahora utilizaremos un fondo estatico
    Sprite bkgSprite;
    Texture bkgTexture;

    bool levelFinished;

    // El multiplicador de dano que va a tener cada nivel
    float dmgMultiplier;

    // Item item;

public:
    // Seccion enemigos
    Mushroom mushroom;
    Goblin goblin;
    FlyingEye flyingEye;

    // Constructor
    Level();

    /// Funciones para el motor
    void draw(RenderWindow &window);
    void update();

    void setBackground(String directory);
    void setDmgMultiplier(float dmgMultiplier);
    void endLevel();


    // Funciones que luego eliminaremos ya que estaran interiorizadas
    void setBackgroundScale(float scaleFactor);

    void getEnemies();

    void setInitialValues();
};
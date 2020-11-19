//
// Created by Agus on 28/8/2020.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include "Bullet.h"
#include "Boss.h"
#include <vector>

using namespace sf;

class Engine {
private:
    // Ventana del juego
    RenderWindow window;

    // Estado de juego
    int gameState;
    // Vista del jugador
    View view;

    // Instancia del jugador
    Player player;

    // Nivel
    Level level;
    Music backgroundMusic;
    Music bossMusic;
    Music winningMusic;
    Boss boss;

    // Bala
    Bullet b1;
    std::vector<Bullet> bullets;
    float shootingDelay;
    Clock shootingTimer;
    Vector2f bossDir;
    Vector2f bossDirNormalized;

    // Mouse
    Vector2i pixelPos;
    Vector2f worldPos;
    RectangleShape mouseHitbox;
    Vector2f aimDir;
    Vector2f aimDirNormalized;
    Sprite mouseSprite;
    Texture mouseTexture;

    // Menu
    int index;
    int optionsMenuIndex;
    bool menuIsOpen;
    Texture mainMenuTexture;
    Texture menuTexture;
    Texture optionsMenuTexture;
    Sprite menuSprite;
    Sprite mainMenuSprite;
    Sprite optionsMenuSprite;

    RectangleShape selectedOption;

    void inputMenu(Event& event);
    void MoveUp();
    void MoveDown();
    void selectOption();
    void drawMenu();
    void menu();
    void mainMenu();
    void optionsMenu();


    // Funciones para el funcionamiento
    void input(Event& event);
    void updateMousePosition();
    void update();
    void checkForCollisions();
    bool isOutOfScreen(Rect<float> element, Window &screen, Level &level);
    void draw();
    void setMouseHitbox();
    void setMouseSprite();
    Sprite drawMouse();

public:
    Engine();


    // Inicia el juego llamando a todas las funciones privadas
    void start();

};

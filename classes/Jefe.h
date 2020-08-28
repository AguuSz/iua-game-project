#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;


//Habilidad especial de jefe
class Habilidad {

private: //privado

    Sprite sprite;

    Vector2f position;

    String nombre;

    Texture textura;

    float damage;

    float cooldown;

    float movementSpeed;

public:  //publico

    Habilidad();

    Sprite getSprite();

    void moveRight();

    void moveLeft();

    void moveDown();

    void moveUp();

    void stopRight();

    void stopLeft();

    void stopUp();

    void stopDown();
    //setters
    void setDamage(float damage){
        Habilidad::damage = damage;
    }

    void setCooldown(float cooldown){
        Habilidad::cooldown = cooldown;
    }

    void setMovementSpeed(float movementSpeed){
        Habilidad::movementSpeed = movementSpeed;
    }

    void setTextura(Texture textura){
        Habilidad::textura = textura;
    }

    void setNombre(String nombre){
        Habilidad::nombre = nombre;
    }
    //getters
    void getDamage(){
        return Habilidad::damage;
    }

    void getCooldown(){
        return Habilidad::cooldown;
    }

    void getMovementSpeed(){
        return Habilidad::movementSpeed;
    }

    Texture getTextura(){    //preguntar gordo
        return Habilidad::textura;
    }

    String getNombre(){
        return Habilidad::nombre;
    }


};


//Clase jefe
class Jefe {

private:

    Vector2f position;

    Sprite sprite;

    Habilidad habilidad;

    Texture textura;

    float vida;

    int damage;

    int damageMultiplier;

    float movementSpeed;

public:
    // Constructor
    Jefe();

    // Mandar el sprite a cualquier funcion que lo llame
    Sprite getSprite();

    Habilidad setHabilidad(Habilidad habilidad){
        Jefe::habilidad = habilidad;
    } //PREGUNTAR GORDO

    Habilidad getHabilidad(){
        return Jefe::habilidad;
    }

    // Mover a la izquierda
    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void stopUp();

    void stopDown();

    void stopLeft();

    void stopRight();

    void specialAttack() const;

    void setVida(float vida){
        Jefe::vida = vida;
    }

    void setDamage(float damage){
        Jefe::damage = damage;
    }

    void setDamageMultiplier(float damageMultiplier){
        Jefe::damageMultiplier = damageMultiplier;
    }

    void setMovementSpeed(float movementSpeed){
        Jefe::movementSpeed = movementSpeed;
    }

    void getVida(){
        return Jefe::vida;
    }

    void getDamage(){
        return Jefe::damage;
    }

    void getDamageMultiplier(){
        return Jefe::damageMultiplier;
    }

    void getMovementSpeed(){
        return Jefe::movementSpeed;
    }

    void update(float elapsedTime);

};

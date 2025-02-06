#include "enemyChaser.h"

Chaser::Chaser(int health, int damage, float speed, Vector2f pos) : Enemy(health, damage, speed, pos) 
{
    if (!textureWalk.loadFromFile("Assets/Flam/SeparateAnim/Walk.png")) {
        throw std::runtime_error("Erreur de chargement de la texture (chaser walk)");
    }
    if (!textureAttack.loadFromFile("Assets/Flam/SeparateAnim/Attack.png")) {
        throw std::runtime_error("Erreur de chargement de la texture (chaser attack)");
    }
    if (!textureDead.loadFromFile("Assets/Flam/SeparateAnim/Dead.png")) {
        throw std::runtime_error("Erreur de chargement de la texture (chaser dead)");
    }

    sprite.setTexture(textureWalk);
    sprite.setScale(Vector2f(3,3));
}

void Chaser::update(float deltaTime, Player& p)
{
    if (!isDead) 
    {
        movement(deltaTime, p);
        attack(deltaTime, p);
        stuntManager(deltaTime);
    }
    animationUpdate(deltaTime);
    
}

void Chaser::movement(float deltaTime, Player& p)
{
    Vector2f pPos = p.getPos();

    float angle = atan2(pPos.y - pos.y, pPos.x - pos.x);

    float dx = cos(angle) * speed * deltaTime;
    float dy = sin(angle) * speed * deltaTime;

    if (abs(dx) < abs(dy)) {
        if (dy > 0) { orientation = 180; }
        else { orientation = 0; }
    }
    else {
        if (dx > 0) { orientation = 270; }
        else { orientation = 90; }

    }
    if (canMove && sqrt((pPos.x - pos.x) * (pPos.x - pos.x) + (pPos.y - pos.y) * (pPos.y - pos.y)) < playerDetectionDistance)
    {
        setPos(Vector2f(pos.x + dx, pos.y + dy));
    }

    if (stuntTime > 0)
    {
        setPos(Vector2f(pos.x - dx*3, pos.y - dy*3));
    }
}








#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

#include "player.h"
#include "enemy.h"
#include <SFML/Graphics/View.hpp>

using namespace sf;
using namespace std;

Player::Player(int health, int dmg, float s, Vector2f p) : Entity(health, dmg, s, p) 
{
    if (!textureWalk.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Walk.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }
    if (!textureIdle.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Idle.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }
    if (!textureAttack.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Attack.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }

    sprite.setTexture(textureIdle);
    sprite.setScale(Vector2f(4, 4));
}

void Player::update(float deltaTime, vector<Enemy*> p)
{
    move(deltaTime);
    attack(deltaTime, p);
    animationUpdate(deltaTime);
}

void Player::animationUpdate(float deltaTime) 
{
    timer += deltaTime;

    if (Keyboard::isKeyPressed(Keyboard::Z) ||
        Keyboard::isKeyPressed(Keyboard::Q) ||
        Keyboard::isKeyPressed(Keyboard::S) ||
        Keyboard::isKeyPressed(Keyboard::D)) 
    { isMoving = true; }
    else { isMoving = false; }

    if (isMoving) { animState = "Walk"; }
    else { animState = "Idle"; }
    if (Mouse::isButtonPressed(Mouse::Left) && timeSinceLastAttack < attackDuration)
    {
        animState = "Attack";
        attackstate = true;
    }
    else
    {
        attackstate =false;
    }

    
    


    if (animState == "Idle")
    {
        frameCount = 1;
        sprite.setTexture(textureIdle);
    }
    else if (animState == "Walk")
    {
        frameCount = 4;
        sprite.setTexture(textureWalk);
    }
    else if (animState == "Attack")
    {
        frameCount = 1;
        sprite.setTexture(textureAttack);
    }

    if (animState != animStateBackup)
    {
        animStateBackup = animState;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, 0, frameWidth, frameHeight));
    }

    if (timer > frameDuration)
    {
        timer = 0;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, currentFrame * frameWidth, frameWidth, frameHeight));
    }
}

bool isGoingDiagonal()
{
    int count = 0;
    if (Keyboard::isKeyPressed(sf::Keyboard::Z)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::S)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::D)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::Q)) { count += 1; }

    return count == 2;
}

void Player::move(float deltaTime)
{
    if (canMove) {
        bool isDiagonal = isGoingDiagonal();
        float isDiagonalMultiplier = 1;

        if (isDiagonal)
        {
            isDiagonalMultiplier = 1 / sqrt(2);
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            setPos(Vector2f(getPos().x, getPos().y - getSpeed() * deltaTime * isDiagonalMultiplier));
            setOrientation(270);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            setPos(Vector2f(getPos().x, getPos().y + getSpeed() * deltaTime * isDiagonalMultiplier));
            setOrientation(90);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            setPos(Vector2f(getPos().x - getSpeed() * deltaTime * isDiagonalMultiplier, getPos().y));
            setOrientation(180);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            setPos(Vector2f(getPos().x + getSpeed() * deltaTime * isDiagonalMultiplier, getPos().y));
            setOrientation(0);
        }
    }
}


bool isInside(Vector2f edges[4], Vector2f posPoint) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        Vector2f a = edges[i];
        Vector2f b = edges[(i + 1) % 4];

        if ((a.y > posPoint.y) != (b.y > posPoint.y)) {
            float intersectX = a.x + (b.x - a.x) * (posPoint.y - a.y) / (b.y - a.y);

            if (posPoint.x < intersectX) {
                count++;
            }
        }
    }
    return count % 2 == 1;
}

void Player::attack(float deltaTime, vector<Enemy*> ennemy)
{
    timeSinceLastAttack += deltaTime;
    if (timeSinceLastAttack > attackDuration)
    {
        canMove = true;

        if (timeSinceLastAttack > attackDuration + attackDelay) {
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                timeSinceLastAttack = 0;
                canMove = false;

                float attackSize = 30;
                float radO = getOrientation() * (M_PI / 180);
                Vector2f pPos = getPos();
                Vector2f attackHitBox[4] =
                {
                    Vector2f(pPos.x + (sin(radO) * attackSize), pPos.y - (cos(radO) * attackSize)),
                    Vector2f(pPos.x - (sin(radO) * attackSize), pPos.y + (cos(radO) * attackSize)),
                    Vector2f((pPos.x + (cos(radO) * 100)) - (sin(radO) * attackSize), (pPos.y + (sin(radO) * 100)) + (cos(radO) * attackSize)),
                    Vector2f((pPos.x + (cos(radO) * 100)) + (sin(radO) * attackSize), (pPos.y + (sin(radO) * 100)) - (cos(radO) * attackSize))
                };

                for (auto e : ennemy)
                {
                    cout << e->getHealth() << endl;
                    if (isInside(attackHitBox, e->getPos()))
                    {
                        e->takeHit(getDamage());
                        e->giveStunt(100.f);
                    }
                }
            }
        }
    }
}

void Player::usePowerUp()
{
    if (!buff)
    {
        buff = true;
        buffstart = chrono::high_resolution_clock::now();
        setDamage(20);
        cout << "test";
    }
}

void Player::checkPowerup()
{
    if (buff)
    {
        sprite.setColor(Color::Blue);
        auto tempsActuel = chrono::high_resolution_clock::now();
        chrono::duration<float> deltaTemps = tempsActuel - buffstart;
        if (deltaTemps.count() >= 3.0f)
        {
            buff = false;
            setDamage(5);
            cout << "fin";
        }
    }
}

void Player::draw(RenderWindow& window, View& view)
{
    sprite.setPosition(getPos());
    view.setCenter(getPos());
    window.draw(sprite);
}

Sprite& Player::getSprite()
{
    return sprite;
}



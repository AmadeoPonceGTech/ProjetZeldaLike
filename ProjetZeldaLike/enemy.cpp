#include "enemy.h"


void Enemy::giveStunt(float time)
{
    canMove = false;
    stuntTime += time;
    sprite.setColor(Color::Red);
}

void Enemy::stuntManager(float deltaTime)
{
    if (stuntTime > 0)
    {
        stuntTime += -deltaTime;
    }
    else
    {
        stuntTime = 0;
        sprite.setColor(Color::White);

        if (timeSinceLastAttack > attackDuration) 
        {
            canMove = true;
        }
    }
}

void Enemy::takeHit(int damage)
{
    health += -damage;
}

void Enemy::draw(RenderWindow& window, View& view)
{
    sprite.setPosition(pos);
    window.draw(sprite);
}

void Enemy::animationUpdate(float deltaTime)
{
    if (health <= 0 && animState != "Dead")
    {
        animState = "Dead";
        frameCount = 1;
        sprite.setTexture(textureDead);
        sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(16, 16)));
        isDead = true;
        return;
    }

    if (animState == "Dead")
    {
        deadTime += deltaTime;
        sprite.setColor(Color(255, 255, 255, 255 - int(deadTime) / 10));
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

    timer += deltaTime;
    if (timer > frameDuration && stuntTime <= 0)
    {
        timer = 0;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, currentFrame * frameWidth, frameWidth, frameHeight));
    }
}

void Enemy::attack(float deltaTime, Player& p)
{
    timeSinceLastAttack += deltaTime;

    Vector2f pPos = p.getPos();
    if (timeSinceLastAttack > attackDuration) {
        if (stuntTime <= 0)
        {
            canMove = true;
        }

        animState = "Walk";

        isPlayerRed = false;
        if (abs(pPos.x - pos.x) + abs(pPos.y - pos.y) < 50)
        {
            p.setHealth(p.getHealth() - damage);
            isPlayerRed = true;
            p.getSprite().setColor(Color::Red);
            animState = "Attack";
            timeSinceLastAttack = 0;
            canMove = false;
        }
    }
}

Sprite& Enemy::getSprite()
{
    return sprite;
}
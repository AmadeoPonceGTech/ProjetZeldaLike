#include "enemyPatrol.h"

bool touch = false;


Patroler::Patroler(int health, int damage, float speed, Vector2f pos, int iD) : Enemy(health, damage, speed, pos)
{
	if (!textureWalk.loadFromFile("Assets/Flam/SeparateAnim/Walk.png")) {
		throw std::runtime_error("Erreur de chargement de la texture (Patroler)");
	}
	if (!textureAttack.loadFromFile("Assets/Flam/SeparateAnim/Attack.png")) {
		throw std::runtime_error("Erreur de chargement de la texture (Patroler)");
	}
	if (!textureDead.loadFromFile("Assets/Flam/SeparateAnim/Dead.png")) {
		throw std::runtime_error("Erreur de chargement de la texture (chaser dead)");
	}

	sprite.setTexture(textureWalk);
	sprite.setScale(Vector2f(3, 3));
	
	intDir = iD;
}

void Patroler::update(float deltaTime, Player& p)
{
	if (!isDead)
	{
		if (intDir == 0) {
			moveHor3s(deltaTime);
		}
		else
		{
			moveVer3s(deltaTime);
		}
		attack(deltaTime, p);
		stuntManager(deltaTime);
	}
	animationUpdate(deltaTime);
}

void Patroler::moveHor3s(float deltaTime)
{
	timeSinceLastDirectionChange += deltaTime;

	if (timeSinceLastDirectionChange >= 3000.0)
	{
		moveleft = !moveleft;
		timeSinceLastDirectionChange = 0;
	}

	if (moveleft)
	{
		pos.x -= 1.0f;
		orientation = 90;
	}
	else
	{
		pos.x += 1.0f;
		orientation = 180;
	}
}


void Patroler::moveVer3s(float deltaTime)
{
	timeSinceLastDirectionChange += deltaTime;

	if (timeSinceLastDirectionChange >= 3000.0)
	{
		moveup = !moveup;
		timeSinceLastDirectionChange = 0;
	}

	if (moveup)
	{
		pos.y -= 1.0f;
		orientation = 0;
	}
	else
	{
		pos.y += 1.0f;
		orientation = 270;
	}
}

void Patroler::hitColor()
{
	health += -damage;
	clockHit.restart();
	getHit = true;
}
Sprite& Patroler::getSprite()
{
	return sprite;
}





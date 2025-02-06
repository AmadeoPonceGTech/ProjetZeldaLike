#include "Entity.h"

using namespace sf;

Entity::Entity(int pv, int dmg,float s, Vector2f p)
{
	health = pv;
	damage = dmg;
	speed = s;
	pos = p;
}

void Entity::setPos(Vector2f p)
{
	pos = p;
}
Vector2f Entity::getPos()
{
	return pos;
}

void Entity::setSpeed(float s)
{
	speed = s;
}
float Entity::getSpeed()
{
	return speed;
}

void Entity::setOrientation(int o)
{
	orientation = o;
}
int Entity::getOrientation()
{
	return orientation;
}

void Entity::setDamage(int d)
{
	damage = d;
}
int Entity::getDamage()
{
	return damage;
}

void Entity::setHealth(int h)
{
	health = h;
}
int Entity::getHealth()
{
	return health;
}

//Sprite Entity::getSprite()
//{
//	return sprite;
//}

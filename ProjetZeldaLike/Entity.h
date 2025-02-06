#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity
{
protected:
	int health;
	int damage;
	Vector2f pos;
	Sprite sprite;
	float speed;
	int orientation = 180;

public:
	Entity(int health, int dmg, float s, Vector2f p);

	virtual void draw(RenderWindow& window, View& view) = 0;
	void setPos(Vector2f p);
	Vector2f getPos();
	void setSpeed(float s);
	float getSpeed();
	void setOrientation(int o);
	int getOrientation();
	void setDamage(int d);
	int getDamage();
	void setHealth(int h);
	int getHealth();
	//Sprite getSprite();
};
#pragma once
#include "enemy.h"
#include "player.h"
#include <chrono>
#include <iostream>

class Patroler : public Enemy
{
private:
	bool moveleft = true;
	bool moveup = true;
	chrono::steady_clock::time_point lastMove;
	float timeSinceLastDirectionChange = 0;
	int intDir;
public:


	Clock clockHit;	
	bool getHit = false;

	Patroler(int health, int damage, float s, Vector2f p, int iD);

	void moveHor3s(float deltaTime);
	void moveVer3s(float deltaTime);

	void update(float deltaTime, Player& p);

	Sprite& getSprite();
	void hitColor();
};
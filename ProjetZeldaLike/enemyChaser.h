#pragma once
#include "player.h"
#include "enemy.h"
#include "player.h"

class Chaser : public Enemy
{
public:
	int playerDetectionDistance = 300;

	Chaser(int health, int damage, float speed, Vector2f pos);
	void update(float deltaTime, Player& p) override;

	void movement(float deltaTime, Player& p);
	
};

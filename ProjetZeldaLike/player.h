#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics/View.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Entity.h"
#include "enemy.h"
//#include "Boss.h"

class Enemy;
class Boss;

class Player : public Entity
{
private:
	void move(float deltaTime);

	void attack(float deltaTime, vector<Enemy*> ennemy, Boss boss);
	void animationUpdate(float deltaTime);

	Texture weapon1;
	Sprite  weaponSprite;

	Texture textureWalk;
	Texture textureIdle;
	Texture textureAttack;
	Sprite  sprite;

	int frameHeight = 16;
	int frameWidth = 16;
	int frameCount = 4;
	int currentFrame = 0;
	float frameDuration = 100.0f;
	float timer = 0;



	string animState = "Idle";
	string animStateBackup = "Idle";
	bool isMoving = false;

	float attackDuration = 100.0f;
	float attackDelay = 500.0f;
	int attackRange = 140;
	float attackSize = 60;
	float timeSinceLastAttack = 0;
	bool canMove = true;

public:
	bool attackstate = false;

	Player(int health, int dmg, float s, Vector2f p);

	void draw(RenderWindow& window, View& view);

	bool buff = true;
	void usePowerUp();
	void update(float deltaTime, vector<Enemy*> p, Boss boss);

	Sprite& getSprite();
	Sprite& getweaponSprite();
	void setWeaponOrientation();

};
#pragma once
#include "Entity.h";
#include "player.h";

class Player;

class Enemy : public Entity
{
public:
	Texture textureWalk;
	Texture textureAttack;
	Texture textureDead;
	Sprite sprite;

	int frameHeight = 16;
	int frameWidth = 16;
	int frameCount = 4;
	int currentFrame = 0;
	float frameDuration = 100.0f;
	float timer = 0;

	string animState = "Walk";
	string animStateBackup = "";

	float attackDuration = 1000.0f;
	float timeSinceLastAttack = 0;
	bool canMove = true;
	bool isPlayerRed = false;

	float stuntTime = 0;

	bool isDead = false;
	float deadTime = 0;

	Enemy(int health, int damage, float speed, Vector2f pos) : Entity(health, damage, speed, pos) {}

	virtual void update(float deltaTime, Player& p) = 0;
	void attack(float deltaTime, Player& player_);
	void animationUpdate(float deltaTime);

	void draw(RenderWindow& game, View& view);
	
	void takeHit(int damage);

	void giveStunt(float time);
	void stuntManager(float deltaTime);
	
	Sprite& getSprite();


};
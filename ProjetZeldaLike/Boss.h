#pragma once
#include "player.h"
#include "bossBullet.h"

class Boss : Entity
{
public:

	Sprite bossSprite;

	Texture bossWalk;

	vector<BossBullet> bossBulletList;


	bool getHit = false;

	int bulletByAttack = 3;
	int bulletAlreadyShotInTheAttack = 0;

	float timeSinceLastBulletShot = 0;
	float timeBetweenBulletShots = 1000.f;
	float timeSinceLastAttack = 0;
	float timeBetweenAttacks = 5000.f;

	int bulletDamage = 10;
	float bulletSpeed = 0.4f;


	int frameHeight = 245;
	int frameWidth = 250;
	int frameCount = 2;
	int currentFrame = 0;
	float frameDuration = 100.0f;

	float speed = 0.1f;

	float timer = 0;

	Vector2f targetPosition;

	Vector2i bossRoomSize = Vector2i(500, 500);

	Boss(int h, int d, float s, Vector2f p);

	void animationUpdate(float deltaTime);
	void update(float deltaTime, Player& p);
	void attack1(float deltaTime, Player& p);
	void move(float deltaTime);

	void bulletUpdate(float deltaTime, Player& p);

	void draw(RenderWindow& window, View& view) override;
	Sprite& getSprite();
	void BossHit(int dmg);
};
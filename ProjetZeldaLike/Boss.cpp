#include "boss.h"
#include "cstdlib"
#define _USE_MATH_DEFINES
#include <math.h>


Clock clockHit;
bool touchBoss = false;

Boss::Boss(int h, int d, float s, Vector2f p) : Entity(h, d, s, p)
{
	try {
		if (!bossWalk.loadFromFile("Assets/Boss/BossAnimation/pinguin.png")) {
			throw std::runtime_error("Erreur de chargement de la texture (player walk)");
		}
	}
	catch (const exception& e) {
		cout << "Probleme detecte : " << e.what() << endl;
	}

	bossSprite.setTexture(bossWalk);
	bossSprite.setScale(Vector2f(0.5f, 0.5f));
}



void Boss::animationUpdate(float deltaTime)
{
	timer += deltaTime;


	if (bossSprite.getTexture() != &bossWalk) {
		if (!bossWalk.loadFromFile("Assets/Boss/BossAnimation/walk1.png")) {
			cout << "Erreur de chargement de la texture de marche" << endl;
		}
		bossSprite.setTexture(bossWalk);
	}


	if (timer > frameDuration) {
		timer = 0;
		currentFrame = (currentFrame + 1) % 2;
	}


	bossSprite.setTextureRect(IntRect(0, currentFrame * frameHeight, frameWidth, frameHeight));
}

void Boss::update(float deltaTime, Player& p)
{
	//timeSinceLastAttack += deltaTime;
	//if (timeSinceLastAttack > timeBetweenAttacks) 
	//{
	//	attack1(deltaTime, p);
	//}
	//Attaque tête chercheuses
	//Attaque rapide demi cercle
	//Un autre truc
	move(deltaTime);
	animationUpdate(deltaTime);
	bulletUpdate(deltaTime, p);
}

//void Boss::attack1(float deltaTime, Player& p)
//{
//	if (bulletAlreadyShotInTheAttack < bulletByAttack)
//	{
//		timeSinceLastBulletShot += deltaTime;
//		if (timeSinceLastBulletShot > timeBetweenBulletShots)
//		{
//			timeSinceLastBulletShot = 0;
//			bulletAlreadyShotInTheAttack += 1;
//
//			bossBulletList.push_back(BossBullet(bulletDamage, bulletSpeed, pos, (rand()%int(M_PI*200))/100));
//		}
//	}
//	else
//	{
//		bulletAlreadyShotInTheAttack = 0;
//		timeSinceLastAttack = 0;
//	}
//}

void Boss::move(float deltaTime)
{

	if (abs(pos.x - targetPosition.x) < 5 && abs(pos.y - targetPosition.y) < 5) {

		targetPosition = Vector2f(rand() % bossRoomSize.x, rand() % bossRoomSize.y);
	}


	float angle = atan2(targetPosition.y - pos.y, targetPosition.x - pos.x);


	pos = Vector2f(pos.x + cos(angle) * deltaTime * speed, pos.y + sin(angle) * deltaTime * speed);
	bossSprite.setPosition(pos);
}

void Boss::bulletUpdate(float deltaTime, Player& p)
{
	vector<BossBullet> tempBossBulletList;
	for (auto& b : bossBulletList)
	{
		b.update(deltaTime, p);
		if (!(b.time > 7000))
		{
			tempBossBulletList.push_back(b);
		}
	}
	bossBulletList = tempBossBulletList;
}

void Boss::draw(RenderWindow& window, View& view)
{
	window.draw(bossSprite);

	for (auto& b : bossBulletList)
	{
		b.draw(window, view);
	}
}

void Boss::BossHit(int dmg)
{
	health -= dmg;
}


Sprite& Boss::getSprite()
{
	return bossSprite;
}



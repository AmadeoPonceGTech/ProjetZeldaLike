#pragma once
#include "Entity.h"
#include "player.h"
#define _USE_MATH_DEFINES
#include <math.h>

class BossBullet : Entity
{
public:
	float realOrientation = 0;
	float time = 0;

	Sprite autoAimSprite;
	Texture autoAimTexture;

	BossBullet(int d, float s, Vector2f p,float o);

	void update(float deltaTime, Player& p);
	void draw(RenderWindow& window, View& view) override;
	Sprite& getSprite();
};
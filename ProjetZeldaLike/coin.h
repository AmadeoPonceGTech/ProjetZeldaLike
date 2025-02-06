#pragma once
#include "itemEntity.h"

class Coin : ItemEntity
{
public:
	Texture texture;
	Sprite sprite;

	int animationStep = 0;
	float timeSinceLastAnimationUpdate = 0;

	Coin(Vector2f p);

	void update(float deltaTime);

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};
#pragma once

#include "itemEntity.h"

class Potion : public ItemEntity
{
public:
	Potion(Vector2f pos);
	Sprite potions;
	Texture potTex;
	


	void update(float deltaTime, Player& player_);
	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};

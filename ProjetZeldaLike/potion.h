#pragma once

#include "itemEntity.h"

class Potion : public ItemEntity
{
public:
	Sprite potions;
	Texture potTex;
	Potion(Vector2f pos) : ItemEntity(pos) {
		if (!potTex.loadFromFile("assets/pp_vie.png")) {
			cout << "Erreur de chargement de la texture!" << endl;
		}
		potions.setPosition(pos);
		potions.setTexture(potTex);
		potions.setPosition(pos);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};

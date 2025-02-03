#pragma once

#include "itemEntity.h"

class PotionDMG : public ItemEntity
{
public:
	Sprite potDMG;
	Texture potDMGtext;
	PotionDMG(Vector2f pos) : ItemEntity(pos) {
		if (!potDMGtext.loadFromFile("assets/pp_dmg.png")) {
			cout << "Erreur de chargement de la texture!" << endl;
		}
		potDMG.setPosition(pos);
		potDMG.setTexture(potDMGtext);
		potDMG.setPosition(pos);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;


};

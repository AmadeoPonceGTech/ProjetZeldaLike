#pragma once

#include "itemEntity.h"

class PotionPOI : public ItemEntity
{
public:
	Sprite potPOI;
	Texture potPOItext;
	PotionPOI(Vector2f pos) : ItemEntity(pos) {
		if (!potPOItext.loadFromFile("assets/pp_degat.png")) {
			cout << "Erreur de chargement de la texture!" << endl;
		}
		potPOI.setPosition(pos);
		potPOI.setTexture(potPOItext);
		potPOI.setPosition(pos);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;


};

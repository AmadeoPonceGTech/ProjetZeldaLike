#include "potion.h"


Potion::Potion(Vector2f pos): ItemEntity(pos){
if (!potTex.loadFromFile("assets/vie.png")) {
	cout << "Erreur de chargement de la texture!" << endl;
}
potions.setPosition(pos);
potions.setTexture(potTex);
potions.setPosition(pos);
}
bool activePot = true;

void Potion::update(float deltaTime, Player& player_)
{
	itmget();
	itemEffect(player_);
}

void Potion::draw(RenderWindow& game)
{
	/*if (activePot)
	{*/
		game.draw(potions);
	/*}*/
}

void Potion::itmget()
{
	activePot = false;
}

void Potion::itemEffect(Player& player_)
{
	player_.setHealth(player_.getHealth() + 10);
}




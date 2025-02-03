#include "potion.h"

bool activePot = true;

void Potion::draw(RenderWindow& game)
{
	if (activePot)
	{
		game.draw(potions);
	}
}

void Potion::itmget()
{
	if (activePot)
	{
		activePot = false;
	}
}

void Potion::itemEffect(Player& player_) 
{
	FloatRect playerbounds = player_.getSprite().getGlobalBounds();
	FloatRect itembound = potions.getGlobalBounds();

	if (playerbounds.intersects(itembound) && activePot)
	{
		player_.setHealth(10);
		activePot = false;
	}
}




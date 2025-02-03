#include "potionPOI.h"


bool activePotSPD = true;

void PotionPOI::draw(RenderWindow& game)
{
	if (activePotSPD)
	{
		game.draw(potPOI);
	}
}

void PotionPOI::itmget()
{
	if (activePotSPD)
	{
		activePotSPD = false;
	}
}

void PotionPOI::itemEffect(Player& player_)
{
	FloatRect playerbounds = player_.getSprite().getGlobalBounds();
	FloatRect itembound = potPOI.getGlobalBounds();

	if (playerbounds.intersects(itembound) && activePotSPD)
	{
		player_.setHealth(player_.getHealth() - 5);
		activePotSPD = false;
		player_.setSpeed(10);
	}
}



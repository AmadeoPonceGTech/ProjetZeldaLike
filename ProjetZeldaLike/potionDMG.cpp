#include "potionDMG.h"


bool activePotDMG = true;

void PotionDMG::draw(RenderWindow& game)
{
	if (activePotDMG)
	{
		game.draw(potDMG);
	}
}

void PotionDMG::itmget()
{
	if (activePotDMG)
	{
		activePotDMG = false;
	}
}

void PotionDMG::itemEffect(Player& player_)
{
	FloatRect playerbounds = player_.getSprite().getGlobalBounds();
	FloatRect itembound = potDMG.getGlobalBounds();

	if (playerbounds.intersects(itembound) && activePotDMG)
	{
		player_.usePowerUp();
		player_.checkPowerup();
		activePotDMG = false;
	}
}



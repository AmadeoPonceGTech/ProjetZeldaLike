#include "potionDMG.h"


bool activePotDMG = true;




void PotionDMG::update(float deltaTime, Player& player_)
{
	itmget();
	itemEffect(player_);
}

void PotionDMG::draw(RenderWindow& game)
{
	if (activePotDMG)
	{
		game.draw(potDMG);
	}
}

void PotionDMG::itmget()
{
	activePotDMG = false;
}

void PotionDMG::itemEffect(Player& player_)
{
	FloatRect playerbounds = player_.getSprite().getGlobalBounds();
	FloatRect itembound = potDMG.getGlobalBounds();

	if (playerbounds.intersects(itembound) && activePotDMG == true)
	{
		activePotDMG = false;
		player_.usePowerUp();
	}
}



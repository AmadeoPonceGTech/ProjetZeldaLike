#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "titre.hpp"

using namespace std;
using namespace sf;

class GameOver : public Menu {
public:

	GameOver();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;

};

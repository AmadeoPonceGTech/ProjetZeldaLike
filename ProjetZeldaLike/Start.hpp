#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu.hpp"

using namespace std;
using namespace sf;

class Start : public Menu {
public:

	Start();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;
	


};

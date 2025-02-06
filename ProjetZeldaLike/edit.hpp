#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Start.hpp"

using namespace std;
using namespace sf;

class Edit : public Menu {
public:

	Edit();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;

};

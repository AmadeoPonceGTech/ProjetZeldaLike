#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "edit.hpp"

using namespace std;
using namespace sf;

class Option : public Menu {
public:

	Option();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;
};

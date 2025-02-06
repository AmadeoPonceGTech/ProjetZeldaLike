#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "option.hpp"

using namespace std;
using namespace sf;

class Back : public Menu {
public:

	Back();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;
};

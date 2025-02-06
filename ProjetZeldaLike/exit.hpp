#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "back.hpp"

using namespace std;
using namespace sf;

class Exit : public Menu {
public:
	Exit();

	FloatRect getBounds() const
	{
		return sprite.getGlobalBounds();
	}


	void draw(RenderWindow& window) override;
};

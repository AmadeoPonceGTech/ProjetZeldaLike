#include "option.hpp"

Option::Option() {
	texture.loadFromFile("Assets/Menu/Option.png");
	sprite.setTexture(texture);
	sprite.setPosition(1730, 650);

}


void Option::draw(RenderWindow& window) {
	window.draw(sprite);
}

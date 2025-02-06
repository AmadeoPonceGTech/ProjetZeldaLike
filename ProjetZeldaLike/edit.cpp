#include "edit.hpp"

Edit::Edit() {

	texture.loadFromFile("Assets/Menu/Edit.png");
	sprite.setTexture(texture);
	sprite.setPosition(800, 600);
}

void Edit::draw(RenderWindow& window) {
	window.draw(sprite);
}
